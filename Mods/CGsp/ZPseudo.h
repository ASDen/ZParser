enum PClasses
{
	_XAxis,
	_YAxis,
	_ZAxis
};

template<PClasses T>
class ZPseudo : public ZTBaseObject< ZPseudo<T> > 
{
public:
	ZPseudo()
	{}

	ZPseudo(ZTvarS inp)
	{ZPseudo();}
	
	static void Init()
	{
		StProps.InitScope();
		ZTObject::Inheriet(StProps);
	}
};

typedef ZPseudo<PClasses::_XAxis> PXAxis;
typedef ZPseudo<PClasses::_YAxis> PYAxis;
typedef ZPseudo<PClasses::_ZAxis> PZAxis;