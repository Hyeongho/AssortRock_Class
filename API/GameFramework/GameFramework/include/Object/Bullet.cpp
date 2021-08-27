#include "Bullet.h"

CBullet::CBullet()
{
	m_Dir.x = 1.f;
	m_Dir.y = 0.f;

	m_Distance = 800.f;

	SetMoveSpeed(500.f);
}

CBullet::CBullet(const CBullet& obj) : CGameObject(obj)
{
	m_Dir = obj.m_Dir;
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

	SetTexture("Bullet", TEXT("Hit2.bmp"));
	SetSize(178.f, 164.f);
	SetImageStart(178.f * 5, 0.f);
	SetTextureColorKey(255, 0, 255);

	return true;
}

void CBullet::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	Vector2 Dir = m_Dir;
	Dir.Normalize();

	Move(Dir);

	m_Distance -= GetMoveSpeedFrame();

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
