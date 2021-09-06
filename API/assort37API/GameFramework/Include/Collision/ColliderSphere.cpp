
#include "ColliderSphere.h"
#include "../Object/GameObject.h"
#include "../GameManager.h"
#include "Collision.h"
#include "ColliderBox.h"

CColliderSphere::CColliderSphere()
{
	m_Info.Radius = 50.f;
	m_Type = ECollider_Type::Sphere;
}

CColliderSphere::CColliderSphere(const CColliderSphere& collider) :
	CCollider(collider)
{
	m_Info = collider.m_Info;
}

CColliderSphere::~CColliderSphere()
{
}

bool CColliderSphere::Init()
{
	if (!CCollider::Init())
		return false;

	return true;
}

void CColliderSphere::Update(float DeltaTime)
{
	CCollider::Update(DeltaTime);
}

void CColliderSphere::PostUpdate(float DeltaTime)
{
	CCollider::PostUpdate(DeltaTime);

	m_Info.Center = m_Owner->GetPos() + m_Offset;
}

void CColliderSphere::Render(HDC hDC)
{
	CCollider::Render(hDC);

#ifdef _DEBUG
	HPEN	Pen = CGameManager::GetInst()->GetGreenPen();

	if (!m_CollisionList.empty())
		Pen = CGameManager::GetInst()->GetRedPen();
	
	HGDIOBJ	Prev = SelectObject(hDC, Pen);

	MoveToEx(hDC, (int)(m_Info.Center.x + m_Info.Radius), (int)m_Info.Center.y, nullptr);

	for (int i = 0; i < 12; ++i)
	{
		float	Radian = DegreeToRadian((i + 1) * (360.f / 12.f));

		float	x = m_Info.Center.x + cosf(Radian) * m_Info.Radius;
		float	y = m_Info.Center.y + sinf(Radian) * m_Info.Radius;

		LineTo(hDC, (int)x, (int)y);
	}

	SelectObject(hDC, Prev);
#endif // _DEBUG

}

CColliderSphere* CColliderSphere::Clone()
{
	return new CColliderSphere(*this);
}

bool CColliderSphere::Collision(CCollider* Dest)
{
	switch (Dest->GetColliderType())
	{
	case ECollider_Type::Box:
		return CCollision::CollisionBoxToSphere((CColliderBox*)Dest, this);
		break;
	case ECollider_Type::Sphere:
		return CCollision::CollisionSphereToSphere(this, (CColliderSphere*)Dest);
	case ECollider_Type::Point:
		break;
	}

	return false;
}
