class ZPlane    : public PrimitiveAPI<ZPlane>
{
public:

	Plane_3* primt;

	ZPlane()
	{}

	static void Init()
	{
		PrimitiveAPI<ZPlane>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Length") ,1,&ZPlane::Length);
		AddFunction(_ZC("Width") ,1,&ZPlane::Width);

		AddFunction(_ZC("LengthSegs") ,1,&ZPlane::LengthSegs);
		AddFunction(_ZC("WidthSegs") ,1,&ZPlane::WidthSegs);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZPlane(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Plane_3();
			break;
		case 2:
			primt = new Plane_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Plane_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 5:
		default:
			primt = new Plane_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZPlane();
	}
	
	ZTvarp Length (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->length;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->length = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Width (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->width;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->width = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp LengthSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->length_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->length_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp WidthSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->width_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->width_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}
};