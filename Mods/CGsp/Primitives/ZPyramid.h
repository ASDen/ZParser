class ZPyramid    : public PrimitiveAPI<ZPyramid>
{
public:

	Pyramid_3* primt;

	PyramidPropsD* pWidth;
	PyramidPropsD* pHeight;
	PyramidPropsD* pDepth;
	PyramidPropsI* pSWidth;
	PyramidPropsI* pSHeight;
	PyramidPropsI* pSDepth;

	ZPyramid()
	{}

	static void Init()
	{
		PrimitiveAPI<ZPyramid>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Depth") ,1,&ZPyramid::MFactory<PyramidPropsD,double,&ZPyramid::pDepth>);
		AddFunction(_ZC("Width")  ,1,&ZPyramid::MFactory<PyramidPropsD,double,&ZPyramid::pWidth>);
		AddFunction(_ZC("Height") ,1,&ZPyramid::MFactory<PyramidPropsD,double,&ZPyramid::pHeight>);

		AddFunction(_ZC("DepthSegs") ,1,&ZPyramid::MFactory<PyramidPropsI,int,&ZPyramid::pSDepth>);
		AddFunction(_ZC("WidthSegs") ,1,&ZPyramid::MFactory<PyramidPropsI,int,&ZPyramid::pSWidth>);
		AddFunction(_ZC("HeightSegs") ,1,&ZPyramid::MFactory<PyramidPropsI,int,&ZPyramid::pSHeight>);

		AddFunction(_ZC("toString"),0,&ZPyramid::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Pyramid : Width = " << primt->width << ", Depth = " << primt->depth 
		   << ", Height = " << primt->height << ", Width Segments = " << primt->width_Seg 
		   << ", Depth Segments = " << primt->depth_Seg << ", Height Segments = " << primt->height_Seg<< endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZPyramid(ZTvarS inp)
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
			primt = new Pyramid_3();
			break;
		case 2:
			primt = new Pyramid_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Pyramid_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 6:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) );
			break;
		case 7:
			primt = new Pyramid_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt,PositionExists);

		pWidth   = new PyramidPropsD(&Pyramid_3::width,primt,primt->width);
		pHeight  = new PyramidPropsD(&Pyramid_3::height,primt,primt->height);
		pDepth   = new PyramidPropsD(&Pyramid_3::depth,primt,primt->depth);
		pSWidth  = new PyramidPropsI(&Pyramid_3::width_Seg,primt,primt->width_Seg);
		pSHeight = new PyramidPropsI(&Pyramid_3::height_Seg,primt,primt->height_Seg);
		pSDepth	 = new PyramidPropsI(&Pyramid_3::depth_Seg,primt,primt->depth_Seg);

		
		primt->ApplyModifier(pWidth);
		primt->ApplyModifier(pHeight);
		primt->ApplyModifier(pDepth);
		primt->ApplyModifier(pSWidth);
		primt->ApplyModifier(pSHeight);
		primt->ApplyModifier(pSDepth);

		ZPyramid();
	}

	template<class T,class S,T* ZPyramid::*mod>
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