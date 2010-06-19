template<class T>
class ModifierAPI : public ZTBaseObject<T> 
{
public:
	ModifierAPI()
	{}

	virtual Modifier* getModifier()=0;

	static void Init()
	{
		StProps.InitScope();
	
		ZTObject::Inheriet(StProps);
	}
};