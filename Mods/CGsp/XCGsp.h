#pragma once
#define NOMINMAX // for conflicts with NxMath
#define CGSP_CC __declspec(dllimport)  
#include "../../../CGsp/Rendrer/stdafx.h"
#include "../../../CGsp/Rendrer/RdInc.h"
#pragma message ("XCGsp.h inlcluded big things")
namespace XCGsp
{
	extern PhysicsManager* ZPxMan;
	extern osgPolyManager* ZPolyMan;
};