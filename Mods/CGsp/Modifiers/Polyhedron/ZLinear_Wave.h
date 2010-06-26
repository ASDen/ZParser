class ZLinear_Wave    : public ModifierAPI<ZLinear_Wave>
{
public:

	Linear_Wave* primt;

	ZLinear_Wave()
	{}

	static void Init()
	{
		ModifierAPI<ZLinear_Wave>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Amplitude") ,1,&ZLinear_Wave::Amplitude);
		AddFunction(_ZC("Wavelength") ,1,&ZLinear_Wave::Wavelength);
		AddFunction(_ZC("Phase") ,1,&ZLinear_Wave::Phase);
		AddFunction(_ZC("Axis") ,1,&ZLinear_Wave::Axis);
		AddFunction(_ZC("AFFAxis") ,1,&ZLinear_Wave::AFFAxis);
		AddFunction(_ZC("Center") ,1,&ZLinear_Wave::Center);

		AddFunction(_ZC("toString") ,1,&ZLinear_Wave::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Linear Wave : Amplitude = " << primt->Amplitude.val << ", Wavelength = " << primt->Wavelength.val 
			<< ", Phase = " << primt->Phase.val << ", Center = " << "NOT SET" 
			<< ", Axis = " << ZAxis::toString(primt->RoAxis) << ", Affected Axis = " << ZAxis::toString(primt->AfAxis) << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZLinear_Wave(ZTvarS inp)
	{
		ZPoint* zp3;
		Point_3* p3;
		ZAxis* za;
		ZAxis* zaf;
		pZObjP zins;
		bool CenterExists = false;

		//constructor inits
		switch(inp.size())
		{
		case 0:
			primt = new Linear_Wave();
			break;
		case 1:
			primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 2:
			switch( GET_ZTYPE(*(inp[1])) )
			{
			case ZETFloat:
				primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
				break;
			case ZETInstance:
				zins=INSTANCE_ZCONV(*(inp[1]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
				{
					primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() );	
					CenterExists = true;
				}
				else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
					primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , za->ax );
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
					primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) );
					break;
				case ZETInstance:
					zins=INSTANCE_ZCONV(*(inp[2]));
					if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
					{
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , zp3->getPnt() );	
						CenterExists = true;
					}
					else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , za->ax );
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
						if ( (zaf = dynamic_cast<ZAxis*>(zins)) != NULL)
						{
							primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , zaf->ax );
							CenterExists = true;
						}
						else 
							ZError::Throw<ZBadConversionError>();
					}
					else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
					{
						zins=INSTANCE_ZCONV(*(inp[2]));
						if ( (zaf = dynamic_cast<ZAxis*>(zins)) != NULL)
							primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , za->ax , zaf->ax );
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
			switch( GET_ZTYPE(*(inp[1])) )
			{
			case ZETFloat:
				switch( GET_ZTYPE(*(inp[2])) )
				{
				case ZETFloat:
					if( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
					{
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , zp3->getPnt() );
						CenterExists = true;
					}
					else if ( (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , za->ax );
					else 
						ZError::Throw<ZBadConversionError>();
					break;
				case ZETInstance:
					zins=INSTANCE_ZCONV(*(inp[2]));
					if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
					{
						zins=INSTANCE_ZCONV(*(inp[3]));
						if ( (zaf = dynamic_cast<ZAxis*>(zins)) != NULL)
						{
							primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , zp3->getPnt() , zaf->ax );
							CenterExists = true;
						}
						else 
							ZError::Throw<ZBadConversionError>();
					}
					else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
					{
						zins=INSTANCE_ZCONV(*(inp[3]));
						if ( (zaf = dynamic_cast<ZAxis*>(zins)) != NULL)
							primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , za->ax , zaf->ax );
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

			case ZETInstance:
				zins=INSTANCE_ZCONV(*(inp[1]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
				{
					if ( (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL && (zaf = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[3])))) != NULL)
					{
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , zp3->getPnt() , za->ax , zaf->ax );
						CenterExists = true;
					}
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
			switch( GET_ZTYPE(*(inp[2])) )
			{
			case ZETFloat:
				zins=INSTANCE_ZCONV(*(inp[3]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
				{
					zins=INSTANCE_ZCONV(*(inp[4]));
					if ( (zaf = dynamic_cast<ZAxis*>(zins)) != NULL)
					{
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , zp3->getPnt() , zaf->ax );
						CenterExists = true;
					}
					else 
						ZError::Throw<ZBadConversionError>();
				}
				else if ( (za = dynamic_cast<ZAxis*>(zins)) != NULL)
				{
					zins=INSTANCE_ZCONV(*(inp[4]));
					if ( (zaf = dynamic_cast<ZAxis*>(zins)) != NULL)
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , za->ax , zaf->ax );
					else 
						ZError::Throw<ZBadConversionError>();
				}
				else 
					ZError::Throw<ZBadConversionError>();
				break;

			case ZETInstance:
				zins=INSTANCE_ZCONV(*(inp[2]));
				if( (zp3 = dynamic_cast<ZPoint*>(zins)) != NULL)
				{
					if ( (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[3])))) != NULL && (zaf = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[4])))) != NULL)
					{
						primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , zp3->getPnt() , za->ax , zaf->ax );
						CenterExists = true;
					}
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

		case 6:
			if ( (zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[3])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[4])))) != NULL && (zaf = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[5])))) != NULL)
			{
				primt = new Linear_Wave( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) , FLOAT_ZCONV(*(inp[2])) , zp3->getPnt() , za->ax , zaf->ax );
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

		ZLinear_Wave();
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Linear_Wave::Amplitude,*primt);
		
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Linear_Wave::Wavelength,*primt);
		
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

		FrameCreater::FillFrames(ZInterp::currentFrame,static_cast<double>(FLOAT_ZCONV(*(inp[0]))),&Linear_Wave::Phase,*primt);
		
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

	ZTvarp AFFAxis (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->AfAxis;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		switch((int)(FLOAT_ZCONV(*(inp[0]))))
		{
		case 0:
			primt->AfAxis = Axis::X_ax;
			break;
		case 1:
			primt->AfAxis = Axis::Y_ax;
			break;
		case 2:
			primt->AfAxis = Axis::Z_ax;
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
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->x(),&Linear_Wave::X_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->y(),&Linear_Wave::Y_Center,*primt);
				FrameCreater::FillFrames(ZInterp::currentFrame,p3->z(),&Linear_Wave::Z_Center,*primt);
			}
		}
		return NULL;
	}
};