class ZBulgeType : public ZTBaseObject<ZBulgeType> 
{
public:

	ZTvar BRadial,
		  BLinear;

	ZBulgeType()
	{
		AddDataMember(_ZC("BRadial")  , &ZBulgeType::BRadial);
		AddDataMember(_ZC("BLinear")  , &ZBulgeType::BLinear);
	}

	ZBulgeType(ZTvarS inp)
	{
		BRadial  = ZTFloat(0);
		BLinear  = ZTFloat(1);

		ZBulgeType();
	}

	static BulgeType getType(ZTvarp inp)
	{
		BulgeType BuType;
		switch((int)(FLOAT_ZCONV(*inp)))
		{
		case 0:
			BuType = BulgeType::BRadial;
			break;
		case 1:
			BuType = BulgeType::BLinear;
			break;
		}

		return BuType;
	}

	static void Init()
	{
		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}
};