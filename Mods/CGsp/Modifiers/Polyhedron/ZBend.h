class ZBend    : public ModifierAPI<ZBend>
{
public:

	Bend* primt;

	ZBend()
	{}

	static void Init()
	{
		ModifierAPI<ZBend>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Angle") ,1,&ZBend::Angle);
		AddFunction(_ZC("Axis") ,1,&ZBend::Axis);
		AddFunction(_ZC("Center") ,1,&ZBend::Center);
		AddFunction(_ZC("Limited") ,1,&ZBend::Limited);
		AddFunction(_ZC("Upper_Limit") ,1,&ZBend::Upper_Limit);
		AddFunction(_ZC("Lower_Limit") ,1,&ZBend::Lower_Limit);

		AddFunction(_ZC("toString"),0,&ZBend::toString);
	
		ZTObject::Inheriet(StProps);
	}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Bend : Angle = " << primt->BeAngle.val << ", Axis = " << ZAxis::toString(primt->RoAxis) 
			<< ", Center = " << "NOT SET" << ", Limited = " << primt->Limited 
		   << ", Upper_Limit = " << primt->Upper.val << ", Upper_Limit = " << primt->Lower.val << endl;
		
		INST_TO_STR( s1.str() );
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZBend(ZTvarS inp)
	{
		Point_3* p3;
		pZObjP zins;

		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Bend();
			break;
		case 1:
			primt = new Bend( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Bend( FLOAT_ZCONV(*(inp[0])) , ZAxis::getAxis((inp[1])) );
			break;
		case 3:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Bend( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) );
			break;
		case 4:
		case 5:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Bend( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) );
			break;
		case 6:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Bend( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) , INT_ZCONV(*(inp[4])) , INT_ZCONV(*(inp[5])) );
			break;
		}
		ZBend();
	}

	ZTvarp Angle (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->BeAngle.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bend::BeAngle,*primt);
		
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
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Bend::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Bend::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Bend::Z_Center,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bend::Upper,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bend::Lower,*primt);
		return NULL;
	}
};