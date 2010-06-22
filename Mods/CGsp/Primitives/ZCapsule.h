class ZCapsule    : public PrimitiveAPI<ZCapsule>
{
public:

	Capsule_3* primt;

	ZCapsule()
	{}

	static void Init()
	{
		PrimitiveAPI<ZCapsule>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZCapsule::Radius);
		AddFunction(_ZC("Height") ,1,&ZCapsule::Height);

		AddFunction(_ZC("SideSegs") ,1,&ZCapsule::SideSegs);
		AddFunction(_ZC("HeightSegs") ,1,&ZCapsule::HeightSegs);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZCapsule(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Capsule_3();
			break;
		case 2:
			primt = new Capsule_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Capsule_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Capsule_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) );
			break;
		case 5:
		default:
			primt = new Capsule_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZCapsule();
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
			ZTInt fr = primt->Segs;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->Segs = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp HeightSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->h_Segs;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->h_Segs = INT_ZCONV(*(inp[0]));
		return NULL;
	}
};