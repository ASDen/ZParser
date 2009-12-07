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
			r=(xyz->expr_g(xyz)).start;
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
				r=(xyz->expr_g(xyz)).start;
				ifnode->u=r->u;
			}
			MATCHT(ANTLR3_TOKEN_UP,NULL);
			MATCHT(EIF_END,NULL);
		}
	}

	void WhileExpr::Exec(pANTLR3_BASE_TREE wnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz)
	{
		ANTLR3_MARKER Wcond=((pANTLR3_BASE_TREE)(wnode->getChild(wnode,0)))->savedIndex;
		ANTLR3_MARKER Wexpr=((pANTLR3_BASE_TREE)(wnode->getChild(wnode,1)))->savedIndex;
		ANTLR3_MARKER Wend =((pANTLR3_BASE_TREE)(wnode->getChild(wnode,2)))->savedIndex;

		while(boost::apply_visitor(BoolVal(),*((ZTvarp)(cond->u)))== ZBTrue )
		{
			SEEK(Wexpr);
			MATCHT(EWHILE_EXP,NULL);
			MATCHT(ANTLR3_TOKEN_DOWN,NULL);
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
		//ANTLR3_MARKER fid = ( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 0 ) ) ) -> savedIndex ;
		//ANTLR3_MARKER fsrc = ( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 1 ) ) ) -> savedIndex ;
		ANTLR3_MARKER fexpr = ( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 2 ) ) ) -> savedIndex ;
		ANTLR3_MARKER fend = ( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 3 ) ) ) -> savedIndex ;

		pANTLR3_BASE_TREE tsrc=( ( pANTLR3_BASE_TREE ) ( fnode -> getChild ( fnode , 1 ) ) );
		pANTLR3_BASE_TREE tstart= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 0 ) ;
		pANTLR3_BASE_TREE tend= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 1 ) ;
		pANTLR3_BASE_TREE tby= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 2 ) ;
		pANTLR3_BASE_TREE twhere= ( pANTLR3_BASE_TREE ) tsrc -> getChild ( tsrc , 3 ) ;

		double start = atof ( ( char * ) getNodeText ( ( pANTLR3_BASE_TREE ) tstart -> getChild ( tstart , 0 ) ) ) ;
		double end = atof ( ( char * ) getNodeText ( ( pANTLR3_BASE_TREE ) tend -> getChild ( tend , 0 ) ) ) ;
		double scale = ( tby != NULL ) ? atof ( ( char * ) getNodeText ( ( pANTLR3_BASE_TREE ) tby -> getChild ( tby , 0 ) ) ) : 1;
		bool cond = (twhere!=NULL) ? boost :: apply_visitor ( BoolVal ( ) , * ( ( ZTvarp ) ( ((pANTLR3_BASE_TREE)twhere->getChild(twhere,0)) -> u ) ) ) ==  ZBTrue : ZBTrue;

		for ( ; start <= end && cond ; start += scale )
		{
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
		//cout<<getNodeText((pANTLR3_BASE_TREE)dnode->getChild(dnode,0))<<endl;
		//cout<<getNodeText((pANTLR3_BASE_TREE)dnode->getChild(dnode,1))<<endl;
		//cout<<getNodeText((pANTLR3_BASE_TREE)dnode->getChild(dnode,2))<<endl;
		
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
	void CaseExpr::Exec(pANTLR3_BASE_TREE caseNode, yatgFW_Ctx_struct * xyz)
	{
		ANTLR3_MARKER caseexpr=(((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,0))->savedIndex);
		ANTLR3_MARKER item=(((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,1))->savedIndex);
		//cout<<getNodeText((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,0))<<endl;
		pANTLR3_BASE_TREE titem=(pANTLR3_BASE_TREE)caseNode->getChild(caseNode,1);
		//cout<<getNodeText(titem)<<endl;
		//cout<<getNodeText((pANTLR3_BASE_TREE)(titem)->getChild(titem,0))<<endl;
		SEEK(item);
		MATCHT(CASE_Item,NULL);
		MATCHT ( ANTLR3_TOKEN_DOWN , NULL ) ;

		pANTLR3_BASE_TREE t = (pANTLR3_BASE_TREE)((pANTLR3_BASE_TREE)caseNode->getChild(caseNode,0));
		pANTLR3_BASE_TREE p=(pANTLR3_BASE_TREE)t->getChild(t,0);
		char* var = getNodeText((pANTLR3_BASE_TREE)p->getChild(p,0));
		ZTvarp x= ZInterp::ZSym.currentScope->lookup<ZTvar>(var);
		string res=boost::apply_visitor(ToString(),*x);
		//cout<<getNodeText((pANTLR3_BASE_TREE)(titem)->getChild(titem,0))<<endl;
		//cout<<boost::apply_visitor(ToString(),*x)<<endl;
		int c=1;
		while((pANTLR3_BASE_TREE)(caseNode)->getChild(caseNode,c)!=NULL)
		{
			string itemstr=getNodeText((pANTLR3_BASE_TREE)((pANTLR3_BASE_TREE)(caseNode)->getChild(caseNode,c))->getChild((pANTLR3_BASE_TREE)(caseNode)->getChild(caseNode,c),0));
			if(itemstr[0]=='"' )
			{
				itemstr.erase(0,1);
				itemstr.erase(itemstr.size()-1,1);
			}
			//cout<<itemstr<<endl;

			if(res== itemstr || itemstr == "DEFAULT")
			{
				pANTLR3_BASE_TREE tt = (pANTLR3_BASE_TREE)caseNode->getChild(caseNode,c);
				SEEK(((pANTLR3_BASE_TREE)(tt->getChild(tt,1)))->savedIndex);
				//cout<<(pANTLR3_BASE_TREE)(titem->getChild(titem,1))<<endl;
				xyz->expr_g(xyz);
				break;
			}
			MATCHT(ANTLR3_TOKEN_UP , NULL);
			c++;
		}
		MATCHT(ANTLR3_TOKEN_UP , NULL);
		MATCHT(ANTLR3_TOKEN_UP , NULL);
		//cout<<var<<"="<<boost::apply_visitor(ToString(),*x)<<endl;
		
	}

};