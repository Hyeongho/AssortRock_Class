#include "Collider.h"
#include "CollisionManager.h"

CCollider::CCollider() : m_Scene(nullptr), m_Owner(nullptr), m_Enable(true), m_Profile(nullptr)
{
}

CCollider::CCollider(const CCollider& collider) : CRef(collider), m_Scene(nullptr), m_Owner(nullptr)
{
	m_Type = collider.m_Type;
	m_Offset = collider.m_Offset;
	m_Profile = collider.m_Profile;
}

CCollider::~CCollider()
{
}

void CCollider::SetCollisionProfile(const std::string& Name)
{
	m_Profile = CCollisionManager::GetInst()->FindProfile(Name);
}

bool CCollider::Init()
{
	m_Profile = CCollisionManager::GetInst()->FindProfile("Default");

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
