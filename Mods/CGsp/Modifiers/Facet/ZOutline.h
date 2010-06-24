class ZOutline    : public ModifierAPI<ZOutline>
{
public:

	Outline* primt;

	ZOutline()
	{}

	static void Init()
	{
		ModifierAPI<ZOutline>::Init();

		StProps.InitScope();

		AddFunction(_ZC("FaceNumber") ,1,&ZOutline::FaceNumber);
		AddFunction(_ZC("OutlineAmount") ,1,&ZOutline::OutlineAmount);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZOutline(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 1:
			primt = new Outline( INT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Outline( INT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
			break;
		}
		ZOutline();
	}

	ZTvarp FaceNumber (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Fnum.val;
			ZTvarp res = ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<int>(INT_ZCONV(*(inp[0]))),&Outline::Fnum,*primt);
		
		return NULL;
	}

	ZTvarp OutlineAmount (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->OutlineAmount.val;
			ZTvarp res = ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Outline::OutlineAmount,*primt);
		
		return NULL;
	}
};