class ZAxis : public ZTBaseObject<ZAxis> 
{
public:

	ZTvar X_ax,
		  Y_ax,
		  Z_ax;

	ZAxis()
	{
		AddDataMember(_ZC("X_ax")  , &ZAxis::X_ax);
		AddDataMember(_ZC("Y_ax")  , &ZAxis::Y_ax);
		AddDataMember(_ZC("Z_ax")  , &ZAxis::Z_ax);
	}

	ZAxis(ZTvarS inp)
	{
		X_ax  = ZTFloat(0);
		Y_ax  = ZTFloat(1);
		Z_ax  = ZTFloat(2);

		ZAxis();
	}

	static Axis getAxis(ZTvarp inp)
	{
		Axis RoAxis;
		switch((int)(FLOAT_ZCONV(*inp)))
		{
		case 0:
			RoAxis = Axis::X_ax;
			break;
		case 1:
			RoAxis = Axis::Y_ax;
			break;
		case 2:
			RoAxis = Axis::Z_ax;
			break;
		}

		return RoAxis;
	}

	static void Init()
	{
		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}
};