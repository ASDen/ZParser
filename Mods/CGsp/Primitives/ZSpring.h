class ZSpring    : public PrimitiveAPI<ZSpring>
{
public:

	Spring_3* primt;

	ZSpring()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSpring>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius1") ,1,&ZSpring::Radius1);
		AddFunction(_ZC("Radius2") ,1,&ZSpring::Radius2);
		AddFunction(_ZC("Height") ,1,&ZSpring::Height);

		AddFunction(_ZC("SideSegs") ,1,&ZSpring::SideSegs);
		AddFunction(_ZC("Segs") ,1,&ZSpring::Segs);
		AddFunction(_ZC("TurnNumber") ,1,&ZSpring::TurnNumber);

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
		//constructor inits
		switch(inp.size())
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
		ZSpring();
	}

	ZTvarp Radius1 (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->radius1;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->radius1 = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Radius2 (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->radius2;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->radius2 = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Height (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->height;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->height = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp SideSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->side_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->side_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Segs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp TurnNumber (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->turn_number;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->turn_number = INT_ZCONV(*(inp[0]));
		return NULL;
	}
};