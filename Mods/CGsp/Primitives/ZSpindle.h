class ZSpindle    : public PrimitiveAPI<ZSpindle>
{
public:

	Spindle_3* primt;

	SpindlePropsD* cRadius;
	SpindlePropsD* cCap;
	SpindlePropsD* cHeight;
	SpindlePropsI* cSideSegs;
	SpindlePropsI* cCapSegs;
	SpindlePropsI* cHeightSegs;

	ZSpindle()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSpindle>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZSpindle::MFactory<SpindlePropsD,double,&ZSpindle::cRadius>);
		AddFunction(_ZC("Cap") ,1,&ZSpindle::MFactory<SpindlePropsD,double,&ZSpindle::cCap>);
		AddFunction(_ZC("Height") ,1,&ZSpindle::MFactory<SpindlePropsD,double,&ZSpindle::cHeight>);

		AddFunction(_ZC("SideSegs") ,1,&ZSpindle::MFactory<SpindlePropsI,int,&ZSpindle::cSideSegs>);
		AddFunction(_ZC("CapSegs") ,1,&ZSpindle::MFactory<SpindlePropsI,int,&ZSpindle::cCapSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZSpindle::MFactory<SpindlePropsI,int,&ZSpindle::cHeightSegs>);

		AddFunction(_ZC("toString"),0,&ZSpindle::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Spindle : Radius = " << primt->radius << ", Cap = " << primt->cap_height
		   << ", Height = " << primt->height << ", Side Segments = " << primt->side_Seg 
		   << ", Cap Segments = " << primt->cap_Seg << ", Height Segments = " << primt->height_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZSpindle(ZTvarS inp)
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
			primt = new Spindle_3();
			break;

		case 2:
			primt = new Spindle_3( FLOAT_ZCONV(*(inp[0])) );
			break;

		case 3:
			primt = new Spindle_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;

		case 4:
			primt = new Spindle_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;

		case 5:
		case 6:
			primt = new Spindle_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;

		case 7:
			primt = new Spindle_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;

		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}

		primt->Draw();
		InitNode(inp,primt,PositionExists);

		cRadius		= new SpindlePropsD(&Spindle_3::radius,primt,primt->radius);
		cCap		= new SpindlePropsD(&Spindle_3::cap_height,primt,primt->cap_height);
		cHeight		= new SpindlePropsD(&Spindle_3::height,primt,primt->height);
		cSideSegs	= new SpindlePropsI(&Spindle_3::side_Seg,primt,primt->side_Seg);
		cCapSegs	= new SpindlePropsI(&Spindle_3::cap_Seg,primt,primt->cap_Seg);
		cHeightSegs = new SpindlePropsI(&Spindle_3::height_Seg,primt,primt->height_Seg);

		DoFor(cRadius);
		DoFor(cCap);
		DoFor(cHeight);
		DoFor(cSideSegs);
		DoFor(cCapSegs);
		DoFor(cHeightSegs);

		cHeightSegs->commit = true;

		ZSpindle();
	}
	
	template<class T,class S,T* ZSpindle::*mod>
	ZTvarp MFactory (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = (this->*mod)->PolyP.FrameValues[ZInterp::currentFrame];
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		if ( (this->*mod)->extrensic == true )
			DoFor( (this->*mod) );

		FrameCreater::FillFrames(ZInterp::currentFrame,(S)(FLOAT_ZCONV(*(inp[0]))),&T::PolyP,*(this->*mod) );
		(this->*mod)->CalcmxF();
		cHeightSegs->mxFrame = std::max( cHeightSegs->mxFrame , (this->*mod)->mxFrame );

		return NULL;
	}
};