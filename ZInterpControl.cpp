#include "stdafx.h"
#include "ZInterp.h"

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
	void Operand::FunCall(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE arg,yatgFW_Ctx_struct* xyz)
	{
		pANTLR3_BASE_TREE t2=(pANTLR3_BASE_TREE)t1->getChild(t1,0);
		ZChar* vName = getNodeText(t2);
		ZFunction* var;
		var = ZSym.getSymbol<ZFunction>(vName,true);
		if(var==NULL)
			std::cout<<"Function : "<<vName<<" Not defined"<<std::endl;

		//collect arguments in a vector before calling
		ZTvarS Fargs;
		ZTvarp vp;
		for(int i=0;i<arg->children->count;i++)
		{
			vp=(ZTvarp)((pANTLR3_BASE_TREE)arg->getChild(arg,i))->u;
			Fargs.push_back(vp);
		}
		switch(var->FunT)
		{
		case ZInternal:
			break;
		case ZExternal:
			ZInterp::setCustomNodeField(t1,(*(var->FunData.pFun))(Fargs));
			break;
		}

	}

	void IfExpr::Exec(pANTLR3_BASE_TREE ifnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz)
	{
		pANTLR3_BASE_TREE r;
		if(boost::apply_visitor(BoolVal(),*((ZTvarp)(cond->u)))== ZBTrue )
		{
			r=(pANTLR3_BASE_TREE)(ifnode->getChild(ifnode,1));
			SEEK(r->savedIndex);
			MATCHT(EIF_THEN,NULL);
			MATCHT(ANTLR3_TOKEN_DOWN,NULL);
			xyz->expr_g(xyz);
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
				xyz->expr_g(xyz);
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
};