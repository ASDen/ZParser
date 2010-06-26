class ZSphere    : public PrimitiveAPI<ZSphere>
{
public:

	Sphere_3* primt;

	SpherePropsD* sRadius;
	SpherePropsI* sSideSegs;

	ZSphere()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSphere>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZSphere::MFactory<SpherePropsD,double,&ZSphere::sRadius>);

		AddFunction(_ZC("SideSegs") ,1,&ZSphere::MFactory<SpherePropsI,int,&ZSphere::sSideSegs>);

		AddFunction(_ZC("toString"),0,&ZSphere::toString);

	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Sphere : Radius = " << primt->radius << ", Segments = " << primt->Segs << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZSphere(ZTvarS inp)
	{
		int inputNumber = 0;
		bool PositionExists = false;

		if (inp.size() != 0)
		{
			inputNumber = inp.size() - 1;
			if (GET_ZTYPE(*(inp[inputNumber])) == ZETList)
			{
				inputNumber = inp.size();
				PositionExists = true;
			}

			else
			{
				inputNumber = inp.size() + 1;
			}
		}

		//constructor inits
		switch(inputNumber)
		{
		case 0:
		case 1:
			primt = new Sphere_3();
			break;
		case 2:
			primt = new Sphere_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Sphere_3( FLOAT_ZCONV(*inp[0]) , INT_ZCONV(*inp[1]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt);

		sRadius   = new SpherePropsD(&Sphere_3::radius,primt,primt->radius);
		sSideSegs = new SpherePropsI(&Sphere_3::Segs,primt,primt->Segs);

		
		primt->ApplyModifier(sRadius);
		primt->ApplyModifier(sSideSegs);

		ZSphere();
	}

	template<class T,class S,T* ZSphere::*mod>
	ZTvarp MFactory (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = (this->*mod)->PolyP.FrameValues[ZInterp::currentFrame];
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,(S)(FLOAT_ZCONV(*(inp[0]))),&T::PolyP,*(this->*mod) );
		return NULL;
	}
};