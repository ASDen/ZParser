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
//public:
//
//	ZTvar BRadial,
//		  BLinear;
//
//	ZBulgeType()
//	{
//		AddDataMember(_ZC("BRadial")  , &ZBulgeType::BRadial);
//		AddDataMember(_ZC("BLinear")  , &ZBulgeType::BLinear);
//	}
//
//	ZBulgeType(ZTvarS inp)
//	{
//		BRadial  = ZTFloat(0);
//		BLinear  = ZTFloat(1);
//
//		ZBulgeType();
//	}
//
//	static BulgeType getType(ZTvarp inp)
//	{
//		BulgeType BuType;
//		switch((int)(FLOAT_ZCONV(*inp)))
//		{
//		case 0:
//			BuType = BulgeType::BRadial;
//			break;
//		case 1:
//			BuType = BulgeType::BLinear;
//			break;
//		}
//
//		return BuType;
//	}
//
//	static void Init()
//	{
//		StProps.InitScope();
//	
//		ZTObject::Inheriet(StProps);
//	}
};