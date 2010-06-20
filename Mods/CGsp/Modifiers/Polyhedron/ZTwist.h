class ZTwist    : public ModifierAPI<ZTwist>
{
public:

	Twist* primt;

	ZTwist()
	{}

	static void Init()
	{
		ModifierAPI<ZTwist>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Angle") ,1,&ZTwist::Angle);
		AddFunction(_ZC("Axis") ,1,&ZTwist::Axis);
		AddFunction(_ZC("Center") ,1,&ZTwist::Center);
		AddFunction(_ZC("Limited") ,1,&ZTwist::Limited);
		AddFunction(_ZC("Upper_Limit") ,1,&ZTwist::Upper_Limit);
		AddFunction(_ZC("Lower_Limit") ,1,&ZTwist::Lower_Limit);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZTwist(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Twist();
			break;
		case 1:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 4:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 5:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 6:
			primt = new Twist( FLOAT_ZCONV(*(inp[0])) );
			break;
		}
		ZTwist();
	}

	ZTvarp Angle (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->TwAngle.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Twist::TwAngle,*primt);
		
		std::cout<<primt->Center->y()<<std::endl;
		return NULL;
	}

	ZTvarp Axis (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->RoAxis;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		switch((int)(FLOAT_ZCONV(*(inp[0]))))
		{
		case 0:
			primt->RoAxis = X_ax;
			break;
		case 1:
			primt->RoAxis = Y_ax;
			break;
		case 2:
			primt->RoAxis = Z_ax;
			break;
		}
		return NULL;
	}
	
	ZTvarp Center (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			Point_3* fr = (primt->Center);
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(fr->x());
			zg[1] = ZTFloat(fr->y());
			zg[2] = ZTFloat(fr->z());

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZPoint (zvs); 
			*hv=zin;
			return hv;
		}
		else
		{
			pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
			primt->Center = reinterpret_cast<ZPoint*>(zins)->getPnt();
		}
		return NULL;
	}

	ZTvarp Limited (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTBool fr = primt->Limited;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->Limited = BOOL_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Upper_Limit (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Upper.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Twist::Upper,*primt);
		return NULL;
	}

	ZTvarp Lower_Limit (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Lower.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Twist::Lower,*primt);
		return NULL;
	}
};