
#include "Player.h"
#include "Bullet.h"
#include "../Scene/Scene.h"
#include "../Input.h"

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

	CInput::GetInst()->SetCallback<CPlayer>("MoveUp", KeyState_Push,
		this, &CPlayer::MoveUp);

	CInput::GetInst()->SetCallback<CPlayer>("MoveDown", KeyState_Push,
		this, &CPlayer::MoveDown);

	CInput::GetInst()->SetCallback<CPlayer>("MoveLeft", KeyState_Push,
		this, &CPlayer::MoveLeft);

	CInput::GetInst()->SetCallback<CPlayer>("MoveRight", KeyState_Push,
		this, &CPlayer::MoveRight);

	CInput::GetInst()->SetCallback<CPlayer>("Fire", KeyState_Down,
		this, &CPlayer::BulleFire);

	return true;
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);
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

void CPlayer::MoveUp(float DeltaTime)
{
	m_Pos.y -= 200.f * DeltaTime;
}

void CPlayer::MoveDown(float DeltaTime)
{
	m_Pos.y += 200.f * DeltaTime;
}

void CPlayer::MoveLeft(float DeltaTime)
{
	m_Pos.x -= 200.f * DeltaTime;
}

void CPlayer::MoveRight(float DeltaTime)
{
	m_Pos.x += 200.f * DeltaTime;
}

void CPlayer::BulleFire(float DeltaTime)
{
	CBullet* Bullet = m_Scene->CreateObject<CBullet>("Bullet",
		Vector2(m_Pos + Vector2(100.f, 25.f)),
		Vector2(50.f, 50.f));
}
