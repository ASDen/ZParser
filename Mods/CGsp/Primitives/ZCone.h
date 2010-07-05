class ZCone    : public PrimitiveAPI<ZCone>
{
public:

	Cone_3* primt;

	ConePropsD* cRadius1;
	ConePropsD* cRadius2;
	ConePropsD* cHeight;
	ConePropsI* cSideSegs;
	ConePropsI* cCapSegs;
	ConePropsI* cHeightSegs;

	ZCone()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCone>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius1") ,1,&ZCone::MFactory<ConePropsD,double,&ZCone::cRadius1>);
		AddFunction(_ZC("Radius2") ,1,&ZCone::MFactory<ConePropsD,double,&ZCone::cRadius2>);
		AddFunction(_ZC("Height") ,1,&ZCone::MFactory<ConePropsD,double,&ZCone::cHeight>);

		AddFunction(_ZC("SideSegs") ,1,&ZCone::MFactory<ConePropsI,int,&ZCone::cSideSegs>);
		AddFunction(_ZC("CapSegs") ,1,&ZCone::MFactory<ConePropsI,int,&ZCone::cCapSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZCone::MFactory<ConePropsI,int,&ZCone::cHeightSegs>);

		AddFunction(_ZC("toString"),0,&ZCone::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Cone : Radius1 = " << primt->radius1 << ", Radius2 = " << primt->radius2
		   << ", Height = " << primt->height <<", Side Segments = " << primt->side_Seg 
		   << ", Cap Segments = " << primt->cap_Seg << ", Height Segments = " << primt->height_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZCone(ZTvarS inp)
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
			primt = new Cone_3();
			break;
		case 2:
			primt = new Cone_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Cone_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Cone_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
		case 6:
			primt = new Cone_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 7:
			primt = new Cone_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		cRadius1	= new ConePropsD(&Cone_3::radius1,primt,primt->radius1);
		cRadius2	= new ConePropsD(&Cone_3::radius2,primt,primt->radius2);
		cHeight		= new ConePropsD(&Cone_3::height,primt,primt->height);
		cSideSegs	= new ConePropsI(&Cone_3::side_Seg,primt,primt->side_Seg);
		cCapSegs	= new ConePropsI(&Cone_3::cap_Seg,primt,primt->cap_Seg);
		cHeightSegs = new ConePropsI(&Cone_3::height_Seg,primt,primt->height_Seg);

		
		primt->ApplyModifier(cRadius1);
		primt->ApplyModifier(cRadius2);
		primt->ApplyModifier(cHeight);
		primt->ApplyModifier(cSideSegs);
		primt->ApplyModifier(cCapSegs);
		primt->ApplyModifier(cHeightSegs);

		ZCone();
	}

	template<class T,class S,T* ZCone::*mod>
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