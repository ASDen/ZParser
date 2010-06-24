class ZTube    : public PrimitiveAPI<ZTube>
{
public:

	Tube_3* primt;

	ZTube()
	{}

	static void Init()
	{
		PrimitiveAPI<ZTube>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius1") ,1,&ZTube::Radius1);
		AddFunction(_ZC("Radius2") ,1,&ZTube::Radius2);
		AddFunction(_ZC("Height") ,1,&ZTube::Height);

		AddFunction(_ZC("SideSegs") ,1,&ZTube::SideSegs);
		AddFunction(_ZC("CapSegs") ,1,&ZTube::CapSegs);
		AddFunction(_ZC("HeightSegs") ,1,&ZTube::HeightSegs);

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
		//constructor inits
		switch(inp.size())
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
		InitNode(inp,primt);
		ZTube();
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

	ZTvarp CapSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->cap_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->cap_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp HeightSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->height_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->height_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}
};