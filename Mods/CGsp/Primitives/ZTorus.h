class ZTorus    : public PrimitiveAPI<ZTorus>
{
public:

	Torus_3* primt;

	TorusPropsD* tRadius1;
	TorusPropsD* tRadius2;
	TorusPropsD* tRotation;
	TorusPropsD* tTwist;
	TorusPropsI* tSideSegs;
	TorusPropsI* tHeightSegs;

	ZTorus()
	{}

	static void Init()
	{
		PrimitiveAPI<ZTorus>::Init();

		StProps.InitScope();

		AddFunction(_ZC("Radius1") ,1,&ZTorus::MFactory<TorusPropsD,double,&ZTorus::tRadius1>);
		AddFunction(_ZC("Radius2") ,1,&ZTorus::MFactory<TorusPropsD,double,&ZTorus::tRadius2>);
		AddFunction(_ZC("Rotation") ,1,&ZTorus::MFactory<TorusPropsD,double,&ZTorus::tRotation>);
		AddFunction(_ZC("Twist") ,1,&ZTorus::MFactory<TorusPropsD,double,&ZTorus::tTwist>);

		AddFunction(_ZC("SideSegs") ,1,&ZTorus::MFactory<TorusPropsI,int,&ZTorus::tSideSegs>);
		AddFunction(_ZC("Segs") ,1,&ZTorus::MFactory<TorusPropsI,int,&ZTorus::tHeightSegs>);

		AddFunction(_ZC("toString"),0,&ZTorus::toString);
	
		ZTObject::Inheriet(StProps);
	}

	Primitives* getPrimtive()
	{return primt;}

	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;
		s1 << " Torus : Radius1 = " << primt->radius1 << ", Radius2 = " << primt->radius2
		   << ", Rotation = " << primt->rotation << ", Twist = " << primt->twist 
		   << ", Height Segments = " << primt->Seg << ", Side Segments = " << primt->side_Seg << endl;
		
		INST_TO_STR( s1.str() );
	}

	//FIXME : int conversions
	ZTorus(ZTvarS inp)
	{int inputNumber = 0;
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
			primt = new Torus_3();
			break;
		case 2:
			primt = new Torus_3( FLOAT_ZCONV(*(inp[0])) );
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			primt = new Torus_3( FLOAT_ZCONV(*(inp[0])) , FLOAT_ZCONV(*(inp[1])) );
			break;
		case 7:
			primt = new Torus_3( FLOAT_ZCONV(*inp[0]) , FLOAT_ZCONV(*inp[1]) , FLOAT_ZCONV(*inp[2]) , FLOAT_ZCONV(*inp[3]) , INT_ZCONV(*inp[4]) , INT_ZCONV(*inp[5]) );
			break;
		default:
			ZError::Throw<ZWrongNumberOfArguments>();
			break;
		}
		primt->Draw();
		InitNode(inp,primt, PositionExists);

		tRadius1	= new TorusPropsD(&Torus_3::radius1,primt,primt->radius1);
		tRadius2	= new TorusPropsD(&Torus_3::radius2,primt,primt->radius2);
		tRotation	= new TorusPropsD(&Torus_3::rotation,primt,primt->rotation);
		tTwist		= new TorusPropsD(&Torus_3::twist,primt,primt->twist);
		tSideSegs	= new TorusPropsI(&Torus_3::side_Seg,primt,primt->side_Seg);
		tHeightSegs	= new TorusPropsI(&Torus_3::Seg,primt,primt->Seg);

		
		primt->ApplyModifier(tRadius1);
		primt->ApplyModifier(tRadius2);
		primt->ApplyModifier(tRotation);
		primt->ApplyModifier(tTwist);
		primt->ApplyModifier(tSideSegs);
		primt->ApplyModifier(tHeightSegs);

		ZTorus();
	}

	template<class T,class S,T* ZTorus::*mod>
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