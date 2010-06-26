#include "../stdafx.h"
#include "../ZInterp.h"
#include <math.h>

class ZMath : public ZTBaseObject<ZMath> 
{
public:

	ZTvar ZPI;
	ZTvar ZEXP;
	
	static void Init()
	{
		StProps.InitScope();
		AddFunction(_ZC("xtoString"),0,&ZMath::toString);
		AddFunction(_ZC("Zsqrt"),1,&ZMath::Zsqrt);
		AddFunction(_ZC("Zpow"),2,&ZMath::Zpow);
		AddFunction(_ZC("Zsqrt"),1,&ZMath::Zsqrt);
		AddFunction(_ZC("Zsin"),1,&ZMath::Zsin);
		AddFunction(_ZC("Zcos"),1,&ZMath::Zcos);
		AddFunction(_ZC("Ztan"),1,&ZMath::Ztan);
	
		ZTObject::Inheriet(StProps);
	}

	ZMath(ZTvarS inp)
	{
		//defulat values
		ZPI=ZTFloat(22/7);
		ZEXP=ZTFloat(2.71);
		//constructor inits
		
		ZMath();
	}

	ZMath()
	{
		AddDataMember(_ZC("PI") , &ZMath::ZPI);
		AddDataMember(_ZC("EXP") , &ZMath::ZEXP);
	}

	ZTvarp toString(ZTvarS inp)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		ZIString str=_ZC("Math Object");
		
		*res=ZTString(str);
		return res;
	}

	ZTvarp Zsqrt(ZTvarS inp)
	{
		ZIFloat in = FLOAT_ZCONV(*inp[0]);
		//ZIInteger ai = boost::get<gZFloat>(a).cont->val;

		ZIFloat fr = /*(float)*/sqrtf(in);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}

	ZTvarp Zpow(ZTvarS inp)
	{
		ZIFloat in = FLOAT_ZCONV(*inp[0]);
		ZIFloat ai = FLOAT_ZCONV(*inp[1]);

		ZIFloat fr = (float)pow(in,ai);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}

	ZTvarp Zsin(ZTvarS inp)
	{
		ZIFloat in = FLOAT_ZCONV(*inp[0]);
		//ZIFloat ai = boost::get<gZInt>(*inp[1]).cont->val;

		ZIFloat fr = (float)sin(in);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}

	ZTvarp Zcos(ZTvarS inp)
	{
		ZIFloat in = FLOAT_ZCONV(*inp[0]);
		//ZIFloat ai = boost::get<gZInt>(*inp[1]).cont->val;

		ZIFloat fr = (float)cos(in);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}

	ZTvarp Ztan(ZTvarS inp)
	{
		ZIFloat in = FLOAT_ZCONV(*inp[0]);
		//ZIFloat ai = boost::get<gZInt>(*inp[1]).cont->val;

		ZIFloat fr = (float)tan(in);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}
	
};

void ZModInit_ZMath()
{
	ZMath::Init();

	ZTvarp zv = ZAlloc(ZTvar,1);
	//ZTOInstance zin;
	//zin.val = new ZMath();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZMath();
	ZInterp::ZSym.InsertSymbol(_ZC("ZMath"),zv);

}