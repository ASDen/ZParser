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
		AddFunction(_ZC("Type") ,1,&ZBulge::Type);
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
		ZPoint* zp3;
		ZAxis* za;
		pZObjP zins;
		ZBulgeType* zbut;

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
			switch( GET_ZTYPE(*(inp[1])) )
			{
			case ZETInstance:
				zins=INSTANCE_ZCONV(*(inp[1]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
					primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() );
				else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
					primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , za->ax );
				else if ( (zbut = dynamic_cast<ZBulgeType*>(zins)) != NULL)
					primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zbut->buType );
				else 
					ZError::Throw<ZBadConversionError>();
				break;
			default:
				ZError::Throw<ZBadConversionError>();
			}
			break;

		case 3:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
				primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax );
			else
				ZError::Throw<ZBadConversionError>();
			break;

		case 4:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
			{
			switch( GET_ZTYPE(*(inp[3])) )
			{
			case ZETBool:
				primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , BOOL_ZCONV(*(inp[3])) );
				break;
			case ZETInstance:
				if ( (zbut = dynamic_cast<ZBulgeType*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
					primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , zbut->buType );
				else
					ZError::Throw<ZBadConversionError>();
				break;
			default:
				ZError::Throw<ZBadConversionError>();
			}
			}
			else
				ZError::Throw<ZBadConversionError>();
			break;
		case 5:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL && (zbut = dynamic_cast<ZBulgeType*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
				primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , zbut->buType , BOOL_ZCONV(*(inp[4])) );
			else
				ZError::Throw<ZBadConversionError>();
			break;
		case 6:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
				primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , BOOL_ZCONV(*(inp[3])) , FLOAT_ZCONV(*(inp[4])) , FLOAT_ZCONV(*(inp[5])) );
			else
				ZError::Throw<ZBadConversionError>();
			break;
		case 7:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL && (zbut = dynamic_cast<ZBulgeType*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
				primt = new Bulge( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , zbut->buType , BOOL_ZCONV(*(inp[4])) , FLOAT_ZCONV(*(inp[5])) , FLOAT_ZCONV(*(inp[6])) );
			else
				ZError::Throw<ZBadConversionError>();
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

	ZTvarp Type (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZBulgeType (primt->BuType); 
			*hv=zin;
			return hv;
		}

		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		primt->BuType = reinterpret_cast<ZBulgeType*>(zins)->buType;
		
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