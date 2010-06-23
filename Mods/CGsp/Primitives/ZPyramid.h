class ZPyramid    : public PrimitiveAPI<ZPyramid>
{
public:

	Pyramid_3* primt;

	ZPyramid()
	{}

	static void Init()
	{
		PrimitiveAPI<ZPyramid>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Depth") ,1,&ZPyramid::Depth);
		AddFunction(_ZC("Width") ,1,&ZPyramid::Width);
		AddFunction(_ZC("Height") ,1,&ZPyramid::Height);

		AddFunction(_ZC("DepthSegs") ,1,&ZPyramid::DepthSegs);
		AddFunction(_ZC("WidthSegs") ,1,&ZPyramid::WidthSegs);
		AddFunction(_ZC("HeightSegs") ,1,&ZPyramid::HeightSegs);

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
		//constructor inits
		switch(inp.size())
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
		InitNode(inp,primt);
		ZPyramid();
	}

	ZTvarp Depth (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->depth;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->depth = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Width (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->width;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->width = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp Height (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->height;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->height = FLOAT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp DepthSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->depth_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->depth_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp WidthSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->width_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->width_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}

	ZTvarp HeightSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->height_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->height_Seg = INT_ZCONV(*(inp[0]));
		return NULL;
	}
};