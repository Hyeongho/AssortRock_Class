
#include "Collider.h"

CCollider::CCollider()	:
	m_Scene(nullptr),
	m_Owner(nullptr),
	m_Enable(true)
{
}

CCollider::CCollider(const CCollider& collider)	:
	CRef(collider),
	m_Scene(nullptr),
	m_Owner(nullptr),
	m_Enable(true)
{
	m_Type = collider.m_Type;
	m_Offset = collider.m_Offset;
}

CCollider::~CCollider()
{
}

bool CCollider::Init()
{
	return true;
}

void CCollider::Update(float DeltaTime)
{
}

void CCollider::PostUpdate(float DeltaTime)
{
}

void CCollider::Render(HDC hDC)
{
}

CCollider* CCollider::Clone()
{
	return nullptr;
}
