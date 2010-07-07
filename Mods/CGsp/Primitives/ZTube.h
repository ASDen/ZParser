class ZTube    : public PrimitiveAPI<ZTube>
{
public:

	Tube_3* primt;

	TubePropsD* tRadius1;
	TubePropsD* tRadius2;
	TubePropsD* tHeight;
	TubePropsI* tSideSegs;
	TubePropsI* tCapSegs;
	TubePropsI* tHeightSegs;

	ZTube()
	{}

	static void Init()
	{
		PrimitiveAPI<ZTube>::Init();

		StProps.InitScope();
		AddFunction(_ZC("Radius1") ,1,&ZTube::MFactory<TubePropsD,double,&ZTube::tRadius1>);
		AddFunction(_ZC("Radius2") ,1,&ZTube::MFactory<TubePropsD,double,&ZTube::tRadius2>);
		AddFunction(_ZC("Height") ,1,&ZTube::MFactory<TubePropsD,double,&ZTube::tHeight>);

		AddFunction(_ZC("SideSegs") ,1,&ZTube::MFactory<TubePropsI,int,&ZTube::tSideSegs>);
		AddFunction(_ZC("CapSegs") ,1,&ZTube::MFactory<TubePropsI,int,&ZTube::tCapSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZTube::MFactory<TubePropsI,int,&ZTube::tHeightSegs>);

		AddFunction(_ZC("toString"),0,&ZTube::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Tube : Radius1 = " << primt->radius1 << ", Radius2 = " << primt->radius2
		   << ", Height = " << primt->height << ", Side Segments = " << primt->side_Seg 
		   << ", Cap Segments = " << primt->cap_Seg << ", Height Segments = " << primt->height_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZTube(ZTvarS inp)
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
			primt = new Tube_3();
			break;
		case 2:
			primt = new Tube_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Tube_3( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Tube_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new Tube_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 7:
			primt = new Tube_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		tRadius1	= new TubePropsD(&Tube_3::radius1,primt,primt->radius1);
		tRadius2	= new TubePropsD(&Tube_3::radius2,primt,primt->radius2);
		tHeight		= new TubePropsD(&Tube_3::height,primt,primt->height);
		tSideSegs	= new TubePropsI(&Tube_3::side_Seg,primt,primt->side_Seg);
		tCapSegs	= new TubePropsI(&Tube_3::cap_Seg,primt,primt->cap_Seg);
		tHeightSegs = new TubePropsI(&Tube_3::height_Seg,primt,primt->height_Seg);

		
		primt->ApplyModifier(tRadius1);
		primt->ApplyModifier(tRadius2);
		primt->ApplyModifier(tHeight);
		primt->ApplyModifier(tSideSegs);
		primt->ApplyModifier(tCapSegs);
		primt->ApplyModifier(tHeightSegs);

		ZTube();
	}

	template<class T,class S,T* ZTube::*mod>
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