#include "XCGsp.h"
#include "../../stdafx.h"
#include "../../ZInterp.h"
#include "ClassDefs.h"

#define ADD_CLASS(X,Y) X::Init();\
						*zv=ZObjP();\
						boost::get<gZObject>(*zv).cont=new X();\
						ZInterp::ZSym.InsertSymbol(_ZC(Y),zv);\
						zv++;


void ZModInit_CGsp()
{
	ZTvarp zv = ZAlloc(ZTvar,20);

	ADD_CLASS(ZBox,"Box");
	ADD_CLASS(ZPlane,"Plane");
	ADD_CLASS(ZRigidBodySimulation,"PhysicsSimulation");
	ADD_CLASS(ZKeyFrame,"KeyFrameAnimation");
	ADD_CLASS(ZTwist,"Twist");
	


	/*ZBox::Init();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZBox();
	ZInterp::ZSym.InsertSymbol(_ZC("Box"),zv);

	zv++;
	ZPlane::Init();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZPlane();
	ZInterp::ZSym.InsertSymbol(_ZC("Plane"),zv);

	zv++;
	ZRigidBodySimulation::Init();
	*zv=ZObjP();
	boost::get<gZObject>(*zv).cont=new ZRigidBodySimulation();
	ZInterp::ZSym.InsertSymbol(_ZC("ZRigidBodySimulation"),zv);*/

	

}