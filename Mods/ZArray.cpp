#include "../stdafx.h"
#include "../ZInterp.h"
#include<math.h>

class ZArray : public ZTBaseObject<ZArray> 
{
private:
	ZTList myList;
public:
	
	static void Init()
	{
		StProps.InitScope();
		AddFunction(_ZC("toString"),0,&ZArray::toString);
		AddFunction(_ZC("add"),1,&ZArray::Zadd);
		//AddFunction(_ZC("Zremove"),1,&ZArray::Zpow);
	
		ZTObject::Inheriet(StProps);
	}

	ZArray(ZTvarS inp)
	{
		//defulat values
		//ZPI=ZTFloat(22/7);
		//ZEXP=ZTFloat(2.71);
		//constructor inits
		
		ZArray();
	}

	ZArray()
	{
		//AddDataMember(_ZC("PI") , &ZArray::ZPI);
		//AddDataMember(_ZC("ZEXP") , &ZArray::ZEXP);
	}

	ZTvarp toString(ZTvarS inp)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		
		*res=ZTString(boost::apply_visitor(ToString(),ZTvar(myList)));
		return res;
	}

	ZTvarp Zadd(ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZError::Throw<ZWrongNumberOfArguments>();
			return NULL;
		}

		//ZIFloat in = boost::get<gZInt>(*inp[0]).cont->val;
		//ZIInteger ai = boost::get<gZFloat>(a).cont->val;
		myList.Concat(inp);
		//ZIFloat fr = (float)sqrtf(in);

		ZTvarp res=ZAlloc(ZTvar,1);
		*res = myList;
		return res;
	}
	
};

void ZModInit_ZArray()
{
	ZArray::Init();

	ZTvarp zv = ZAlloc(ZTvar,1);
	//ZTOInstance zin;
	//zin.val = new ZArray();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZArray();
	ZInterp::ZSym.InsertSymbol(_ZC("ZArray"),zv);

}