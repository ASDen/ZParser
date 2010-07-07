class ZMatrix : public ZTBaseObject<ZMatrix> 
{
public:
    ZTMatrix myMatrix;
    
    static void Init()
    {
        StProps.InitScope();

        AddFunction(_ZC("toString"),1,&ZMatrix::toString);
        AddFunction(_ZC("transpose"),1,&ZMatrix::ZTransport);
		AddFunction(_ZC("add"),2,&ZMatrix::Zadd);
		AddFunction(_ZC("Translate"),3,&ZMatrix::ZTranslate);
		AddFunction(_ZC("Scale"),3,&ZMatrix::ZScale);
		AddFunction(_ZC("Rotate"),3,&ZMatrix::ZRotateEuler);
		
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
		ZTMatrix myMatrix1= MATRIX_ZCONV(*(inp[0]));
		ZTvarp res=ZAlloc(ZTvar,1);
		*res = ZTMatrix(myMatrix1.val.transpose());
		return res;
    }
	
	ZTvarp ZTranslate(ZTvarS inp)
    {
		ZIFloat x= FLOAT_ZCONV(*(inp[0]));
		ZIFloat y= FLOAT_ZCONV(*(inp[1]));
		ZIFloat z= FLOAT_ZCONV(*(inp[2]));

		
		Eigen::Transform<float,3> t ;
		t.setIdentity();
		ZTvarp res=ZAlloc(ZTvar,1);
		t.translate(Eigen::Vector3f(-x,z,y));
		*res = ZTMatrix( t );
		return res;
    }

	ZTvarp ZScale(ZTvarS inp)
    {
		ZIFloat x= FLOAT_ZCONV(*(inp[0]));
		ZIFloat y= FLOAT_ZCONV(*(inp[1]));
		ZIFloat z= FLOAT_ZCONV(*(inp[2]));

		
		Eigen::Transform<float,3> t ;
		t.setIdentity();
		ZTvarp res=ZAlloc(ZTvar,1);
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
		t       = Eigen::AngleAxisf(-x*180/M_PI, Vector3f::UnitZ())
				* Eigen::AngleAxisf(z*180/M_PI, Vector3f::UnitY())
				* Eigen::AngleAxisf(y*180/M_PI, Vector3f::UnitZ());

		*res = ZTMatrix( t );
		return res;
    }

	static NxMat34 toNxMat( ZTMatrix zmx )
	{
		NxMat34 nxm;
		NxF32 d[4][4];
		for(int i=0;i<3;i++)
			for(int j=0;j<4;j++)
				d[i][j] = zmx.val(i,j);

		nxm.setRowMajor44(d);
		return nxm;
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