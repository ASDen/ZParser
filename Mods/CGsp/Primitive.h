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
		AddFunction(_ZC("ApplyModifier") ,1,&PrimitiveAPI::ApplyModifier);
		AddFunction(_ZC("Modify") ,1,&PrimitiveAPI::Modify);
		AddFunction(_ZC("setWire") ,1,&PrimitiveAPI::setWire);
	
		ZTObject::Inheriet(StProps);
	}

	PolyhedronNode* pnode;

	void InitNode(ZTvarS inp,Primitives* p,bool exists = false)
	{
		if(exists)
		{
			ZTList zl = LIST_ZCONV(*inp[ inp.size()-1 ] );
			pnode = new PolyhedronNode(p,osg::Vec3 (
				FLOAT_ZCONV(*zl.Get(0)),
				FLOAT_ZCONV(*zl.Get(1)),
				FLOAT_ZCONV(*zl.Get(2))
				));
		}
		else
		{
			pnode = new PolyhedronNode(p,osg::Vec3 (0,0,0));
		}
	}

	virtual Primitives* getPrimtive()=0;

	ZTvarp ApplyModifier (ZTvarS inp)
	{
		pZObjP zrsg = INSTANCE_ZCONV(*(inp[0]));
		Primitives* pr=this->getPrimtive();
		Modifier* m= (reinterpret_cast < ModifierAPI<ZTwist>* >(zrsg))->getModifier();
		pr->ApplyModifier(m);
		return NULL;
	}

	ZTvarp Modify (ZTvarS inp)
	{
		pZObjP zrsg = INSTANCE_ZCONV(*(inp[0]));
		Primitives* pr=this->getPrimtive();
		Modifier* m= (reinterpret_cast < ModifierAPI<ZTwist>* >(zrsg))->getModifier();
		m->Do(pr->Mesh);
		return NULL;
	}

	ZTvarp setWire (ZTvarS inp)
	{
		pnode->WireFrame = BOOL_ZCONV(*(inp[0]));
		return NULL;
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
			pnode->RigidActor = XCapsule::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode);
			break;
		case 3:
			pnode->RigidActor = XConvex::Construct<ConvexHullReducer>(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gPhysicsSDK,pnode);
			break;
		case 4:
			pnode->RigidActor = XPlane::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode);
			break;
		case 5:
			pnode->RigidActor = XSphere::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode);
			break;
		case 6:
			pnode->RigidActor = XSpring::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gPhysicsSDK,pnode,BOOL_ZCONV(*(inp[2])));
			break;
		case 7:
			pnode->RigidActor = XTorus::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gPhysicsSDK,pnode);
			break;
		case 8:
			pnode->RigidActor = XTube::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,pnode,INT_ZCONV(*(inp[2])),BOOL_ZCONV(*(inp[3])));
			break;
		case 9:
			pnode->ClothActor = XCloth::Construct(reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gScene,reinterpret_cast<ZRigidBodySimulation*>(zrsg)->pm->gPhysicsSDK,pnode,false);
			break;
		}
		return NULL;
	}

};