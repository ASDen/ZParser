class ZAxis : public ZTBaseObject<ZAxis> 
{
public:

	Axis ax;

	ZAxis()
	{}

	ZAxis(Axis a):ax(a)
	{}

	ZAxis(ZTvarS inp)
	{
		ZAxis(Z_ax);
	}

	static Axis getAxis(ZTvarp inp)
	{
		pZObjP zins = INSTANCE_ZCONV(*(inp));
		return Axis(reinterpret_cast<ZAxis*>(zins)->ax);
	}

	static void Init()
	{
		StProps.InitScope();
        AddFunction(_ZC("toString"),1,&ZAxis::toString);
	
		ZTObject::Inheriet(StProps);
	}

	static ZIString toString(Axis ax)
	{
		switch (ax)
		{
		case X_ax:
			return ZIString("X Axis");
			break;
		case Y_ax:
			return ZIString("Y Axis");
			break;
		case Z_ax:
			return ZIString("Z Axis");
			break;
		default:
			return ZIString("Type Error");
		}
	}
	
	ZTvarp toString(ZTvarS inp)
	{
		ostringstream s1;

		switch (ax)
		{
		case X_ax:
			s1 << " Axis : " << "X Axis" << endl;
			break;
		case Y_ax:
			s1 << " Axis : " << "Y Axis" << endl;
			break;
		case Z_ax:
			s1 << " Axis : " << "Z Axis" << endl;
			break;
		default:
			s1 << " Axis : " << "Type Error" << endl;
		}
		
		INST_TO_STR( s1.str() );
	}
};