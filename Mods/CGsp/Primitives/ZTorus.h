class ZTorus    : public PrimitiveAPI<ZTorus>
{
public:

	Torus_3* primt;

	ZTorus()
	{}

	static void Init()
	{
		PrimitiveAPI<ZTorus>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius1") ,1,&ZTorus::Radius1);
		AddFunction(_ZC("Radius2") ,1,&ZTorus::Radius2);
		AddFunction(_ZC("Rotation") ,1,&ZTorus::Rotation);
		AddFunction(_ZC("Twist") ,1,&ZTorus::Twist);

		AddFunction(_ZC("SideSegs") ,1,&ZTorus::SideSegs);
		AddFunction(_ZC("Segs") ,1,&ZTorus::Segs);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	//FIXME : int conversions
	ZTorus(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Torus_3();
			break;
		case 2:
			primt = new Torus_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Torus_3( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
			break;
		case 7:
			primt = new Torus_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , FLOAT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZTorus();
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

	ZTvarp Rotation (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->rotation;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->rotation = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Twist (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->twist;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->twist = FLOAT_ZCONV(*(inp[0]));
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
};