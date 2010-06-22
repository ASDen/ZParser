class ZSmooth    : public ModifierAPI<ZSmooth>
{
public:

	Smooth* primt;

	ZSmooth()
	{}

	static void Init()
	{
		ModifierAPI<ZSmooth>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Degree") ,1,&ZSmooth::Degree);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZSmooth(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Smooth();
			break;
		case 1:
			primt = new Smooth( FLOAT_ZCONV(*(inp[0])) );
			break;
		}
		ZSmooth();
	}

	ZTvarp Degree (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->S_Deg.val;
			ZTvarp res = ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<int>(INT_ZCONV(*(inp[0]))),&Smooth::S_Deg,*primt);
		
		return NULL;
	}
};