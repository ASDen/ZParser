class ZMorph    : public ModifierAPI<ZMorph>
{
public:

	Morph* primt;

	ZMorph()
	{}

	static void Init()
	{
		ModifierAPI<ZMorph>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Morph_Rate") ,1,&ZMorph::Morph_Rate);

		AddFunction(_ZC("toString") ,1,&ZMorph::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Morph : Amount = " << primt->Morph_Rate.val << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZMorph(ZTvarS inp)
	{
		ZPoint* zp3;
		ZAxis* za;
		pZObjP zins;
		ZBulgeType* zbut;
		bool CenterExists = false;

		//constructor inits
		switch(inp.size())
		{
		case 1:
			pZObjP zrsg = INSTANCE_ZCONV(*(inp[0]));
			Primitives pr = zrsg->getPrimtive();
			primt = new Morph( pr );
			break;

		case 2:
			break;

		default:
			ZError::Throw<ZBadConversionError>();
		}

		ZMorph();
	}

	ZTvarp Morph_Rate (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Morph_Rate.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Morph::Morph_Rate,*primt);
		
		return NULL;
	}
};