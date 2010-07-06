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
	void IfExpr::Exec(pANTLR3_BASE_TREE ifnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz)
	{
		pANTLR3_BASE_TREE r;
		if(boost::apply_visitor(BoolVal(),*((ZTvarp)(cond->u)))== ZBTrue )
		{
			r=(pANTLR3_BASE_TREE)(ifnode->getChild(ifnode,1));
			SEEK(r->savedIndex);
			MATCHT(EIF_THEN,NULL);
			MATCHT(ANTLR3_TOKEN_DOWN,NULL);
			ZInterp::ifScope=true;
			r=(xyz->expr_g(xyz)).start;
			ZInterp::ifScope=false;
			ifnode->u=r->u;
			r=(pANTLR3_BASE_TREE)(ifnode->getChild(ifnode,3));
			SEEK(r->savedIndex);
			MATCHT(EIF_END,NULL);
		}
		
		else
		{
			r=(pANTLR3_BASE_TREE)(ifnode->getChild(ifnode,2));
			SEEK(r->savedIndex);
			MATCHT(EIF_ELSE,NULL);
			if(LA(1)==ANTLR3_TOKEN_DOWN)
			{
				MATCHT(ANTLR3_TOKEN_DOWN,NULL);
				ZInterp::ifScope=true;
				r=(xyz->expr_g(xyz)).start;
				ZInterp::ifScope=false;
				ifnode->u=r->u;
				MATCHT(ANTLR3_TOKEN_UP,NULL);
			}
			
			MATCHT(EIF_END,NULL);
		}
	}

	void WhileExpr::Exec(pANTLR3_BASE_TREE wnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz)
	{
		ANTLR3_MARKER Wcond=((pANTLR3_BASE_TREE)(wnode->getChild(wnode,0)))->savedIndex;
		ANTLR3_MARKER Wexpr=((pANTLR3_BASE_TREE)(wnode->getChild(wnode,1)))->savedIndex;
		ANTLR3_MARKER Wend =((pANTLR3_BASE_TREE)(wnode->getChild(wnode,2)))->savedIndex;
	
        ZInterp::lend.push_back(Wend);
        ZInterp::lCon.push_back(Wcond);
		while ( boost :: apply_visitor ( BoolVal ( ) , * ( ( ZTvarp ) ( cond -> u ) ) ) == ZBTrue )
		{
			SEEK(Wexpr);
			MATCHT(EWHILE_EXP,NULL);
			MATCHT(ANTLR3_TOKEN_DOWN,NULL);
			if ( ZInterp :: isContinue )
			{
				ZInterp :: isContinue= ZBFalse;
				continue ;
			}
			if(ZInterp::isExit)
            {
                ZInterp :: actual ++ ;
                if(ZInterp :: actual == ZInterp :: loopNum)
                {
                    ZInterp :: actual = 0 ;
                    ZInterp :: isExit = ZBFalse ;
                } 
                break ;
            }
			xyz->expr_g(xyz);
			SEEK(Wcond);
			MATCHT(EWHILE_CON,NULL);
			MATCHT(ANTLR3_TOKEN_DOWN,NULL);
			cond = (xyz->expr_g(xyz)).start;
			
		    
		}
		SEEK(Wend);
		MATCHT(EWHILE_END,NULL);
	}

	void ForExpr::Exec ( pANTLR3_BASE_TREE fnode , pANTLR3_BASE_TREE src , yatgFW_Ctx_struct* xyz )
	{
		ANTLR3_MARKER fexpr = ( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 2 ) ) ) -> savedIndex ;
		ANTLR3_MARKER fend = ( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 3 ) ) ) -> savedIndex ;
        ZInterp::lend.push_back(fend);
        ZInterp::lCon.push_back(fend);
		pANTLR3_BASE_TREE tsrc=( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 1 ) ) );
		pANTLR3_BASE_TREE tstart= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 0 ) ;
		pANTLR3_BASE_TREE tend= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 1 ) ;
		pANTLR3_BASE_TREE tby= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 2 ) ;
		pANTLR3_BASE_TREE twhere= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 3 ) ;

        ZIFloat start,end,scale=1;ZIBool cond=ZBTrue;ZTvarp v;ZTList* list=NULL;ZChar* arr;
		ZTFloat f;
		v = ZAlloc(ZTvar,1);
        if(tend==NULL)
        {
            //arr=getNodeText(((pANTLR3_BASE_TREE)(( pANTLR3_BASE_TREE ) tstart -> getChild ( tstart , 0 ))->getChild((( pANTLR3_BASE_TREE ) tstart -> getChild ( tstart , 0 )),0)));
            //ZTvarp var=ZInterp::ZSym.getSymbol(arr,true);
            list=( gLIST_ZCONV( *(ZTvarp)( ( ( pANTLR3_BASE_TREE ) tstart -> getChild ( tstart , 0 ) ) ->u) )).cont;
            start=0;
            end=list->val.size();
            
		    //f.val=atof(boost::apply_visitor(ToString(),*(list->val[0])));
		    //v = ZAlloc(ZTvar , 1);
		    *v=*(list->val[0]);
        }
        else
        {
			start= gFLOAT_ZCONV(*(ZTvarp)((( pANTLR3_BASE_TREE ) tstart -> getChild ( tstart , 0 ))->u)).cont->val;
            end=gFLOAT_ZCONV(*(ZTvarp)((( pANTLR3_BASE_TREE ) tend -> getChild ( tend , 0 ))->u)).cont->val;
            scale=( tby != NULL ) ? gFLOAT_ZCONV(*(ZTvarp)((( pANTLR3_BASE_TREE ) tby -> getChild ( tby , 0 ))->u)).cont->val : 1.0;
            cond= (twhere!=NULL)  ? gBOOL_ZCONV(*(ZTvarp)((( pANTLR3_BASE_TREE ) twhere -> getChild ( twhere , 0 ))->u)).cont->val ==  ZBTrue : ZBTrue;
    		
		    //f.val=start;
		    
			*v =ZTFloat(start);
        }
		ZChar* id=getNodeText((pANTLR3_BASE_TREE)fnode->getChild(fnode,0));
	    ZInterp::ZSym.currentScope->VarTable.Insert(v,id);
		bool direct = ( start < end ) ? true : false ;
		for ( ; direct?  start <=end : start >= end && cond ; start += scale )
		{
            if(list==NULL)            {
                //f.val+=scale;
                //*v =(ZTvar)f;
				//*v=boost::apply_visitor(Sum(),*v,ZTvar(ZTFloat(start)));
				*v =ZTFloat(start);
            }
            else
            {
                if(start+1>end)
                    break;
               // f.val=atof(boost::apply_visitor(ToString(),*(list->val[start])));
				*v=*(list->val[start]);
            }
			if(ZInterp :: isContinue)
            {
				ZInterp :: isContinue=ZBFalse;
                continue ;

            }
		    if(ZInterp::isExit)
            {
                ZInterp::actual++;
                if(ZInterp::actual==ZInterp::loopNum)
                {
                    ZInterp::actual=0;
                    ZInterp::isExit = ZBFalse ;
                }
                break ;
            }
			SEEK ( fexpr ) ;
			MATCHT ( EFOR_EXP , NULL ) ;
			MATCHT ( ANTLR3_TOKEN_DOWN , NULL ) ;
			xyz -> expr_g ( xyz ) ;
		}
		SEEK ( fend ) ;
		MATCHT ( EFOR_END , NULL ) ;
	}

	void DoExpr::Exec ( pANTLR3_BASE_TREE dnode , pANTLR3_BASE_TREE cond , yatgFW_Ctx_struct* xyz )
	{
		ANTLR3_MARKER dexpr=(((pANTLR3_BASE_TREE)dnode->getChild(dnode,1))->savedIndex);
		ANTLR3_MARKER dcond=(((pANTLR3_BASE_TREE)dnode->getChild(dnode,0))->savedIndex);
		ANTLR3_MARKER dend=(((pANTLR3_BASE_TREE)dnode->getChild(dnode,2))->savedIndex);
		
		do
		{
			SEEK ( dexpr ) ;
			MATCHT ( EDO_EXP , NULL ) ;
			MATCHT ( ANTLR3_TOKEN_DOWN , NULL ) ;
			xyz -> expr_g ( xyz ) ;
			SEEK ( dcond ) ;
			MATCHT ( EDO_CON , NULL ) ;
			MATCHT ( ANTLR3_TOKEN_DOWN , NULL ) ;
			cond = ( xyz -> expr_g ( xyz ) ) . start ;
		}

		while(boost :: apply_visitor ( BoolVal ( ) , * ( ( ZTvarp ) ( cond -> u ) ) ) ==  ZBTrue );
		SEEK(dend);
		MATCHT(EDO_END,NULL);
	}

	void ContextExpr::Exec(pANTLR3_BASE_TREE timeNode,yatgFW_Ctx_struct* )
	{
		currentFrame = (int)gFLOAT_ZCONV(*(ZTvarp)((( pANTLR3_BASE_TREE ) timeNode -> getChild ( timeNode , 2 ))->u)).cont->val;
	}


	void ContextExpr::Flush()
	{
		currentFrame = 0;
	}

	void CaseExpr::Exec(pANTLR3_BASE_TREE caseNode, yatgFW_Ctx_struct * xyz)
	{
		int cnt = ((caseNode))->children->count;
		ANTLR3_MARKER cend = (((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,cnt-1))->savedIndex);

		pANTLR3_BASE_TREE t = (pANTLR3_BASE_TREE)((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,0));
		pANTLR3_BASE_TREE p=(pANTLR3_BASE_TREE)t->getChild(t,0);
		ZChar* var = getNodeText((pANTLR3_BASE_TREE)p->getChild(p,0));
        ZTvarp x= ZInterp::ZSym.getSymbol(var,ZBTrue);
		int c=1;
		//while((pANTLR3_BASE_TREE)(caseNode)->getChild(caseNode,c)!=NULL)
		for(int j=0;j<cnt-2;j++)
		{
			ANTLR3_MARKER item=(((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,c))->savedIndex);
			
			SEEK(item);
			MATCHT(CASE_Item,NULL);
			MATCHT ( ANTLR3_TOKEN_DOWN , NULL ) ;
			pANTLR3_BASE_TREE cur=((pANTLR3_BASE_TREE)((pANTLR3_BASE_TREE)(caseNode)->getChild(caseNode,c))->getChild((pANTLR3_BASE_TREE)(caseNode)->getChild(caseNode,c),0));
			char* curStr=getNodeText(cur);
			if(strcmp(curStr,"DEFAULT")==0)
			{
				pANTLR3_BASE_TREE tt = ( pANTLR3_BASE_TREE ) caseNode -> getChild ( caseNode , c ) ;
				pANTLR3_BASE_TREE tt1 = ( pANTLR3_BASE_TREE ) tt -> getChild ( tt , 1 ) ;
				SEEK (  tt1-> savedIndex);
				caseScope=true;
				xyz -> expr_g ( xyz );
				caseScope=false;
				break;
			}
			else
			{
				xyz->expr_g(xyz);
				ZTvarp y = ((ZTvarp)cur->u);
				string str=boost::apply_visitor(ToString(),*y);
				ZTvarp var=ZAlloc(ZTvar,1);
				*var = boost::apply_visitor(Boolean::Equal(),*x,*y);
				string str1=boost::apply_visitor(ToString(),*var);
				
				if(BOOL_ZCONV(*var))
				{
					pANTLR3_BASE_TREE tt = ( pANTLR3_BASE_TREE ) caseNode -> getChild ( caseNode , c ) ;
					pANTLR3_BASE_TREE tt1 = ( pANTLR3_BASE_TREE ) tt -> getChild ( tt , 1 ) ;
					SEEK (  tt1-> savedIndex);
					caseScope=true;
					xyz -> expr_g ( xyz );
					caseScope=false;
					//MATCHT ( ANTLR3_TOKEN_UP , NULL ) ;
					break;
				}
				//MATCHT ( ANTLR3_TOKEN_UP , NULL ) ;
				
			}
			c ++ ;
		}
		SEEK(cend);
		//MATCHT(ANTLR3_TOKEN_UP,NULL);
		MATCHT(ECASE_END,NULL);
	}

};