#include "GameObject.h"
#include "../GameManager.h"

CGameObject::CGameObject() : m_MoveSpeed(200.f), m_TimeScale(1.f)
{
}

CGameObject::CGameObject(const CGameObject& obj)
{
	*this = obj;
}

CGameObject::~CGameObject()
{
}

void CGameObject::Move(const Vector2& Dir)
{
	Vector2 CurrentMove = Dir * m_MoveSpeed * CGameManager::GetInst()->GetDeltaTime() * m_TimeScale;
	m_Velocitry += CurrentMove;
	m_Pos += CurrentMove;
}

void CGameObject::Move(const Vector2& Dir, float Speed)
{
	Vector2 CurrentMove = Dir * Speed * CGameManager::GetInst()->GetDeltaTime() * m_TimeScale;
	m_Velocitry += CurrentMove;
	m_Pos += CurrentMove;
}

bool CGameObject::Init()
{
	return true;
}

void CGameObject::Update(float DeltaTime)
{
}

void CGameObject::PostUpdate(float DeltaTime)
{
}

void CGameObject::Collision(float DeltaTime)
{
}

void CGameObject::Render(HDC hDC)
{
	Vector2 Lt = m_Pos - m_Pivot * m_Size;

	Rectangle(hDC, (int)Lt.x, (int)Lt.y, (int)(Lt.x + m_Size.x), (int)(Lt.y + m_Size.y));

	m_PrevPos = m_Pos;
	m_Velocitry = Vector2(0.f, 0.f);
}

CGameObject* CGameObject::Clone()
{
	return nullptr;
}
