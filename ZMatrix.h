#include "stdafx.h"
#include "ZInterp.h"
class ZMatrix : public ZTBaseObject<ZMatrix> 
{
public:
    ZTMatrix myMatrix;
    
    static void Init()
    {
        StProps.InitScope();

        AddFunction(_ZC("ToString"),1,&ZMatrix::toString);
		AddFunction(_ZC("Transpose1"),1,&ZMatrix::ZTransport1);
        AddFunction(_ZC("Transpose"),0,&ZMatrix::ZTransport);
		AddFunction(_ZC("Add"),2,&ZMatrix::Zadd);
		AddFunction(_ZC("CreateTranslation"),3,&ZMatrix::ZTranslate);
		AddFunction(_ZC("CreateScale"),3,&ZMatrix::ZScale);
		AddFunction(_ZC("CreateRotation"),3,&ZMatrix::ZRotateEuler);
		
        ZTObject::Inheriet(StProps);
    }

    ZMatrix(ZTvarS inp)
    {
		myMatrix.val= MATRIX_ZCONV(*(inp[0]));        
        ZMatrix();
    }

    ZMatrix()
    {
    }

    ZTvarp Zadd(ZTvarS inp)
    {
		ZTMatrix myMatrix1= MATRIX_ZCONV(*(inp[0]));
		ZTMatrix myMatrix2= MATRIX_ZCONV(*(inp[1]));
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTMatrix(myMatrix1.val+myMatrix2.val);
		return res;    }

	ZTvarp ZTransport(ZTvarS inp)
    {
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTMatrix(myMatrix.val.transpose());
		return res;
    }
	
	ZTvarp ZTransport1(ZTvarS inp)
    {
		ZTMatrix m = MATRIX_ZCONV(*(inp[0]));
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTMatrix(m.val.transpose());
		return res;
		
    }

	ZTvarp ZTranslate(ZTvarS inp)
    {
		ZIFloat x= FLOAT_ZCONV(*(inp[0]));
		ZIFloat y= FLOAT_ZCONV(*(inp[1]));
		ZIFloat z= FLOAT_ZCONV(*(inp[2]));

		
		Eigen::Transform<float,3> t ;//= Eigen::Translation3f(3.4,2.3,3.4);	
		t.setIdentity();
		ZTvarp res=ZAlloc(ZTvar,1);
		//Eigen::Translation<float,Eigen::Dynamic> t;
		t.translate(Eigen::Vector3f(x,y,z));
		*res = ZTMatrix( t );
		return res;
    }

	ZTvarp ZScale(ZTvarS inp)
    {
		ZIFloat x= FLOAT_ZCONV(*(inp[0]));
		ZIFloat y= FLOAT_ZCONV(*(inp[1]));
		ZIFloat z= FLOAT_ZCONV(*(inp[2]));

		
		Eigen::Transform<float,3> t ;//= Eigen::Translation3f(3.4,2.3,3.4);	
		t.setIdentity();
		ZTvarp res=ZAlloc(ZTvar,1);
		//Eigen::Translation<float,Eigen::Dynamic> t;
		t.scale(Eigen::Vector3f(x,y,z));
		*res = ZTMatrix( t );
		return res;
    }

	ZTvarp ZRotateEuler(ZTvarS inp)
    {
		ZIFloat x= FLOAT_ZCONV(*(inp[0]));
		ZIFloat y= FLOAT_ZCONV(*(inp[1]));
		ZIFloat z= FLOAT_ZCONV(*(inp[2]));

		
		Eigen::Transform<float,3> t ;
		t.setIdentity();
		ZTvarp res=ZAlloc(ZTvar,1);
		t       = Eigen::AngleAxisf(x, Vector3f::UnitZ())
				* Eigen::AngleAxisf(y, Vector3f::UnitY())
				* Eigen::AngleAxisf(z, Vector3f::UnitZ());

		//t.translate(Eigen::Vector3f(x,y,z));
		*res = ZTMatrix( t );
		return res;
    }

	

	ZTvarp toString(ZTvarS inp)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTString("MATRIX is");
		cout<<myMatrix.val<<endl;
		return res;
	}
    
};

void ZModInit_ZMatrix()
{
	ZMatrix::Init();

	ZTvarp zv = ZAlloc(ZTvar,1);
	//ZTOInstance zin;
	//zin.val = new ZMatrix();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZMatrix();
	ZInterp::ZSym.InsertSymbol(_ZC("ZMatrix"),zv);

}