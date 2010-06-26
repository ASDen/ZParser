class ZPlane    : public PrimitiveAPI<ZPlane>
{
public:

	Plane_3* primt;

	PlanePropsD* pWidth;
	PlanePropsD* pLength;
	PlanePropsI* pSWidth;
	PlanePropsI* pSLength;

	ZPlane()
	{}

	static void Init()
	{
		PrimitiveAPI<ZPlane>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Width")  ,1,&ZPlane::MFactory<PlanePropsD,double,&ZPlane::pWidth>);
		AddFunction(_ZC("Length") ,1,&ZPlane::MFactory<PlanePropsD,double,&ZPlane::pLength>);

		AddFunction(_ZC("WidthSegs") ,1,&ZPlane::MFactory<PlanePropsI,int,&ZPlane::pSWidth>);
		AddFunction(_ZC("LengthSegs") ,1,&ZPlane::MFactory<PlanePropsI,int,&ZPlane::pSLength>);

		AddFunction(_ZC("toString"),0,&ZPlane::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Plane : Width = " << primt->width << ", Length = " << primt->length
		   << ", Width Segments = " << primt->width_Seg << ", Length Segments = " << primt->length_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZPlane(ZTvarS inp)
	{
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
		case 0:
		case 1:
			primt = new Plane_3();
			break;
		case 2:
			primt = new Plane_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
		case 4:
			primt = new Plane_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 5:
			primt = new Plane_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , INT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt);

		pWidth   = new PlanePropsD(&Plane_3::width,primt,primt->width);
		pLength  = new PlanePropsD(&Plane_3::length,primt,primt->length);
		pSWidth  = new PlanePropsI(&Plane_3::width_Seg,primt,primt->width_Seg);
		pSLength = new PlanePropsI(&Plane_3::length_Seg,primt,primt->length_Seg);


		primt->ApplyModifier(pWidth);
		primt->ApplyModifier(pLength);
		primt->ApplyModifier(pSWidth);
		primt->ApplyModifier(pSLength);

		ZPlane();
	}

	template<class T,class S,T* ZPlane::*mod>
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
};