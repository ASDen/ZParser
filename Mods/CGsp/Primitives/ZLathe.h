class ZLathe    : public PrimitiveAPI<ZLathe>
{
public:

	Lathe_3* primt;

	LathePropsD* lAngle;
	LathePropsI* lSideSegs;

	ZLathe()
	{
	}

	static void Init()
	{
		PrimitiveAPI<ZBox>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Angle")  ,1,&ZLathe::MFactory<LathePropsD,double,&ZLathe::lAngle>);
		AddFunction(_ZC("SideSegs") ,1,&ZLathe::MFactory<LathePropsI,int,&ZLathe::lSideSegs>);

		AddFunction(_ZC("Axis") ,1,&ZLathe::Axis);
		AddFunction(_ZC("Center") ,1,&ZLathe::Center);

		AddFunction(_ZC("toString"),0,&ZLathe::toString);
		
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;

		ZTList zl = VECTORtoLIST(primt->Arr_Points);

		s1 << " Lathe : Points = " << endl << boost::apply_visitor(ToString(),ZTvar(zl)) << endl << ", Angle = " << primt->R_Angle << ", Axis = "<< ZAxis::toString(primt->R_Axis)
			<< ", Side Segments = " << primt->Seg << ", Center = " << ZPoint::toString(*primt->Center) << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZLathe(ZTvarS inp)
	{
		ZPoint* zp3;
		ZAxis* za;
		int inputNumber = 0;
		bool PositionExists = false;

		if (inp.size() != 0)
		{
			inputNumber = inp.size() - 1;
			if (GET_ZTYPE(*(inp[inputNumber])) == ZETList)
			{
				inputNumber = inp.size();
				PositionExists = true;
			}

			else
			{
				inputNumber = inp.size() + 1;
			}
		}

		//constructor inits
		switch(inputNumber)
		{
		case 6:
			if ((zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp[1])))) != NULL && (za = dynamic_cast<ZAxis*>(INSTANCE_ZCONV(*(inp[2])))) != NULL)
			{
				std::vector<Point_3> P = LISTtoVECTOR(LIST_ZCONV(*inp[0]));
				if (P.size() != 0)
					primt = new Lathe_3( LISTtoVECTOR(LIST_ZCONV(*inp[0])) , zp3->getPnt() , za->ax , INT_ZCONV(*inp[3]) , FLOAT_ZCONV(*inp[4]));
				else
					ZError::Throw<ZBadConversionError>();
			}
			else
				ZError::Throw<ZBadConversionError>();
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		lAngle    = new LathePropsD(&Lathe_3::R_Angle,primt,primt->R_Angle);
		lSideSegs = new LathePropsI(&Lathe_3::Seg,primt,primt->Seg);

		
		primt->ApplyModifier(lAngle);
		primt->ApplyModifier(lSideSegs);

		ZLathe();
	}

	std::vector<Point_3> LISTtoVECTOR (ZTList inp)
	{
		ZPoint* zp3;
		std::vector<Point_3> Points;

		for (int i = 0; i < inp.size(); i++)
		{
			if ((zp3 = dynamic_cast<ZPoint*>(INSTANCE_ZCONV(*(inp.Get(i))))) != NULL)
				Points.push_back((*zp3->getPnt()));
		}

		return Points;
	}

	ZTList VECTORtoLIST (std::vector<Point_3> inp)
	{
		ZTList zl;

		for (int i = 0; i < inp.size(); i++)
		{
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(inp[i].x());
			zg[1] = ZTFloat(inp[i].y());
			zg[2] = ZTFloat(inp[i].z());

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);

			zin.val = new ZPoint (zvs);
			*hv=zin;
			zl.Append(hv);
		}

		return zl;
	}

	template<class T,class S,T* ZLathe::*mod>
	ZTvarp MFactory (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = (this->*mod)->PolyP.FrameValues[ZInterp::currentFrame];
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		FrameCreater::FillFrames(ZInterp::currentFrame,(S)(FLOAT_ZCONV(*(inp[0]))),&T::PolyP,*(this->*mod) );
		return NULL;
	}

	ZTvarp Axis (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZAxis (primt->R_Axis); 
			*hv=zin;
			return hv;
		}

		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		primt->R_Axis = reinterpret_cast<ZAxis*>(zins)->ax;
		
		return NULL;
	}
	
	ZTvarp Center (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(primt->Center->x());
			zg[1] = ZTFloat(primt->Center->y());
			zg[2] = ZTFloat(primt->Center->z());

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);

			zin.val = new ZPoint (zvs);
			*hv=zin;

			return hv;
		}

		pZObjP zins = INSTANCE_ZCONV(*(inp[0]));
		primt->Center = reinterpret_cast<ZPoint*>(zins)->getPnt();
		
		return NULL;
	}
};