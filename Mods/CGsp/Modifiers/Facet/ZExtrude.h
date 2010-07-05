class ZExtrude    : public ModifierAPI<ZExtrude>
{
public:

	Extrude* primt;

	ZExtrude()
	{}

	static void Init()
	{
		ModifierAPI<ZExtrude>::Init();

		StProps.InitScope();

		AddFunction(_ZC("FaceNumber") ,1,&ZExtrude::FaceNumber);
		AddFunction(_ZC("ExtrudeAmount") ,1,&ZExtrude::ExtrudeAmount);

		AddFunction(_ZC("toString"),0,&ZExtrude::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Extrude : Face Number = " << primt->Fnum.val << ", Extrude Amount = " << primt->ExAmount.val << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZExtrude(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 1:
			primt = new Extrude( INT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Extrude( INT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}

		ZExtrude();
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<int>(INT_ZCONV(*(inp[0]))),&Extrude::Fnum,*primt);
		
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Extrude::ExAmount,*primt);
		
		return NULL;
	}
};