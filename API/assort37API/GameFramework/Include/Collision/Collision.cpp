
#include "Collision.h"
#include "ColliderBox.h"

bool CCollision::CollisionBoxToBox(CColliderBox* Src, CColliderBox* Dest)
{
	if (CollisionBoxToBox(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionBoxToBox(const RectInfo& Src, const RectInfo& Dest)
{
	if (Src.Left > Dest.Right)
		return false;

	else if (Dest.Left > Src.Right)
		return false;

	else if (Src.Top > Dest.Bottom)
		return false;

	else if (Dest.Top > Src.Bottom)
		return false;

	return true;
}
