class ZBox    : public PrimitiveAPI<ZBox>
{
public:

	Box_3* primt;

	ZBox()
	{}

	static void Init()
	{
		PrimitiveAPI<ZBox>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Length") ,1,&ZBox::Length);
		AddFunction(_ZC("Width") ,1,&ZBox::Width);
		AddFunction(_ZC("Height") ,1,&ZBox::Height);

		AddFunction(_ZC("LengthSegs") ,1,&ZBox::LengthSegs);
		AddFunction(_ZC("WidthSegs") ,1,&ZBox::WidthSegs);
		AddFunction(_ZC("HeightSegs") ,1,&ZBox::HeightSegs);

		AddFunction(_ZC("toString"),0,&ZBox::toString);
		
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Box : Width = " << primt->width << ", Length = "<<primt->length
		   << ", Height = " <<primt->height<<", Width Segments = " << primt->width_Seg 
		   << ", Length Segments = "<<primt->length_Seg <<", Height Segments = "<<primt->height_Seg<< endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZBox(ZTvarS inp)
	{
		//constructor inits
		switch(inp.size())
		{
		case 0:
		case 1:
			primt = new Box_3();
			break;
		case 2:
			primt = new Box_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
			primt = new Box_3( FLOAT_ZCONV(*(inp[0])) , INT_ZCONV(*(inp[1])) );
			break;
		case 4:
			primt = new Box_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) );
			break;
		case 5:
			primt = new Box_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) );
			break;
		case 6:
			primt = new Box_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) );
			break;
		case 7:
			primt = new Box_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , INT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt);
		ZBox();
	}

	ZTvarp Length (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = primt->length;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->length = FLOAT_ZCONV(*(inp[0]));
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

	ZTvarp LengthSegs (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTInt fr = primt->length_Seg;
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		primt->length_Seg = INT_ZCONV(*(inp[0]));
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