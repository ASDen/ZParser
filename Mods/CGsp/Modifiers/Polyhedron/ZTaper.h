class ZTaper    : public ModifierAPI<ZTaper>
{
public:

	Taper* primt;

	ZTaper()
	{}

	static void Init()
	{
		ModifierAPI<ZTaper>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Amount") ,1,&ZTaper::Amount);
		AddFunction(_ZC("Axis") ,1,&ZTaper::Axis);
		AddFunction(_ZC("Center") ,1,&ZTaper::Center);
		AddFunction(_ZC("Limited") ,1,&ZTaper::Limited);
		AddFunction(_ZC("Upper_Limit") ,1,&ZTaper::Upper_Limit);
		AddFunction(_ZC("Lower_Limit") ,1,&ZTaper::Lower_Limit);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZTaper(ZTvarS inp)
	{
		Point_3* p3;
		pZObjP zins;

		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Taper();
			break;
		case 1:
			primt = new Taper( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Taper( FLOAT_ZCONV(*(inp[0])) , ZAxis::getAxis((inp[1])) );
			break;
		case 3:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Taper( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) );
			break;
		case 4:
		case 5:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Taper( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) );
			break;
		case 6:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Taper( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) , INT_ZCONV(*(inp[4])) , INT_ZCONV(*(inp[5])) );
			break;
		}
		ZTaper();
	}

	ZTvarp Amount (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->TaAmount.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Taper::TaAmount,*primt);
		
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
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Taper::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Taper::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Taper::Z_Center,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Taper::Upper,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Taper::Lower,*primt);
		return NULL;
	}
};