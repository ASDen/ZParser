class ZSpring    : public PrimitiveAPI<ZSpring>
{
public:

	Spring_3* primt;

	SpringPropsD* sRadius1;
	SpringPropsD* sRadius2;
	SpringPropsD* sHeight;
	SpringPropsI* sSideSegs;
	SpringPropsI* sHeightSegs;
	SpringPropsI* sTurnNumber;

	ZSpring()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSpring>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius1") ,1,&ZSpring::MFactory<SpringPropsD,double,&ZSpring::sRadius1>);
		AddFunction(_ZC("Radius2") ,1,&ZSpring::MFactory<SpringPropsD,double,&ZSpring::sRadius2>);
		AddFunction(_ZC("Height") ,1,&ZSpring::MFactory<SpringPropsD,double,&ZSpring::sHeight>);

		AddFunction(_ZC("SideSegs") ,1,&ZSpring::MFactory<SpringPropsI,int,&ZSpring::sSideSegs>);
		AddFunction(_ZC("HeightSegs") ,1,&ZSpring::MFactory<SpringPropsI,int,&ZSpring::sHeightSegs>);
		AddFunction(_ZC("TurnNumber") ,1,&ZSpring::MFactory<SpringPropsI,int,&ZSpring::sTurnNumber>);

		AddFunction(_ZC("toString"),0,&ZSpring::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Spring : Radius1 = " << primt->radius1 << ", Radius2 = " << primt->radius2
		   << ", Height = " << primt->height << ", Side Segments = " << primt->side_Seg 
		   << ", Height Segments = " << primt->Seg << ", Turns Number = " << primt->turn_number << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZSpring(ZTvarS inp)
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
			primt = new Spring_3();
			break;
		case 2:
			primt = new Spring_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Spring_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Spring_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
		case 6:
			primt = new Spring_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 7:
			primt = new Spring_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt);

		sRadius1	= new SpringPropsD(&Spring_3::radius1,primt,primt->radius1);
		sRadius2	= new SpringPropsD(&Spring_3::radius2,primt,primt->radius2);
		sHeight		= new SpringPropsD(&Spring_3::height,primt,primt->height);
		sSideSegs	= new SpringPropsI(&Spring_3::side_Seg,primt,primt->side_Seg);
		sHeightSegs = new SpringPropsI(&Spring_3::Seg,primt,primt->Seg);
		sTurnNumber	= new SpringPropsI(&Spring_3::turn_number,primt,primt->turn_number);

		
		primt->ApplyModifier(sRadius1);
		primt->ApplyModifier(sRadius2);
		primt->ApplyModifier(sHeight);
		primt->ApplyModifier(sSideSegs);
		primt->ApplyModifier(sHeightSegs);
		primt->ApplyModifier(sTurnNumber);

		ZSpring();
	}

	template<class T,class S,T* ZSpring::*mod>
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