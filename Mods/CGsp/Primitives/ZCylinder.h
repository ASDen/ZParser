class ZCylinder    : public PrimitiveAPI<ZCylinder>
{
public:

	Cylinder_3* primt;

	ZCylinder()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCylinder>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZCylinder::Radius);
		AddFunction(_ZC("Height") ,1,&ZCylinder::Height);

		AddFunction(_ZC("SideSegs") ,1,&ZCylinder::SideSegs);
		AddFunction(_ZC("CapSegs") ,1,&ZCylinder::CapSegs);
		AddFunction(_ZC("HeightSegs") ,1,&ZCylinder::HeightSegs);

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
		//constructor inits
		switch(inp.size())
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
		InitNode(inp,primt);
		ZCylinder();
	}

	ZTvarp Radius (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->radius;
			ZTvarp res = ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->radius = FLOAT_ZCONV(*(inp[0]));
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