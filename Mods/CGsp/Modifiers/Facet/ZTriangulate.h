class ZTriangulate    : public ModifierAPI<ZTriangulate>
{
public:

	Traingulate* primt;

	ZTriangulate()
	{}

	static void Init()
	{
		ModifierAPI<ZTriangulate>::Init();

		StProps.InitScope();
		
		ZTObject::Inheriet(StProps);
	}

	Modifier* getModifier()
	{
		return primt;
	}

	ZTriangulate(ZTvarS inp)
	{
		primt = new Traingulate();

		ZTriangulate();
	}

};