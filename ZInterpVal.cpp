#include "stdafx.h"
#include "ZInterp.h"

namespace ZInterp
{
	ZSymbolTable<ZTvar,ZTmfp> ZSym;


	void global::Init()
	{
		ZSym.InitScope();
	}

	void global::IncScope()
	{
		ZSym.InitScope();
	}

	void global::DecScope()
	{
		ZSym.FinScope();
	}


	inline
		ZChar* getNodeText(pANTLR3_BASE_TREE n)
	{
		return (ZChar*)n->getText(n)->chars;
	}

	inline
		void setCustomNodeField(pANTLR3_BASE_TREE t,ZTvarp v)
	{
		t->u=(void *)v;
	}


	void Operand::_OPERAND(pANTLR3_BASE_TREE t1)
	{
		pANTLR3_BASE_TREE t2=(pANTLR3_BASE_TREE)t1->getChild(t1,0);
		ZChar* vName = getNodeText(t2);
		ZTvarp var;
		var = ZSym.getSymbol<ZTvar>(vName,true);
		if(var==NULL)
		{
			var=ZAlloc(ZTvar,1);
			ZSym.currentScope->VarTable.Insert(var,vName);
		}
		setCustomNodeField(t1,var);
	}


	// TODO : use a pool of preallocaed temps , should affect
	//		  performance greatly

	void Constant::Exec(pANTLR3_BASE_TREE c)
	{
		ZTvarp var=ZAlloc(ZTvar,1);
		switch(c->getToken(c)->type)
		{
		case DIGIT:
			*var=ZTInt(boost::lexical_cast<int,ZChar*>(getNodeText(c)));
			break;
		case HEX_LITERAL:
			{
				int x;   
				std::stringstream ss;
				ss << std::hex << getNodeText(c);
				ss >> x;
				*var=ZTInt(x);
			}
			break;
		case STRING_LITERIAL:
			{
				ZTString s((getNodeText(c)));
				s.RemQuotes();
				*var=s;
			}
			break;
		case KW_TRUE:
			*var=ZTBool(true);
			break;
		case KW_FALSE:
			*var=ZTBool(false);
			break;
		}
		setCustomNodeField(c,var);
	}

	void Cexprx::Exec(pANTLR3_BASE_TREE r,pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE t2)
	{
		ZTvarp var=ZAlloc(ZTvar,1);
		switch(r->getToken(r)->type)
		{
		case SS_PLUS:
			*var=boost::apply_visitor(Sum(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_MINUS:
			*var=boost::apply_visitor(Subtract(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_STAR:
			*var=boost::apply_visitor(Multiply(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_FSLASH:
			*var=boost::apply_visitor(Divide(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_D_AMP:
			*var=boost::apply_visitor(Boolean::And(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_D_BAR:
			*var=boost::apply_visitor(Boolean::Or(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_LT:
			*var=boost::apply_visitor(Boolean::Less(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_GT:
			*var=boost::apply_visitor(Boolean::Great(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_LT_EQUAL:
			break;
		case SS_GT_EQUAL:
			break;
		}
		setCustomNodeField(r,var);
	}

	void ExprSeq::_ESEQ(pANTLR3_BASE_TREE e)
	{
		pANTLR3_BASE_TREE p=((pANTLR3_BASE_TREE)(e->getChild(e, e->getChildCount(e)-1)));
		//cout<<p->toStringTree(p)->chars<<endl;
		e->u=p->u;
		//cout<<boost::apply_visitor(ToString(),*((ZTvarp)(p->u)))<<endl;
	}

	void AssingmentExpr::Exec(pANTLR3_BASE_TREE r,pANTLR3_BASE_TREE l,pANTLR3_BASE_TREE e)
	{
		switch(r->getToken(r)->type)
		{
		case SS_EQUAL:
			//cout<<boost::apply_visitor(ToString(),*((ZTvarp)(l->u)))<<endl;
			*((ZTvarp)(l->u))=*((ZTvarp)(e->u));
			break;
		case SS_PLUS_EQUAL:
			*((ZTvarp)(l->u))=boost::apply_visitor(Sum(),*((ZTvarp)(l->u)),*((ZTvarp)(e->u)) );
			break;
		case SS_MINUS_EQUAL:
			*((ZTvarp)(l->u))=boost::apply_visitor(Subtract(),*((ZTvarp)(l->u)),*((ZTvarp)(e->u)) );
			break;
		case SS_STAR_EQUAL:
			*((ZTvarp)(l->u))=boost::apply_visitor(Multiply(),*((ZTvarp)(l->u)),*((ZTvarp)(e->u)) );
			break;
		case SS_FSLASH_EQUAL:
			*((ZTvarp)(l->u))=boost::apply_visitor(Divide(),*((ZTvarp)(l->u)),*((ZTvarp)(e->u)) );
			break;
		case SS_PERCENT_EQUAL:
			break;
		}
		//((r->u))=((ZTvarp)(l->u));
		r->u=l->u;
	}
};