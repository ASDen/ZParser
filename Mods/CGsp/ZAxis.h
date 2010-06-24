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
		pZObjP zins=INSTANCE_ZCONV(*(inp));
		return Axis(reinterpret_cast<ZAxis*>(zins)->ax);
	}

	static void Init()
	{
		StProps.InitScope();
	
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
};