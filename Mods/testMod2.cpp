#include "../stdafx.h"
#include "../ZInterp.h"

class ASD : public ZTBaseObject<ASD> 
{
public:

	ZTvar a;
	ZTvar b;
	
	static void Init()
	{
		StProps.InitScope();
		AddFunction(_ZC("xtoString"),0,&ASD::toString);
		AddFunction(_ZC("Square"),1,&ASD::sq);
	
		ZTObject::Inheriet(StProps);
	}

	ASD(ZTvarS inp)
	{
		//defulat values
		a=ZTInt(90);
		b=ZTInt(45);
		//constructor inits
		switch(inp.size())
		{
		case 2:
			b=*inp[1];
		case 1:
			a=*inp[0];
		case 0:
			break;
		}
		ASD();
	}

	ASD()
	{
		AddDataMember(_ZC("a") , &ASD::a);
		AddDataMember(_ZC("b") , &ASD::b);
	}

	ZTvarp toString(ZTvarS inp)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		ZIString str=_ZC("ASD Object");
		str.append(_ZC(" a = ")); 
		str.append(boost::apply_visitor(ToString(),a));
		str.append(_ZC(" b = ")); 
		str.append(boost::apply_visitor(ToString(),b));
		*res=ZTString(str);
		return res;
	}

	ZTvarp sq(ZTvarS inp)
	{
		ZIInteger in = gFLOAT_ZCONV(*inp[0]).cont->val;
		ZIInteger ai = gFLOAT_ZCONV(a).cont->val;

		ZIFloat fr = (in*in+ai*ai)/(ZIFloat)(in);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTFloat(fr);
		return res;
	}
	
};

void ZModInit_Test2()
{
	ASD::Init();

	ZTvarp zv = ZAlloc(ZTvar,1);
	ZTOInstance zin;
	zin.val = new ASD();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ASD();
	ZInterp::ZSym.InsertSymbol(_ZC("ASD"),zv);

}