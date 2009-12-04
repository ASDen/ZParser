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

namespace ZInterp
{
	void Function :: Defination ( pANTLR3_BASE_TREE funNode , yatgFW_Ctx_struct *xyz )
	{
		ANTLR3_MARKER funend = ( ( pANTLR3_BASE_TREE ) funNode -> getChild ( funNode , 3 ) ) -> savedIndex ;
		pANTLR3_BASE_TREE t2 = ( pANTLR3_BASE_TREE ) funNode -> getChild ( funNode , 0 ) ;
		ZChar* fName = getNodeText ( ( pANTLR3_BASE_TREE ) t2 -> getChild ( t2 , 0 ) ) ;
		ZFunction* fun;
		fun = ZSym . getSymbol < ZFunction > ( fName , true ) ;
		if ( fun == NULL )
		{
			fun = ZAlloc ( ZFunction , 1 ) ;
			fun -> FunData . NodeID = ( funNode ) -> savedIndex ;
			fun -> FunT = ZInternal;
			fun -> NumArgs = ( ( pANTLR3_BASE_TREE ) funNode -> getChild ( funNode , 1 ) ) -> children -> count;
			ZSym . currentScope -> FunTable . Insert ( fun , fName ) ;


		}
		SEEK ( funend ) ;
		MATCHT ( FUN_DEF_END , NULL ) ;
		//setCustomNodeField(funNode,fun);

		
	}
	void Operand::FunCall(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE arg,yatgFW_Ctx_struct* xyz)
	{
		
		pANTLR3_BASE_TREE t2=(pANTLR3_BASE_TREE)t1->getChild(t1,0);
		ZChar* vName = getNodeText(t2);
		ZFunction* var;
		var = ZSym.getSymbol<ZFunction>(vName,true);
		if ( var == NULL )
		{
			std::cout << "Function : " << vName << " Not defined" << std::endl ;
			return;
		}

		//collect arguments in a vector before calling
		ZTvarS Fargs;
		ZTvarp vp;
		for ( int i = 0 ; i < arg -> children -> count ; i ++ )
		{
			vp = ( ZTvarp ) ( ( pANTLR3_BASE_TREE ) arg -> getChild ( arg , i ) ) -> u;
			Fargs . push_back ( vp ) ;
		}
		pANTLR3_BASE_TREE t  ;
		switch ( var -> FunT )
		{
		case ZInternal :
		
			if( Helper :: Function :: ZTestArg ( var , Fargs ) ) 
			{
				SEEK ( var -> FunData . NodeID ) ;
				t = ( xyz -> expr_g ( xyz ) ) . start ;
				//cout<<"tree is\n"<<t->toStringTree(t)->chars<<endl;
				//cout<<"tree ARG is\n"<<t1->toStringTree(t1)->chars<<endl;
				ANTLR3_MARKER funend=((pANTLR3_BASE_TREE)t->getChild(t,3))->savedIndex;
				
				int i=0;
				
				pANTLR3_BASE_TREE argtree = ( pANTLR3_BASE_TREE ) t -> getChild ( t , 1 ) ;
				//pANTLR3_BASE_TREE body = ( pANTLR3_BASE_TREE ) t -> getChild ( t , 2 ) ;
				pANTLR3_BASE_TREE ty = ( pANTLR3_BASE_TREE ) argtree -> getChild ( argtree , 0 ) ;
				//pANTLR3_BASE_TREE ty1 = ( pANTLR3_BASE_TREE ) ty -> getChild ( ty , 0 ) ;
				//cout<<"node="<<getNodeText(ty)<<endl;
				SEEK ( ty -> savedIndex );
				//xyz -> expr_g ( xyz ) ;
				while(i < var -> NumArgs )
				{
					
					ZChar* name = getNodeText ( ( pANTLR3_BASE_TREE ) argtree -> getChild ( argtree , i ) ) ;
					//ZChar* var = getNodeText ( ( pANTLR3_BASE_TREE ) arg -> getChild ( arg , i  ) ) ;
					/*cout<<"ARGUMENT=";
					cout<<name;
					std::wcout<<"="<<boost::apply_visitor(ToString(),*((ZTvarp)Fargs[i]))<<std::endl;*/

					ZInterp :: ZSym . currentScope -> VarTable . Insert ( ( ZTvarp ) Fargs [ i ] , name ) ;
					i ++ ;
				}
				//MATCHT(ANTLR3_TOKEN_UP,NULL);
				//SEEK(funend);
				//MATCHT(ID_MORE,NULL);
				
			}
			else
			{
				cout<<"different number\n";
			}
			break;
		case ZExternal:
			ZInterp::setCustomNodeField(t1,(*(var->FunData.pFun))(Fargs));
			break;
		}

	}
}