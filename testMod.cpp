#include "stdafx.h"
#include "ZInterp.h"

class Zsqrt : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE_1

	template<class S,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1) const
	{
		return ZTFloat(sqrtf(a1.cont->val));;
	}

	static ZTvarp Zsqrt_(ZTvarS var)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		*res=boost::apply_visitor(Zsqrt(),*(var[0]));
		return res;
	}
};

class Zpower : public boost::static_visitor<ZTvar>
{
public:

	BASE_CASE

	template<class S,class W,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<W,NumOps> &a2) const
	{
		return ZTFloat(pow((ZIFloat)a1.cont->val,(ZIFloat)a2.cont->val));;
	}

	static ZTvarp Zpower_(ZTvarS var)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		*res=boost::apply_visitor( Zpower() , *(var[0]) ,*(var[1]) );
		return res;
	}
};


ZTvarp Zprint(ZTvarS var)
{
	std::cout<< boost::apply_visitor(ToString(),*(var[0])) ;
	ZTvarp res=ZAlloc(ZTvar,1);
	*res=ZTBool(true);
	return res;
}

ZTvarp ZprintL(ZTvarS var)
{
	std::cout<< boost::apply_visitor(ToString(),*(var[0])) <<endl;
	ZTvarp res=ZAlloc(ZTvar,1);
	*res=ZTBool(true);
	return res;
}

void ZModInit_Test()
{
	ZFunction* zf=ZAlloc(ZFunction,4);

	zf->pFunInit(1,Zprint);
	ZInterp::ZSym.currentScope->FunTable.Insert(zf,_ZC("print"));

	zf++;
	zf->pFunInit(1,ZprintL);
	ZInterp::ZSym.currentScope->FunTable.Insert(zf,_ZC("printL"));

	zf++;
	zf->pFunInit(1,Zsqrt::Zsqrt_);
	ZInterp::ZSym.currentScope->FunTable.Insert(zf,_ZC("sqrt"));

	zf++;
	zf->pFunInit(2,Zpower::Zpower_);
	ZInterp::ZSym.currentScope->FunTable.Insert(zf,_ZC("pow"));
}