class CGPlug
{
	
};

template<class T>
class PrimitiveAPI : public ZTBaseObject<T> 
{
public:
	PrimitiveAPI()
	{}

	static void Init()
	{
		StProps.InitScope();

		AddFunction(_ZC("setPhysActor") ,2,&PrimitiveAPI::setPhysActor);
	
		ZTObject::Inheriet(StProps);
	}

	PolyhedronNode* pnode;

	void InitNode(ZTvarS inp,Primitives* p)
	{
		ZTList zl = LIST_ZCONV(*inp[ inp.size()-1 ] );
		pnode = new PolyhedronNode(p,osg::Vec3 (
											FLOAT_ZCONV(*zl.Get(0)),
											FLOAT_ZCONV(*zl.Get(1)),
											FLOAT_ZCONV(*zl.Get(2))
												));
	}

	ZTvarp setPhysActor (ZTvarS inp)
	{
		pZObjP zrsg = INSTANCE_ZCONV(*(inp[0]));
		switch((int)FLOAT_ZCONV(*(inp[1])))
		{
		case 1:
			pnode->RigidActor = XBox::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode);
			break;
		case 2:
			pnode->RigidActor = XPlane::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode);
			break;
		case 3:
			//pnode->RigidActor=XSphere::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode);
			break;
		case 4:
			break;
		}
		return NULL;
	}

};