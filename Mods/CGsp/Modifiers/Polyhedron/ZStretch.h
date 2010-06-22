class ZStretch    : public ModifierAPI<ZStretch>
{
public:

	Stretch* primt;

	ZStretch()
	{}

	static void Init()
	{
		ModifierAPI<ZStretch>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Amount") ,1,&ZStretch::Amount);
		AddFunction(_ZC("Axis") ,1,&ZStretch::Axis);
		AddFunction(_ZC("Center") ,1,&ZStretch::Center);
		AddFunction(_ZC("Limited") ,1,&ZStretch::Limited);
		AddFunction(_ZC("Upper_Limit") ,1,&ZStretch::Upper_Limit);
		AddFunction(_ZC("Lower_Limit") ,1,&ZStretch::Lower_Limit);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZStretch(ZTvarS inp)
	{
		Point_3* p3;
		pZObjP zins;

		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Stretch();
			break;
		case 1:
			primt = new Stretch( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 2:
			primt = new Stretch( FLOAT_ZCONV(*(inp[0])) , ZAxis::getAxis((inp[1])) );
			break;
		case 3:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Stretch( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) );
			break;
		case 4:
		case 5:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Stretch( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) );
			break;
		case 6:
			zins=INSTANCE_ZCONV(*(inp[1]));
			p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
			primt = new Stretch( FLOAT_ZCONV(*(inp[0])) , p3 , ZAxis::getAxis((inp[2])) , BOOL_ZCONV(*(inp[3])) , INT_ZCONV(*(inp[4])) , INT_ZCONV(*(inp[5])) );
			break;
		}
		ZStretch();
	}

	ZTvarp Amount (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->StAmount.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Stretch::StAmount,*primt);
		
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
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Stretch::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Stretch::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Stretch::Z_Center,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Stretch::Upper,*primt);
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Stretch::Lower,*primt);
		return NULL;
	}
};