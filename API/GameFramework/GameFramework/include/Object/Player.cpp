#include "Player.h"
#include "../Scene/Scene.h"
#include "../Input.h"
#include "../GameManager.h"

CPlayer::CPlayer() : m_Skill1Enable(false), m_Skill1Time(0.f)
{
}

CPlayer::CPlayer(const CPlayer& obj) : CCharacter(obj)
{
	m_Skill1Time = obj.m_Skill1Time;
	m_Skill1Enable = false;
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	if (!CCharacter::Init())
	{
		return false;
	}

	SetPivot(0.5f, 0.5f);

	//SetTexture("Teemo", TEXT("teemo.bmp"));

	CreateAnimation();
	AddAnimation("LucidNunNaRightIdle");
	AddAnimation("LucidNunNaRightWalk");
	AddAnimation("LucidNunNaRightAttack", false, 0.2f);

	CInput::GetInst()->SetCallback<CPlayer>("MoveUp", KeyState_Push, this, &CPlayer::MoveUp);
	CInput::GetInst()->SetCallback<CPlayer>("MoveDown", KeyState_Push, this, &CPlayer::MoveDown);
	CInput::GetInst()->SetCallback<CPlayer>("MoveLeft", KeyState_Push, this, &CPlayer::MoveLeft);
	CInput::GetInst()->SetCallback<CPlayer>("MoveRight", KeyState_Push, this, &CPlayer::MoveRight);
	CInput::GetInst()->SetCallback<CPlayer>("Fire", KeyState_Down, this, &CPlayer::BulleFire);

	CInput::GetInst()->SetCallback<CPlayer>("Pause", KeyState_Down, this, &CPlayer::Pause);
	CInput::GetInst()->SetCallback<CPlayer>("Resume", KeyState_Down, this, &CPlayer::Resume);

	CInput::GetInst()->SetCallback<CPlayer>("Skill1", KeyState_Down, this, &CPlayer::Skill1);

	return true;
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	if (m_Skill1Enable)
	{
		m_Skill1Time += DeltaTime;

		if (m_Skill1Time >= 3.f)
		{
			m_Skill1Enable = false;
			m_Skill1Time = 0.f;

			SetTimeScale(1.f);
			CGameManager::GetInst()->SetTimeScale(1.f);

			/*auto	iter = m_Skill1BulletList.begin();
			auto	iterEnd = m_Skill1BulletList.end();

			for (; iter != iterEnd; ++iter)
			{
				(*iter)->SetTimeScale(1.f);
			}

			m_Skill1BulletList.clear();*/
		}
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

void CPlayer::MoveUp(float DeltaTime)
{
	Move(Vector2(0.f, -1.f));
}

void CPlayer::MoveDown(float DeltaTime)
{
	Move(Vector2(0.f, 1.f));
}

void CPlayer::MoveLeft(float DeltaTime)
{
	Move(Vector2(-1.f, 0.f));
}

void CPlayer::MoveRight(float DeltaTime)
{
	Move(Vector2(1.f, 0.f));
}

void CPlayer::BulleFire(float DeltaTime)
{
	CSharedPtr<CBullet> Bullet = m_Scene->CreateObject<CBullet>("Bullet", Vector2(m_Pos + Vector2(75, 0)), Vector2(50.f, 50.f));

	Bullet->SetPivot(0.5f, 0.5f);

	/*if (m_Skill1Enable)
	{
		Bullet->SetTimeScale(0.f);
		m_Skill1BulletList.push_back(Bullet);
	}*/
}

void CPlayer::Pause(float DeltaTime)
{
	CGameManager::GetInst()->SetTimeScale(0.f);
}

void CPlayer::Resume(float DeltaTime)
{
	CGameManager::GetInst()->SetTimeScale(1.f);
}

void CPlayer::Skill1(float DeltaTime)
{
	CGameManager::GetInst()->SetTimeScale(0.01f);
	SetTimeScale(100.f);
	m_Skill1Enable = true;
	//m_Skill1Time = 0.f;
}
