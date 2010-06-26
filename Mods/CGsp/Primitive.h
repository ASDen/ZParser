template<class T>
class PrimitiveAPI : public ZTBaseObject<T> 
{
public:

	Translate* pTr;
	Rotate*    pRt;
	Scale*     pSc;

	PrimitiveAPI()
	{
	}

	static void Init()
	{
		StProps.InitScope();

		AddFunction(_ZC("setPhysActor") ,2,&PrimitiveAPI::setPhysActor);
		AddFunction(_ZC("ApplyModifier") ,1,&PrimitiveAPI::ApplyModifier);
		AddFunction(_ZC("Modify") ,1,&PrimitiveAPI::Modify);
		AddFunction(_ZC("setWire") ,1,&PrimitiveAPI::setWire);
		AddFunction(_ZC("Position") ,1,&PrimitiveAPI::Position);
		AddFunction(_ZC("Rotation") ,1,&PrimitiveAPI::Rotation);
		AddFunction(_ZC("Scale") ,1,&PrimitiveAPI::Scaler);
		AddFunction(_ZC("Color") ,1,&PrimitiveAPI::Color);
		
		ZTObject::Inheriet(StProps);
	}

	PolyhedronNode* pnode;

	void InitNode(ZTvarS inp,Primitives* p)
	{
		if(inp.size()>0)
		{
			ZTList zl = LIST_ZCONV(*inp[ inp.size()-1 ] );
			osg::Vec3 ovt(
				FLOAT_ZCONV(*zl.Get(0)),
				FLOAT_ZCONV(*zl.Get(1)),
				FLOAT_ZCONV(*zl.Get(2))
				);
			pnode = new PolyhedronNode(p,ovt);
			pTr = new Translate(ovt.x(),ovt.y(),ovt.z());
		}
		else
		{
			pnode = new PolyhedronNode(p,osg::Vec3 (0,0,0));
			pTr = new Translate(0);
		}
		pRt = new Rotate(0);
		pSc = new Scale(1);

		pnode->ApplyModifier(pTr);
		pnode->ApplyModifier(pSc);
		pnode->ApplyModifier(pRt);


	}

	ZTvarp Position (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(pTr->tx.FrameValues[ZInterp::currentFrame]);
			zg[1] = ZTFloat(pTr->ty.FrameValues[ZInterp::currentFrame]);
			zg[2] = ZTFloat(pTr->tz.FrameValues[ZInterp::currentFrame]);

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZPoint (zvs); 
			*hv=zin;
			return hv;
		}

		ZTList zls = LIST_ZCONV(*inp[ 0 ] );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(0)))),&Translate::tx,*pTr );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(1)))),&Translate::ty,*pTr );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(2)))),&Translate::tz,*pTr );

		return NULL;
	}

	ZTvarp Rotation (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(pRt->ax.FrameValues[ZInterp::currentFrame]);
			zg[1] = ZTFloat(pRt->ay.FrameValues[ZInterp::currentFrame]);
			zg[2] = ZTFloat(pRt->az.FrameValues[ZInterp::currentFrame]);

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZPoint (zvs); 
			*hv=zin;
			return hv;
		}

		ZTList zls = LIST_ZCONV(*inp[ 0 ] );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(0)))),&Rotate::ax,*pRt );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(1)))),&Rotate::ay,*pRt );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(2)))),&Rotate::az,*pRt );

		return NULL;
	}

	ZTvarp Scaler (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(pSc->sx.FrameValues[ZInterp::currentFrame]);
			zg[1] = ZTFloat(pSc->sy.FrameValues[ZInterp::currentFrame]);
			zg[2] = ZTFloat(pSc->sz.FrameValues[ZInterp::currentFrame]);

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZPoint (zvs); 
			*hv=zin;
			return hv;
		}

		ZTList zls = LIST_ZCONV(*inp[ 0 ] );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(0)))),&Scale::sx,*pSc );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(1)))),&Scale::sy,*pSc );
		FrameCreater::FillFrames(ZInterp::currentFrame,(double)(FLOAT_ZCONV(*(zls.Get(2)))),&Scale::sz,*pSc );

		return NULL;
	}

	virtual Primitives* getPrimtive()=0;

	ZTvarp Color (ZTvarS inp)
	{
		if (inp.size() == 0)
		{
			ZTvarS zvs;
			ZTvarp zg = ZAlloc(ZTvar,3);
			
			zg[0] = ZTFloat(pnode->PColor.x());
			zg[1] = ZTFloat(pnode->PColor.y());
			zg[2] = ZTFloat(pnode->PColor.z());

			zvs.push_back( &zg[0] );
			zvs.push_back( &zg[1] );
			zvs.push_back( &zg[2] );
			
			ZTOInstance zin;
			ZTvarp hv = ZAlloc(ZTvar,1);
			zin.val = new ZPoint (zvs); 
			*hv=zin;
			return hv;
		}

		pZObjP zins=INSTANCE_ZCONV(*(inp[0]));
		Point_3* p3 = reinterpret_cast<ZPoint*>(zins)->getPnt();
		pnode->PColor = osg::Vec3(p3->x(),p3->y(),p3->z());
	}

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
			pnode->ClothActor->setThickness(0.5);
			break;
		}
		return NULL;
	}

};