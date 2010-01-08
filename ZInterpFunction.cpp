#include "stdafx.h"
#include "ZInterp.h"
#include "Helper.h"

#define	    PARSER							xyz->pTreeParser  
#define	    RECOGNIZER						PARSER->rec
#define	    INPUT							PARSER->ctnstream
#define		ISTREAM							INPUT->tnstream->istream
#define	    MATCHT(t, fs)					RECOGNIZER->match(RECOGNIZER, t, fs)
#define	    MATCHANYT()						RECOGNIZER->matchAny(RECOGNIZER)
#define	    CONSUME()						ISTREAM->consume(ISTREAM)
#define	    LA(n)							ISTREAM->_LA(ISTREAM, n)
#define	    LT(n)							INPUT->tnstream->_LT(INPUT->tnstream, n)
#define		SEEK(n)							ISTREAM->seek(ISTREAM, n)
#define	    MARK()							ISTREAM->mark(ISTREAM)
#define	    REWIND(m)						ISTREAM->rewind(ISTREAM, m)
#define	    REWINDLAST()					ISTREAM->rewindLast(ISTREAM)

namespace ZInterp
{
	void Function :: Defination ( pANTLR3_BASE_TREE funNode , yatgFW_Ctx_struct *xyz )
	{
		ANTLR3_MARKER funend = ( ( pANTLR3_BASE_TREE ) funNode -> getChild ( funNode , 3 ) ) -> savedIndex ;
		pANTLR3_BASE_TREE t2 = ( pANTLR3_BASE_TREE ) funNode -> getChild ( funNode , 0 ) ;
		ZChar* fName = getNodeText ( ( pANTLR3_BASE_TREE ) t2 -> getChild ( t2 , 0 ) ) ;
		ZTvarp fun;
		fun = ZSym . getSymbol ( fName , true ) ;
		if ( fun == NULL )
		{
			fun = ZAlloc(ZTvar,1);
			ZIFunction* ifun=ZAlloc(ZIFunction,1);
			ifun -> FunData . NodeID = ( funNode ) -> savedIndex ;
			ifun -> FunT = ZInternal;
			ifun -> NumArgs = ( ( pANTLR3_BASE_TREE ) funNode -> getChild ( funNode , 1 ) ) -> children -> count;
			*fun=ZTFunction(ifun);
			ZSym.InsertSymbol ( fName , fun );
		}
		SEEK ( funend ) ;
		MATCHT ( FUN_DEF_END , NULL ) ;
		setCustomNodeField(funNode,fun);
		
	}
	void Operand::FunCall(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE arg,yatgFW_Ctx_struct* xyz)
	{
		pANTLR3_BASE_TREE t2=(pANTLR3_BASE_TREE)t1->getChild(t1,0);
		ZChar* vName = getNodeText(t2);
		ZTvarp fun;
		fun = ZSym.getSymbol(vName,true);
		if ( fun == NULL )
		{
			/* Fire an Exception */
			std::cout << "Function : " << vName << " Not defined" << std::endl ;
			return;
		}

		//Collect arguments in a vector before calling
		ZTvarS Fargs;
		ZTvarp vp;
		if(arg->children!=NULL)
		for ( int i = 0 ; i < arg -> children -> count ; i ++ )
		{
			vp=ZAlloc(ZTvar,1);
			*vp = *((ZTvarp)((pANTLR3_BASE_TREE)arg->getChild(arg,i))->u);
			Fargs . push_back ( vp ) ;
		}

		pANTLR3_BASE_TREE t  ;
		ZIFunction* var=boost::get<gZFunction>(*fun).cont->val;
		
		switch ( var -> FunT )
		{
		case ZInternal :
		
			if( Helper :: Function :: ZTestArg ( var , Fargs ) ) 
			{
				ANTLR3_MARKER Mst=MARK();

				SEEK ( var -> FunData . NodeID ) ;
				pANTLR3_BASE_TREE fun =LT(1);
				pANTLR3_BASE_TREE argtree = ( pANTLR3_BASE_TREE ) fun -> getChild ( fun , 1 ) ;
				pANTLR3_BASE_TREE body = ( pANTLR3_BASE_TREE ) fun -> getChild ( fun , 2 ) ;
				
				int i=0;
				ZInterp::ZSym.InitScope();
				while(i < var -> NumArgs )
				{			
					ZChar* name = getNodeText ( ( pANTLR3_BASE_TREE ) argtree -> getChild ( argtree , i ) ) ;
					ZInterp :: ZSym . currentScope -> VarTable . Insert ( ( ZTvarp ) Fargs [ i ] , name ) ;
					i++;
				}
				SEEK ( body -> savedIndex );
				MATCHT(BODY,NULL);
				MATCHT(ANTLR3_TOKEN_DOWN,NULL);

				ZTvarp ret=ZAlloc(ZTvar,1);
				ret=(ZTvarp)((xyz -> expr_g ( xyz )).start->u) ;
				ZInterp::setCustomNodeField(t1,ret);

				ZInterp::ZSym.FinScope();
				REWIND(Mst);
			}
			else
			{
				/* Fire an Exception */
				std::cout<<"Insufficient Numer of Arguments"<<std::endl;
			}
			break;
		case ZExternal:
			ZInterp::setCustomNodeField(t1,(*(var->FunData.pFun))(Fargs));
			break;
		}

	}
}