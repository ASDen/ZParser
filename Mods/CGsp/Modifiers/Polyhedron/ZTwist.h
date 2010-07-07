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

		AddFunction(_ZC("toString") ,1,&ZTwist::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Twist : Angle = " << primt->TwAngle.val << ", Axis = " << ZAxis::toString(primt->RoAxis) 
		   << ", Center = (" << primt->X_Center.val << ", " << primt->Y_Center.val << ", " << primt->Z_Center.val << ")" 
		   << ", Limited = " << primt->Limited << ", Upper_Limit = " << primt->Upper.val << ", Upper_Limit = " << primt->Lower.val << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZTwist(ZTvarS inp)
	{
		ZPoint* zp3;
		ZAxis* za;
		Point_3* p3;
		pZObjP zins;
		bool CenterExists = false;

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
			if ((za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[1])))) != NULL)
				primt = new Twist( FLOAT_ZCONV(*(inp[0])) , za->ax );
			else
				ZError::Throw<ZBadConversionError>();
			break;
		case 3:
			if ((zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
			{
				primt = new Twist( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax );
				CenterExists = true;
			}
			else
				ZError::Throw<ZBadConversionError>();
			break;
		case 4:
		case 5:
			if ((zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
			{
				primt = new Twist( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , BOOL_ZCONV(*(inp[3])) );
				CenterExists = true;
			}
			else
				ZError::Throw<ZBadConversionError>();
			break;
		case 6:
			if ((zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
			{
				primt = new Twist( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , BOOL_ZCONV(*(inp[3])) , INT_ZCONV(*(inp[4])) , INT_ZCONV(*(inp[5])) );
				CenterExists = true;
			}
			else
				ZError::Throw<ZBadConversionError>();
			break;
		}

		if (!CenterExists)
		{
			primt->X_Center.FrameValues[0]  = 0;
			primt->Y_Center.FrameValues[0]  = 0;
			primt->Z_Center.FrameValues[0]  = 0;
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
		
		return NULL;
	}

	ZTvarp Axis (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZAxis (primt->RoAxis); 
			*hv=zin;
			return hv;
		}

		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		primt->RoAxis = reinterpret_cast<ZAxis*>(zins)->ax;
		
		return NULL;
	}
	
	ZTvarp Center (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			//Point_3* fr = (primt->Center);
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(primt->X_Center.val);
			zg[1] = ZTFloat(primt->Y_Center.val);
			zg[2] = ZTFloat(primt->Z_Center.val);

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
			Point_3* p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();

			if(ZInterp::currentFrame == 0)
			{
				primt->X_Center.FrameValues[0]  = p3->x();
				primt->Y_Center.FrameValues[0]  = p3->y();
				primt->Z_Center.FrameValues[0]  = p3->z();
			}
			else
			{
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Twist::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Twist::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Twist::Z_Center,*primt);
			}
		}
		return NULL;
	}

	ZTvarp Limited (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTBool fr = primt->Limited;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTBool(fr);
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