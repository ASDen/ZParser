class ZCylindrical_Wave    : public ModifierAPI<ZCylindrical_Wave>
{
public:

	Cylindrical_Wave* primt;

	ZCylindrical_Wave()
	{}

	static void Init()
	{
		ModifierAPI<ZCylindrical_Wave>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Amplitude") ,1,&ZCylindrical_Wave::Amplitude);
		AddFunction(_ZC("Wavelength") ,1,&ZCylindrical_Wave::Wavelength);
		AddFunction(_ZC("Phase") ,1,&ZCylindrical_Wave::Phase);
		AddFunction(_ZC("Axis") ,1,&ZCylindrical_Wave::Axis);
		AddFunction(_ZC("Center") ,1,&ZCylindrical_Wave::Center);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	//FIXME : int conversions
	ZCylindrical_Wave(ZTvarS inp)
	{
		ZPoint* zp3;
		ZAxis* za;
		pZObjP zins;

		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Cylindrical_Wave();
			break;

		case 1:
			primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) );
			break;

		case 2:
			switch( GET_ZTYPE(*(inp[1])) )
			{
			case ZETFloat:
				primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
				break;
			case ZETInstance:
				zins=INSTANCE_ZCONV(*(inp[1]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
					primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() );
				else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
					primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , za->ax );
				else ZError::Throw<ZBadConversionError>();
				break;
			default:
				ZError::Throw<ZBadConversionError>();
			}
			break;

		case 3:
			switch( GET_ZTYPE(*(inp[1])) )
			{
			case ZETFloat:
				switch( GET_ZTYPE(*(inp[2])) )
				{
				case ZETFloat:
					primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) );
					break;
				case ZETInstance:
					zins=INSTANCE_ZCONV(*(inp[2]));
					if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
						primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , zp3->getPnt() );
					else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
						primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , za->ax );
					else ZError::Throw<ZBadConversionError>();
					break;
				default:
					ZError::Throw<ZBadConversionError>();
				}
				break;

			case ZETInstance:
				switch( GET_ZTYPE(*(inp[2])) )
				{
				case ZETInstance:
					zins=INSTANCE_ZCONV(*(inp[1]));
					if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
					{
						zins=INSTANCE_ZCONV(*(inp[2]));
						if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
							primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax );
						else 
							ZError::Throw<ZBadConversionError>();
					}
					else 
						ZError::Throw<ZBadConversionError>();
					break;
				default:
					ZError::Throw<ZBadConversionError>();
				}
				break;

			default:
				ZError::Throw<ZBadConversionError>();
			}
			break;

		case 4:
			switch( GET_ZTYPE(*(inp[2])) )
			{
			case ZETFloat:
				zins=INSTANCE_ZCONV(*(inp[3]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
					primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , zp3->getPnt() );
				else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
					primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , za->ax );
				else 
					ZError::Throw<ZBadConversionError>();
				break;

			case ZETInstance:
				zins=INSTANCE_ZCONV(*(inp[2]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
				{
					if ( (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
						primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , zp3->getPnt() , za->ax );

					else
						ZError::Throw<ZBadConversionError>();
				}
				else 
					ZError::Throw<ZBadConversionError>();
				break;

			default:
				ZError::Throw<ZBadConversionError>();
			}
			break;

		case 5:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[3])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[4])))) != NULL)
				primt = new Cylindrical_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , zp3->getPnt() , za->ax );
			break;
		}
		ZCylindrical_Wave();
	}

	ZTvarp Amplitude (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Amplitude.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Cylindrical_Wave::Amplitude,*primt);
		
		return NULL;
	}

	ZTvarp Wavelength (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Wavelength.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Cylindrical_Wave::Wavelength,*primt);
		
		return NULL;
	}

	ZTvarp Phase (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->Phase.val;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Cylindrical_Wave::Phase,*primt);
		
		return NULL;
	}

	ZTvarp Axis (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZAxis (primt->AfAxis); 
			*hv=zin;
			return hv;
		}

		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		primt->AfAxis = reinterpret_cast<ZAxis*>(zins)->ax;
		
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
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Cylindrical_Wave::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Cylindrical_Wave::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Cylindrical_Wave::Z_Center,*primt);
			}
		}
		return NULL;
	}
};