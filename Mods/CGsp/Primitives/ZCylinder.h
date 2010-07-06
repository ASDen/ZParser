class ZCylinder    : public PrimitiveAPI<ZCylinder>
{
public:

	Cylinder_3* primt;

	CylinderPropsD* cRadius;
	CylinderPropsD* cHeight;
	CylinderPropsI* cSideSegs;
	CylinderPropsI* cCapSegs;
	CylinderPropsI* cHeightSegs;

	ZCylinder()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCylinder>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZCylinder::MFactory<CylinderPropsD,double,&ZCylinder::cRadius>);
		AddFunction(_ZC("Height") ,1,&ZCylinder::MFactory<CylinderPropsD,double,&ZCylinder::cHeight>);

		AddFunction(_ZC("SideSegs") ,1,&ZCylinder::MFactory<CylinderPropsI,int,&ZCylinder::cSideSegs>);
		AddFunction(_ZC("CapSegs") ,1,&ZCylinder::MFactory<CylinderPropsI,int,&ZCylinder::cCapSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZCylinder::MFactory<CylinderPropsI,int,&ZCylinder::cHeightSegs>);

		AddFunction(_ZC("toString"),0,&ZCylinder::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Cylinder : Radius = " << primt->radius
		   << ", Height = " << primt->height <<", Side Segments = " << primt->side_Seg 
		   << ", Cap Segments = " << primt->cap_Seg << ", Height Segments = " << primt->height_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}
	//FIXME : int conversions
	ZCylinder(ZTvarS inp)
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
			primt = new Cylinder_3();
			break;
		case 2:
			primt = new Cylinder_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Cylinder_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
		case 5:
			primt = new Cylinder_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) );
			break;
		case 6:
			primt = new Cylinder_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		cRadius		= new CylinderPropsD(&Cylinder_3::radius,primt,primt->radius);
		cHeight		= new CylinderPropsD(&Cylinder_3::height,primt,primt->height);
		cSideSegs	= new CylinderPropsI(&Cylinder_3::side_Seg,primt,primt->side_Seg);
		cCapSegs	= new CylinderPropsI(&Cylinder_3::cap_Seg,primt,primt->cap_Seg);
		cHeightSegs = new CylinderPropsI(&Cylinder_3::height_Seg,primt,primt->height_Seg);

		
		primt->ApplyModifier(cRadius);
		primt->ApplyModifier(cHeight);
		primt->ApplyModifier(cSideSegs);
		primt->ApplyModifier(cCapSegs);
		primt->ApplyModifier(cHeightSegs);

		ZCylinder();
	}

	template<class T,class S,T* ZCylinder::*mod>
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