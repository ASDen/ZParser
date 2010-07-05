class ZCapsule    : public PrimitiveAPI<ZCapsule>
{
public:

	Capsule_3* primt;

	CapsulePropsD* cRadius;
	CapsulePropsD* cHeight;
	CapsulePropsI* cSideSegs;
	CapsulePropsI* cHeightSegs;

	ZCapsule()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCapsule>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZCapsule::MFactory<CapsulePropsD,double,&ZCapsule::cRadius>);
		AddFunction(_ZC("Height") ,1,&ZCapsule::MFactory<CapsulePropsD,double,&ZCapsule::cHeight>);

		AddFunction(_ZC("SideSegs") ,1,&ZCapsule::MFactory<CapsulePropsI,int,&ZCapsule::cSideSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZCapsule::MFactory<CapsulePropsI,int,&ZCapsule::cHeightSegs>);

		AddFunction(_ZC("toString"),0,&ZCapsule::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Capsule : Radius = " << primt->radius << ", Height = " << primt->height
		   << ", Side Segments = " << primt->Segs << ", Height Segments = " << primt->h_Segs << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZCapsule(ZTvarS inp)
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
			primt = new Capsule_3();
			break;
		case 2:
			primt = new Capsule_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Capsule_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Capsule_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new Capsule_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		cRadius		= new CapsulePropsD(&Capsule_3::radius,primt,primt->radius);
		cHeight		= new CapsulePropsD(&Capsule_3::height,primt,primt->height);
		cSideSegs	= new CapsulePropsI(&Capsule_3::Segs,primt,primt->Segs);
		cHeightSegs = new CapsulePropsI(&Capsule_3::h_Segs,primt,primt->h_Segs);

		
		primt->ApplyModifier(cRadius);
		primt->ApplyModifier(cHeight);
		primt->ApplyModifier(cSideSegs);
		primt->ApplyModifier(cHeightSegs);

		ZCapsule();
	}

	template<class T,class S,T* ZCapsule::*mod>
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