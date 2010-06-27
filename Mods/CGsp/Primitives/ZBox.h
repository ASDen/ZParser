class ZBox    : public PrimitiveAPI<ZBox>
{
public:

	Box_3* primt;

	BoxPropsD* bWidth;
	BoxPropsD* bHeight;
	BoxPropsD* bLength;
	BoxPropsI* bSWidth;
	BoxPropsI* bSHeight;
	BoxPropsI* bSLength;

	ZBox()
	{
	}

	static void Init()
	{
		PrimitiveAPI<ZBox>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Length") ,1,&ZBox::MFactory<BoxPropsD,double,&ZBox::bLength>);
		AddFunction(_ZC("Width")  ,1,&ZBox::MFactory<BoxPropsD,double,&ZBox::bWidth>);
		AddFunction(_ZC("Height") ,1,&ZBox::MFactory<BoxPropsD,double,&ZBox::bHeight>);

		AddFunction(_ZC("LengthSegs") ,1,&ZBox::MFactory<BoxPropsI,int,&ZBox::bSLength>);
		AddFunction(_ZC("WidthSegs") ,1,&ZBox::MFactory<BoxPropsI,int,&ZBox::bSWidth>);

		AddFunction(_ZC("HeightSegs") ,1,&ZBox::MFactory<BoxPropsI,int,&ZBox::bSHeight>);

		AddFunction(_ZC("toString"),0,&ZBox::toString);
		
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Box : Width = " << primt->width << ", Length = "<< primt->length
		   << ", Height = " << primt->height<<", Width Segments = " << primt->width_Seg 
		   << ", Length Segments = " << primt->length_Seg << ", Height Segments = " << primt->height_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZBox(ZTvarS inp)
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

		InitNode(inp,primt,PositionExists);

		bWidth   = new BoxPropsD(&Box_3::width,primt,primt->width);
		bHeight  = new BoxPropsD(&Box_3::height,primt,primt->height);
		bLength  = new BoxPropsD(&Box_3::length,primt,primt->length);
		bSWidth  = new BoxPropsI(&Box_3::width_Seg,primt,primt->width_Seg);
		bSHeight = new BoxPropsI(&Box_3::height_Seg,primt,primt->height_Seg);
		bSLength = new BoxPropsI(&Box_3::length_Seg,primt,primt->length_Seg);

		DoFor(bWidth);
		DoFor(bHeight);
		DoFor(bLength);
		DoFor(bSWidth);
		DoFor(bSHeight);
		DoFor(bSLength);

		bSLength->commit = true;

		ZBox();
	}

	template<class T>
	void DoFor(T* mod)
	{
		mod->extrensic = false;
		mod->CalcmxF();
		primt->ApplyModifier( mod );
	}
	
	template<class T,class S,T* ZBox::*mod>
	ZTvarp MFactory (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZIFloat fr = (this->*mod)->PolyP.FrameValues[ZInterp::currentFrame];
			ZTvarp res=ZAlloc(ZTvar,1);
			*res = ZTFloat(fr);
			return res;
		}

		if ( (this->*mod)->extrensic == true )
			DoFor( (this->*mod) );

		FrameCreater::FillFrames(ZInterp::currentFrame,(S)(FLOAT_ZCONV(*(inp[0]))),&T::PolyP,*(this->*mod) );
		(this->*mod)->CalcmxF();
		bSLength->mxFrame = std::max( bSLength->mxFrame , (this->*mod)->mxFrame );
		return NULL;
	}
};