#include "stdafx.h"
#include "ZInterp.h"
#include <math.h>

#define HAS_ERROR(x,y)\
		if (inp.size() != y)\
		{\
			ZError::Throw<ZWrongNumberOfArguments>();\
			return NULL;\
		}

#define HAS_ERROR1(x,y)\
		if (inp.size() < y)\
		{\
			ZError::Throw<ZWrongNumberOfArguments>();\
			return NULL;\
		}


class ZMath : public ZTBaseObject<ZMath> 
{
public:

	ZTvar ZPI;
	ZTvar ZEXP;
	
	static void Init()
	{
		StProps.InitScope();
		AddFunction(_ZC("ToString"),0,&ZMath::toString);

		AddFunction(_ZC("Power"),2,&ZMath::Zpow);
		AddFunction(_ZC("Sqrt"),1,&ZMath::Zsqrt);
		AddFunction(_ZC("Abs"),1,&ZMath::ZAbs);
		AddFunction(_ZC("Floor"),1,&ZMath::ZFloor);
		AddFunction(_ZC("Ceil"),1,&ZMath::ZCeil);
		
		AddFunction(_ZC("Sin"),1,&ZMath::Zsin);
		AddFunction(_ZC("Cos"),1,&ZMath::Zcos);
		AddFunction(_ZC("Tan"),1,&ZMath::Ztan);
		AddFunction(_ZC("ASin"),1,&ZMath::ZAsin);
		AddFunction(_ZC("ACos"),1,&ZMath::ZAcos);
		AddFunction(_ZC("ATan"),1,&ZMath::ZAtan);
		AddFunction(_ZC("Sinh"),1,&ZMath::Zsinh);
		AddFunction(_ZC("Cosh"),1,&ZMath::Zcosh);
		AddFunction(_ZC("Tanh"),1,&ZMath::Ztanh);
		
		AddFunction(_ZC("ToRedian"),1,&ZMath::Ztoredian);
		AddFunction(_ZC("ToDegree"),1,&ZMath::Ztodegree);
	
		AddFunction(_ZC("Exp"),1,&ZMath::ZExp);
		AddFunction(_ZC("Log"),1,&ZMath::ZLog);
		AddFunction(_ZC("Log1"),1,&ZMath::ZLog1);

		AddFunction(_ZC("Max"),2,&ZMath::ZMax);
		AddFunction(_ZC("Min"),2,&ZMath::ZMin);
		AddFunction(_ZC("Random"),2,&ZMath::ZRandom);

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

	ZTvarp ZCeil(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ceilf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp ZFloor(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(floorf(FLOAT_ZCONV(*inp[0])));
		return res;
	}
	
	ZTvarp ZAbs(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(abs(FLOAT_ZCONV(*inp[0])));
		return res;
	}


	ZTvarp Zsqrt(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(sqrtf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp Zpow(ZTvarS inp)
	{
		HAS_ERROR(inp,2)
		ZIFloat in = FLOAT_ZCONV(*inp[0]);
		ZIFloat ai = FLOAT_ZCONV(*inp[1]);

		ZIFloat fr = (float)pow(in,ai);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}

	ZTvarp Zsin(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(sinf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp Zcos(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(cosf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp Ztan(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(tanf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp ZAsin(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(asinf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp ZAcos(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(acosf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp ZAtan(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat(atanf(FLOAT_ZCONV(*inp[0]))));
		return res;
	}

	ZTvarp Zsinh(ZTvarS inp)
	{
		HAS_ERROR(inp,1)
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(sinhf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp Zcosh(ZTvarS inp)
	{
		HAS_ERROR(inp,1);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(coshf(FLOAT_ZCONV(*inp[0])));
		return res;
	}

	ZTvarp Ztanh(ZTvarS inp)
	{
		HAS_ERROR(inp,1);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat(tanhf(FLOAT_ZCONV(*inp[0]))));
		return res;
	}

	ZTvarp Ztoredian(ZTvarS inp)
	{
		HAS_ERROR(inp,1);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat((FLOAT_ZCONV(*inp[0]))*3.141/180));
		return res;
	}

	ZTvarp Ztodegree(ZTvarS inp)
	{
		HAS_ERROR(inp,1);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat((FLOAT_ZCONV(*inp[0]))*180/3.141));
		return res;
	}

	ZTvarp ZExp(ZTvarS inp)
	{
		HAS_ERROR(inp,1);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat(expf(FLOAT_ZCONV(*inp[0]))));
		return res;
	}

	ZTvarp ZLog(ZTvarS inp)
	{
		HAS_ERROR(inp,1);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat(logf(FLOAT_ZCONV(*inp[0]))));
		return res;
	}

	ZTvarp ZLog1(ZTvarS inp)
	{
		HAS_ERROR(inp,2);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(ZTFloat(log(FLOAT_ZCONV(*inp[0]))/logf(FLOAT_ZCONV(*inp[1]))));
		return res;
	}

	ZTvarp ZMax(ZTvarS inp)
	{
		HAS_ERROR1(inp,2);
		float max=FLOAT_ZCONV(*(inp[0]));
		for ( int i=1 ;i < inp.size();i++)
		{
			if(max<FLOAT_ZCONV(*(inp[i])))
			{
				max=FLOAT_ZCONV(*(inp[i]));
			}
		}
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(max);
		return res;
	}

	ZTvarp ZMin(ZTvarS inp)
	{
		HAS_ERROR1(inp,2);
		float min=FLOAT_ZCONV(*(inp[0]));
		for ( int i=1; i < inp.size();i++)
		{
			if(min>FLOAT_ZCONV(*(inp[i])))
			{
				min=FLOAT_ZCONV(*(inp[i]));
			}
		}
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(min);
		return res;
	}

	ZTvarp ZRandom(ZTvarS inp)
	{
		HAS_ERROR1(inp,2);
		//time_t t;
		//srand(t);
		int max=FLOAT_ZCONV(*(inp[1]));
		int min=FLOAT_ZCONV(*(inp[0]));
		float rand1= (rand()%max+min)%max;
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(rand1);
		return res;
	}



};
