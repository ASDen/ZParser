class ZBevel    : public ModifierAPI<ZBevel>
{
public:

	Bevel* primt;

	ZBevel()
	{}

	static void Init()
	{
		ModifierAPI<ZBevel>::Init();

		StProps.InitScope();

		AddFunction(_ZC("FaceNumber") ,1,&ZBevel::FaceNumber);
		AddFunction(_ZC("ExtrudeAmount") ,1,&ZBevel::ExtrudeAmount);
		AddFunction(_ZC("OutlineAmount") ,1,&ZBevel::OutlineAmount);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZBevel(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 1:
			primt = new Bevel( INT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Bevel( INT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) );
			break;
		}
		ZBevel();
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<int>(INT_ZCONV(*(inp[0]))),&Bevel::Fnum,*primt);
		
		return NULL;
	}

	ZTvarp ExtrudeAmount (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->ExAmount.val;
			ZTvarp res = ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bevel::ExAmount,*primt);
		
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bevel::OutlineAmount,*primt);
		
		return NULL;
	}
};