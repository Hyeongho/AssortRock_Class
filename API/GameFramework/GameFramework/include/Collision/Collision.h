#pragma once

#include "../GameInfo.h"

class CCollision
{
public:
	static bool CollisionBoxToBox(class CColliderBox* Src, class CColliderBox* Dest);
	
	static bool CollisionBoxToBox(const RectInfo& Src, const RectInfo& Dest);
};

