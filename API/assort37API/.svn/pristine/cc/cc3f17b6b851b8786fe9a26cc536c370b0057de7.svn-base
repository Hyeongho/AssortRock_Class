
#include "Player.h"
#include "Bullet.h"
#include "../Scene/Scene.h"

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& obj)	:
	CCharacter(obj)
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	if (!CCharacter::Init())
		return false;

	return true;
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_Pos.y -= 200.f * DeltaTime;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_Pos.y += 200.f * DeltaTime;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_Pos.x -= 200.f * DeltaTime;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_Pos.x += 200.f * DeltaTime;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		CBullet* Bullet = m_Scene->CreateObject<CBullet>("Bullet",
			Vector2(m_Pos + Vector2(100.f, 25.f)),
			Vector2(50.f, 50.f));
	}
}

void CPlayer::PostUpdate(float DeltaTime)
{
	CCharacter::PostUpdate(DeltaTime);
}

void CPlayer::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CPlayer::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}
