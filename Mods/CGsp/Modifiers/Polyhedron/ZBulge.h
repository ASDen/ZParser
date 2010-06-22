class ZBulge    : public ModifierAPI<ZBulge>
{
public:

	Bulge* primt;

	ZBulge()
	{}

	static void Init()
	{
		ModifierAPI<ZBulge>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Amount") ,1,&ZBulge::Amount);
		AddFunction(_ZC("Axis") ,1,&ZBulge::Axis);
		AddFunction(_ZC("Center") ,1,&ZBulge::Center);
		AddFunction(_ZC("Limited") ,1,&ZBulge::Limited);
		AddFunction(_ZC("Upper_Limit") ,1,&ZBulge::Upper_Limit);
		AddFunction(_ZC("Lower_Limit") ,1,&ZBulge::Lower_Limit);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZBulge(ZTvarS inp)
	{
		Point_3* p3;
		pZObjP zins;

		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Bulge();
			break;
		case 1:
			primt = new Bulge( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , ZBulgeType::getType((inp[1])) );
			break;
		case 3:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) );
			break;
		case 4:
		case 5:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) );
			break;
		case 6:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) , INT_ZCONV(*(inp[4])) , INT_ZCONV(*(inp[5])) );
			break;
		}
		ZBulge();
	}

	ZTvarp Amount (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->BuAmount.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bulge::BuAmount,*primt);
		
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
			primt->RoAxis = Axis::X_ax;
			break;
		case 1:
			primt->RoAxis = Axis::Y_ax;
			break;
		case 2:
			primt->RoAxis = Axis::Z_ax;
			break;
		}
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
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Bulge::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Bulge::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Bulge::Z_Center,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bulge::Upper,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Bulge::Lower,*primt);
		return NULL;
	}
};