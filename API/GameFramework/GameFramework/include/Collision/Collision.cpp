#include "Collision.h"
#include "ColliderBox.h"
#include "ColliderSphere.h"

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
	{
		return false;
	}

	else if (Dest. Left > Src.Right)
	{
		return false;
	}

	else if (Src.Top > Dest.Bottom)
	{
		return false;
	}

	else if (Dest.Top > Src.Bottom)
	{
		return false;
	}

	return true;
}

bool CCollision::CollisionSphereToSphere(CColliderSphere* Src, CColliderSphere* Dest)
{
	if (CollisionSphereToSphere(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionSphereToSphere(const SphereInfo& Src, const SphereInfo& Dest)
{
	float Dist = Distance(Src.Center, Dest.Center);

	return Dist <= Src.Radius + Dest.Radius;
}

bool CCollision::CollisionBoxToSphere(CColliderBox* Src, CColliderSphere* Dest)
{
	if (CollisionBoxToSphere(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionBoxToSphere(const RectInfo& Src, const SphereInfo& Dest)
{
	if ((Src.Left >= Dest.Center.x && Src.Right <= Dest.Center.x) || (Src.Top >= Dest.Center.y && Src.Bottom <= Dest.Center.y))
	{
		float DestLeft = Src.Left - Dest.Radius;
		float DestTop = Src.Top - Dest.Radius;
		float DestRight = Src.Right + Dest.Radius;
		float DestBottom = Src.Bottom + Dest.Radius;

		if ((DestLeft >= Dest.Center.x && DestRight <= Dest.Center.x) || (DestTop >= Dest.Center.y && DestBottom <= Dest.Center.y))
		{
			return true;
		}
	}

	else
	{
		float LTPoint = Distance(Dest.Center, Vector2(Src.Left, Src.Top));
		float LBPoint = Distance(Dest.Center, Vector2(Src.Left, Src.Bottom));
		float RTPoint = Distance(Dest.Center, Vector2(Src.Right, Src.Top));
		float RBPoint = Distance(Dest.Center, Vector2(Src.Right, Src.Bottom));

		if ((LTPoint <= Dest.Radius) || (LBPoint <= Dest.Radius) || (RTPoint <= Dest.Radius) || (RBPoint <= Dest.Radius))
		{
			return true;
		}
	}

	return false;
}

bool CCollision::CollisionSphereToBox(CColliderSphere* Src, CColliderBox* Dest)
{
	if (CollisionSphereToBox(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionSphereToBox(const SphereInfo& Src, const RectInfo& Dest)
{
	if ((Dest.Left >= Src.Center.x && Dest.Right <= Src.Center.x) || (Dest.Top >= Src.Center.y && Dest.Bottom <= Src.Center.y))
	{
		float DestLeft = Dest.Left - Src.Radius;
		float DestTop = Dest.Top - Src.Radius;
		float DestRight = Dest.Right + Src.Radius;
		float DestBottom = Dest.Bottom + Src.Radius;

		if ((DestLeft >= Src.Center.x && DestRight <= Src.Center.x) || (DestTop >= Src.Center.y && DestBottom <= Src.Center.y))
		{
			return true;
		}
	}

	else
	{
		float LTPoint = Distance(Src.Center, Vector2(Dest.Left, Dest.Top));
		float LBPoint = Distance(Src.Center, Vector2(Dest.Left, Dest.Bottom));
		float RTPoint = Distance(Src.Center, Vector2(Dest.Right, Dest.Top));
		float RBPoint = Distance(Src.Center, Vector2(Dest.Right, Dest.Bottom));

		if ((LTPoint <= Src.Radius) || (LBPoint <= Src.Radius) || (RTPoint <= Src.Radius) || (RBPoint <= Src.Radius))
		{
			return true;
		}
	}

	return false;
}
