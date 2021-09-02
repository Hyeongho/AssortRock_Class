#include "ColliderBox.h"
#include "../Object/GameObject.h"
#include "../GameManager.h"
#include "Collision.h"

CColliderBox::CColliderBox() : m_Width(100.f), m_Height(100.f)
{
	m_Type = ECollider_Type::Box;
}

CColliderBox::CColliderBox(const CColliderBox& collider) : CCollider(collider)
{
	m_Width = collider.m_Width;
	m_Height = collider.m_Height;
	m_Info = collider.m_Info;
}

CColliderBox::~CColliderBox()
{
}

bool CColliderBox::Init()
{
	if (!CCollider::Init())
	{
		return false;
	}

	return true;
}

void CColliderBox::Update(float DeltaTime)
{
	CCollider::Update(DeltaTime);
}

void CColliderBox::PostUpdate(float DeltaTime)
{
	CCollider::PostUpdate(DeltaTime);

	Vector2 Pos = m_Owner->GetPos();

	m_Info.Left = Pos.x - m_Width / 2.f + m_Offset.x;
	m_Info.Top = Pos.y - m_Height / 2.f + m_Offset.y;
	m_Info.Right = Pos.x + m_Width / 2.f + m_Offset.x;
	m_Info.Bottom = Pos.y + m_Height / 2.f + m_Offset.y;
}

void CColliderBox::Render(HDC hDC)
{
	CCollider::Render(hDC);

#ifdef _DEBUG
	HBRUSH Brush = CGameManager::GetInst()->GetGreenBrush();

	RECT rc = { (long)m_Info.Left, (long)m_Info.Top , (long)m_Info.Right , (long)m_Info.Bottom };

	FrameRect(hDC, &rc, Brush);
#endif // _DEBUG

}

CColliderBox* CColliderBox::Clone()
{
	return new CColliderBox(*this);
}

bool CColliderBox::Collision(CCollider* Dest)
{
	switch (Dest->GetColliderType())
	{
	case ECollider_Type::Box:
		return CCollision::CollisionBoxToBox(this, (CColliderBox*)Dest);
	case ECollider_Type::Sphere:
		break;
	case ECollider_Type::Point:
		break;
	}

	return false;
}
