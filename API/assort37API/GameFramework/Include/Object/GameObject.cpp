
#include "GameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
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
	Rectangle(hDC, (int)m_Pos.x, (int)m_Pos.y, 
		(int)(m_Pos.x + m_Size.x), (int)(m_Pos.y + m_Size.y));
}