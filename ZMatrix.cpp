#include "stdafx.h"
#include "ZInterp.h"
class ZMatrix : public ZTBaseObject<ZMatrix> 
{
public:
    ZTMatrix myMatrix;
    
    static void Init()
    {
        StProps.InitScope();

        AddFunction(_ZC("toString"),1,&ZMatrix::toString);
		AddFunction(_ZC("add"),2,&ZMatrix::Zadd);

        ZTObject::Inheriet(StProps);
    }

    ZMatrix(ZTvarS inp)
    {
		//myMatrix.val= MATRIX_ZCONV(*inp[0]);        
        ZMatrix();
    }

    ZMatrix()
    {
    }

    ZTvarp Zadd(ZTvarS inp)
    {
		ZTMatrix myMatrix1= MATRIX_ZCONV(*inp[0]);
		ZTMatrix myMatrix2= MATRIX_ZCONV(*inp[1]);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTMatrix(myMatrix1.val+myMatrix2.val);
		return res;    }

	ZTvarp ZTransport(ZTvarS inp)
    {
		ZTMatrix myMatrix1= MATRIX_ZCONV(*inp[0]);
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTMatrix(myMatrix1.val.transpose());
		return res;
    }
	
	ZTvarp toString(ZTvarS inp)
	{
		return NULL;
	}
    
};

void ZModInit_ZMatrix()
{
	ZMatrix::Init();

	ZTvarp zv = ZAlloc(ZTvar,1);
	ZTOInstance zin;
	zin.val = new ZMatrix();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZMatrix();
	ZInterp::ZSym.InsertSymbol(_ZC("ZMatrix"),zv);

}