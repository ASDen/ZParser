class ZSpherify    : public ModifierAPI<ZSpherify>
{
public:

	Spherify* primt;

	ZSpherify()
	{}

	static void Init()
	{
		ModifierAPI<ZSpherify>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Amount") ,1,&ZSpherify::Amount);

		AddFunction(_ZC("toString") ,1,&ZSpherify::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Spherify : Amount = " << primt->SphAmount.val << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZSpherify(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Spherify();
			break;
		case 1:
			primt = new Spherify( FLOAT_ZCONV(*(inp[0])) );
			break;
		}

		ZSpherify();
	}

	ZTvarp Amount (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->SphAmount.val;
			ZTvarp res = ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Spherify::SphAmount,*primt);
		
		return NULL;
	}
};