class ZBulgeType : public ZTBaseObject<ZBulgeType> 
{
public:

	BulgeType buType;

	ZBulgeType()
	{}

	ZBulgeType(BulgeType b):buType(b)
	{}

	ZBulgeType(ZTvarS inp)
	{
		ZBulgeType(BLinear);
	}

	static BulgeType getType(ZTvarp inp)
	{
		pZObjP zins=INSTANCE_ZCONV(*(inp));
		return BulgeType(reinterpret_cast<ZBulgeType*>(zins)->buType);
	}

	static void Init()
	{
		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}

	static ZIString toString(BulgeType butype)
	{
		switch (butype)
		{
		case BRadial:
			return ZIString("Radial");
			break;
		case BLinear:
			return ZIString("Linear");
			break;
		default:
			return ZIString("Type Error");

		}
	}
};