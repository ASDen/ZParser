class ZSphere    : public PrimitiveAPI<ZSphere>
{
public:

	Sphere_3* primt;

	ZSphere()
	{}

	static void Init()
	{
		PrimitiveAPI<ZSphere>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius") ,1,&ZSphere::Radius);

		AddFunction(_ZC("SideSegs") ,1,&ZSphere::SideSegs);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZSphere(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Sphere_3();
			break;
		case 2:
			primt = new Sphere_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 7:
		default:
			primt = new Sphere_3( FLOAT_ZCONV(*inp[0]) , INT_ZCONV(*inp[1]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZSphere();
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
};