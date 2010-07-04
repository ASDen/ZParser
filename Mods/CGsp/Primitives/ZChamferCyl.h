class ZChamferCyl    : public PrimitiveAPI<ZChamferCyl>
{
public:

	ChamferCyl_3* primt;

	ChamferCylPropsD* cRadius;
	ChamferCylPropsD* cFillet;
	ChamferCylPropsD* cHeight;
	ChamferCylPropsI* cSideSegs;
	ChamferCylPropsI* cCapSegs;
	ChamferCylPropsI* cHeightSegs;
	ChamferCylPropsI* cFilletSegs;

	ZChamferCyl()
	{}

	static void Init()
	{
		PrimitiveAPI<ZChamferCyl>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZChamferCyl::MFactory<ChamferCylPropsD,double,&ZChamferCyl::cRadius>);
		AddFunction(_ZC("Fillet") ,1,&ZChamferCyl::MFactory<ChamferCylPropsD,double,&ZChamferCyl::cFillet>);
		AddFunction(_ZC("Height") ,1,&ZChamferCyl::MFactory<ChamferCylPropsD,double,&ZChamferCyl::cFillet>);

		AddFunction(_ZC("SideSegs") ,1,&ZChamferCyl::MFactory<ChamferCylPropsI,int,&ZChamferCyl::cSideSegs>);
		AddFunction(_ZC("CapSegs") ,1,&ZChamferCyl::MFactory<ChamferCylPropsI,int,&ZChamferCyl::cCapSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZChamferCyl::MFactory<ChamferCylPropsI,int,&ZChamferCyl::cHeightSegs>);
		AddFunction(_ZC("FilletSegs") ,1,&ZChamferCyl::MFactory<ChamferCylPropsI,int,&ZChamferCyl::cFilletSegs>);

		AddFunction(_ZC("toString"),0,&ZChamferCyl::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Chamfer Cylinder : Radius = " << primt->radius << ", Fillet = " << primt->fillet
		   << ", Height = " << primt->height << ", Side Segments = " << primt->side_Seg 
		   << ", Cap Segments = " << primt->cap_Seg <<", Height Segments = " << primt->height_Seg
		   << ", Fillet Segments = " << primt->fillet_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZChamferCyl(ZTvarS inp)
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
			primt = new ChamferCyl_3();
			break;
		case 2:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
		case 6:
		case 7:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 8:
			primt = new ChamferCyl_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) , INT_ZCONV(*inp[6]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		cRadius		= new ChamferCylPropsD(&ChamferCyl_3::radius,primt,primt->radius);
		cFillet		= new ChamferCylPropsD(&ChamferCyl_3::fillet,primt,primt->fillet);
		cHeight		= new ChamferCylPropsD(&ChamferCyl_3::height,primt,primt->height);
		cSideSegs	= new ChamferCylPropsI(&ChamferCyl_3::side_Seg,primt,primt->side_Seg);
		cCapSegs	= new ChamferCylPropsI(&ChamferCyl_3::cap_Seg,primt,primt->cap_Seg);
		cHeightSegs = new ChamferCylPropsI(&ChamferCyl_3::height_Seg,primt,primt->height_Seg);
		cFilletSegs = new ChamferCylPropsI(&ChamferCyl_3::fillet_Seg,primt,primt->fillet_Seg);

		
		primt->ApplyModifier(cRadius);
		primt->ApplyModifier(cFillet);
		primt->ApplyModifier(cHeight);
		primt->ApplyModifier(cSideSegs);
		primt->ApplyModifier(cCapSegs);
		primt->ApplyModifier(cHeightSegs);
		primt->ApplyModifier(cFilletSegs);

		ZChamferCyl();
	}

	template<class T,class S,T* ZChamferCyl::*mod>
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