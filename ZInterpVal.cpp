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


extern ZBuiltinModule ZBMods[];

namespace ZInterp
{
	
	ZSymbolTable<ZTvar> ZSym;
	ZIBool isExit=ZBFalse,isContinue=ZBFalse,ifScope=ZBFalse,caseScope=ZBFalse;
    vector <ANTLR3_MARKER> lend,lCon;
	int loopNum=0,actual=0,currentFrame=0,currentLine=1;
	yatgFW_Ctx_struct* cxtr;

	void global::Init()
	{
		ZSym . InitScope();
	}

	void global :: IncScope()
	{
		if(!ifScope || !caseScope)
			ZSym . InitScope ( ) ;
	}

	void global :: DecScope ( )
	{
		if(!ifScope || !caseScope)
			ZSym . FinScope();
	}

	void global::InitBuiltinMods()
	{
		int i=0;
		while(true)
		{
			if (ZBMods[i].ZModInitFunc==0)
				break;
			(*ZBMods[i].ZModInitFunc)();
			i++;
		}
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


	void Operand::_OPERAND(pANTLR3_BASE_TREE t1  )
	{
		pANTLR3_BASE_TREE t2=(pANTLR3_BASE_TREE)t1->getChild(t1,0);
		ZChar* vName = getNodeText(t2);
		ZTvarp var;
		var = ZSym.getSymbol(vName,true);
		if(var==NULL)
		{
			var=ZAlloc(ZTvar,1);
			ZSym.InsertSymbol(vName,var);
		}
		setCustomNodeField(t1,var);
	}

    void Operand::AccessListElement(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE ind)
	{
		pANTLR3_BASE_TREE aind=(pANTLR3_BASE_TREE)ind->getChild(ind,0);
        ZIInteger index=INT_ZCONV(*(ZTvarp)(aind->u));
		ZTList* list=( gLIST_ZCONV( *(ZTvarp)(t1->u) )).cont;
		setCustomNodeField(t1,list->val[index]);
	}

	void Operand::AccessObjectField(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE field)
	{
		pANTLR3_BASE_TREE afield=(pANTLR3_BASE_TREE)field->getChild(field,0);
		ZChar* vName = getNodeText(afield);
		ZTvarp var,elm;
		ZTOInstance* zin=( gINSTANCE_ZCONV( *(ZTvarp)(t1->u) )).cont;
		var = zin->val->getDyn().getSymbol(vName,true);
		if(var!=NULL)
		{
			switch( boost::apply_visitor(getType(),*var) )
			{
			case ZETMemDataItem:
				elm = (boost::apply_visitor(ZTDataBridge((MEMDATA_ZCONV(*var))), *(ZTvarp)(t1->u) ));
				break;
			case ZETFunction:
				FUNCTION_ZCONV( *var )->obj = (ZTvarp)(t1->u);
				elm = var;
				break;
			}
			setCustomNodeField(t1,elm);
		}
		else
		{
			ZError::Throw<ZNotDefined>();
			//printf("it's not a member of object\n");
			//exit(5);
		}
	}

	// TODO : use a pool of preallocaed temps , should affect
	//		  performance greatly

	void Number::Exec(pANTLR3_BASE_TREE numNode)
	{
		ZTvarp var=ZAlloc(ZTvar,1);
		string str=getNodeText(numNode);
		int cc=numNode->getChildCount(numNode);
		
		if(numNode->getChildCount(numNode)>1)
		{
			pANTLR3_BASE_TREE num=(pANTLR3_BASE_TREE)numNode->getChild(numNode,1);
			*var=ZTFloat(boost::lexical_cast<float,ZChar*>(getNodeText(num))*-1);
			setCustomNodeField(numNode,var);
		}
		else
		{
			pANTLR3_BASE_TREE num=(pANTLR3_BASE_TREE)numNode->getChild(numNode,0);
			*var=ZTFloat(boost::lexical_cast<float,ZChar*>(getNodeText(num)));
			setCustomNodeField(numNode,var);
		}
	}

	void Number::Exec1(pANTLR3_BASE_TREE numNode)
	{
		ZTvarp var=ZAlloc(ZTvar,1);
		string str=getNodeText(numNode);
		int cc=numNode->getChildCount(numNode);
		
		if(numNode->getChildCount(numNode)>1)
		{
			pANTLR3_BASE_TREE num=(pANTLR3_BASE_TREE)numNode->getChild(numNode,1);
			*var=ZTFloat(boost::lexical_cast<float,ZChar*>(getNodeText(num))*-1);
			setCustomNodeField(numNode,var);
		}
		else
		{
			pANTLR3_BASE_TREE num=(pANTLR3_BASE_TREE)numNode->getChild(numNode,0);
			*var=ZTFloat(boost::lexical_cast<float,ZChar*>(getNodeText(num)));
			setCustomNodeField(numNode,var);
		}

	}

	void Constant::Exec(pANTLR3_BASE_TREE c)
	{
		ZTvarp var=ZAlloc(ZTvar,1);
		string str;
		switch(c->getToken(c)->type)
		{
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

	void Constant::ComplexExec(pANTLR3_BASE_TREE c)
	{
		ZTvarp var=ZAlloc(ZTvar,1);
		switch(c->getToken(c)->type)
		{
		case ARR_A:
			ZTList zl;
			if(c->children!=NULL)
			{
				for ( int i = 0 ; i < c->children->count ; i++ )
				{
					ZTvarp vp=ZAlloc(ZTvar,1);
					*vp = *((ZTvarp)((pANTLR3_BASE_TREE)c->getChild(c,i))->u);
					zl.Append ( vp ) ;
				}
			}
			*var=zl;
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
		case SS_PERCENT:
			*var=boost::apply_visitor(Modulus(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
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
		case SS_D_EQUAL:
			*var=boost::apply_visitor(Boolean::Equal(),*((ZTvarp)t1->u),*((ZTvarp)t2->u));
			break;
		case SS_LT_EQUAL:
			*var=boost::apply_visitor(Boolean::Or(),
				boost::apply_visitor(Boolean::Equal(),*((ZTvarp)t1->u),*((ZTvarp)t2->u)),
				boost::apply_visitor(Boolean::Less(),*((ZTvarp)t1->u),*((ZTvarp)t2->u))
				);
			break;
		case SS_GT_EQUAL:
			*var=boost::apply_visitor(Boolean::Or(),
				boost::apply_visitor(Boolean::Equal(),*((ZTvarp)t1->u),*((ZTvarp)t2->u)),
				boost::apply_visitor(Boolean::Great(),*((ZTvarp)t1->u),*((ZTvarp)t2->u))
				);
			break;
		}
		setCustomNodeField(r,var);
	}

	void ExprSeq::_ESEQ(pANTLR3_BASE_TREE e)
	{
		if(e->getChildCount(e)>0)
		{
			pANTLR3_BASE_TREE p=((pANTLR3_BASE_TREE)(e->getChild(e, e->getChildCount(e)-1)));
			e->u=p->u;
		}
		else
		{
			pANTLR3_BASE_TREE p=((pANTLR3_BASE_TREE)(e->getChild(e, e->getChildCount(e)-1)));
			ZIFloat fr = (float)0;

			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			e->u=res;
		}
	}

	void AssingmentExpr::Exec(pANTLR3_BASE_TREE r,pANTLR3_BASE_TREE l,pANTLR3_BASE_TREE e)
	{
		pANTLR3_BASE_TREE p;
		switch(r->getToken(r)->type)
		{
		case SS_EQUAL:
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
		r -> u = l -> u ;
	}

    void EXIT :: Exec ( pANTLR3_BASE_TREE exitNode , yatgFW_Ctx_struct *xyz )
    {
        char * n=(((pANTLR3_BASE_TREE)exitNode->getChild(exitNode,0))!=NULL)? getNodeText((pANTLR3_BASE_TREE)(((pANTLR3_BASE_TREE)exitNode->getChild(exitNode,0))->getChild((pANTLR3_BASE_TREE)exitNode->getChild(exitNode,0),0))) : "1";
        isExit = ZBTrue ;
        loopNum=atoi(n);
        SEEK(lend[0]);
        switch(LA(1))
        {
        case EFOR_END:
            MATCHT(EFOR_END,NULL);
            break;
        case EDO_END:
            MATCHT(EDO_END,NULL);
            break;
        case EWHILE_END:
            MATCHT(EWHILE_END,NULL);
            break;
        }

    }
	void CONTINUE :: Exec ( pANTLR3_BASE_TREE conNode , yatgFW_Ctx_struct *xyz )
    {
     //   char * n=getNodeText((pANTLR3_BASE_TREE)((pANTLR3_BASE_TREE)exitNode->getChild(exitNode,0))->getChild((pANTLR3_BASE_TREE)exitNode->getChild(exitNode,0),0));
        isContinue = ZBTrue ;
        //loopNum=atoi(n);
        SEEK(lCon[0]);
        switch(LA(1))
        {
        case EFOR_END:
            MATCHT(EFOR_END,NULL);
            break;
        case EDO_END:
            MATCHT(EDO_END,NULL);
            break;
        case EWHILE_END:
            MATCHT(EWHILE_END,NULL);
            break;
        }
	}

	void Matrix::Exec(pANTLR3_BASE_TREE matrixNode , yatgFW_Ctx_struct* xyz)
	{
		MATCHT(MATRIX,NULL);
		MATCHT(ANTLR3_TOKEN_DOWN,NULL);
		for ( int i=0;i<matrixNode->getChildCount(matrixNode);i++)
		{
			pANTLR3_BASE_TREE row= (pANTLR3_BASE_TREE)matrixNode->getChild(matrixNode,i);
			MATCHT(ROW,NULL);
			MATCHT(ANTLR3_TOKEN_DOWN,NULL);
			for( int j=0;j<row->getChildCount(row);j++)
			{
				pANTLR3_BASE_TREE element=(pANTLR3_BASE_TREE)row->getChild(row,j);
				//SEEK(element->savedIndex);
				xyz->expr_g(xyz);
				MATCHT(ANTLR3_TOKEN_UP,NULL);
			}
		}
		cout<<"Matrix"<<endl;

	}


};
