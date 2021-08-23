#include "Bullet.h"

CBullet::CBullet()
{
	m_Dir.x = 1.f;
	m_Dir.y = 0.f;

	m_Distance = 800.f;

	m_Speed = 500.f;
}

CBullet::CBullet(const CBullet& obj) : CGameObject(obj)
{
	m_Dir = obj.m_Dir;
	m_Speed = obj.m_Speed;
}

CBullet::~CBullet()
{
}

bool CBullet::Init()
{
	if (!CGameObject::Init())
	{
		return false;
	}

	return true;
}

void CBullet::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	Vector2 Dir = m_Dir;
	Dir.Normalize();

	m_Pos += Dir * m_Speed * DeltaTime;

	m_Distance -= m_Speed * DeltaTime;

	if (m_Distance <= 0.f)
	{
		Destroy();
	}
}

void CBullet::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CBullet::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CBullet::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CBullet* CBullet::Clone()
{
	return new CBullet(*this);
}
