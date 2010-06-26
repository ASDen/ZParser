class ZChamferCyl    : public PrimitiveAPI<ZChamferCyl>
{
public:

	ChamferCyl_3* primt;

	ZChamferCyl()
	{}

	static void Init()
	{
		PrimitiveAPI<ZChamferCyl>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZChamferCyl::Radius);
		AddFunction(_ZC("Fillet") ,1,&ZChamferCyl::Fillet);
		AddFunction(_ZC("Height") ,1,&ZChamferCyl::Height);

		AddFunction(_ZC("SideSegs") ,1,&ZChamferCyl::SideSegs);
		AddFunction(_ZC("CapSegs") ,1,&ZChamferCyl::CapSegs);
		AddFunction(_ZC("HeightSegs") ,1,&ZChamferCyl::HeightSegs);
		AddFunction(_ZC("FilletSegs") ,1,&ZChamferCyl::FilletSegs);

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
		//constructor inits
		switch(inp.size())
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
		InitNode(inp,primt);
		ZChamferCyl();
	}

	ZTvarp Radius (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->radius;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->radius = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Fillet (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->fillet;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->fillet = FLOAT_ZCONV(*(inp[0]));
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

	ZTvarp FilletSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->fillet_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->fillet_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}
};