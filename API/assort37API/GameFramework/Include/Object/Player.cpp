
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Input.h"
#include "../GameManager.h"
#include "../Collision/ColliderBox.h"

CPlayer::CPlayer()	:
	m_Skill1Enable(false),
	m_Skill1Time(0.f)
{
}

CPlayer::CPlayer(const CPlayer& obj)	:
	CCharacter(obj)
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
		return false;

	SetPivot(0.5f, 1.f);

	//SetTexture("Teemo", TEXT("teemo.bmp"));
	CreateAnimation();
	AddAnimation("LucidNunNaRightIdle");
	AddAnimation("LucidNunNaRightWalk", true, 0.6f);
	AddAnimation("LucidNunNaRightAttack", false, 0.5f);
	AddAnimation("LucidNunNaRightSkill1", false, 0.5f);

	AddAnimationNotify<CPlayer>("LucidNunNaRightAttack", 2, this, &CPlayer::Fire);
	SetAnimationEndNotify<CPlayer>("LucidNunNaRightAttack", this, &CPlayer::AttackEnd);

	AddAnimationNotify<CPlayer>("LucidNunNaRightSkill1", 2, this, &CPlayer::Skill1Enable);
	SetAnimationEndNotify<CPlayer>("LucidNunNaRightSkill1", this, &CPlayer::Skill1End);

	/*CColliderBox* Body = AddCollider<CColliderBox>("Body");
	Body->SetExtent(80.f, 75.f);
	Body->SetOffset(0.f, -37.5f);*/

	CColliderBox* Head = AddCollider<CColliderBox>("Head");
	Head->SetExtent(40.f, 30.f);
	Head->SetOffset(0.f, -60.f);
	Head->SetCollisionProfile("Player");

	CColliderBox* Body = AddCollider<CColliderBox>("Body");
	Body->SetExtent(80.f, 45.f);
	Body->SetOffset(0.f, -22.5f);
	Body->SetCollisionProfile("Player");



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

	CInput::GetInst()->SetCallback<CPlayer>("Pause", KeyState_Down,
		this, &CPlayer::Pause);
	CInput::GetInst()->SetCallback<CPlayer>("Resume", KeyState_Down,
		this, &CPlayer::Resume);

	CInput::GetInst()->SetCallback<CPlayer>("Skill1", KeyState_Down,
		this, &CPlayer::Skill1);

	return true;
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	if (GetAsyncKeyState(VK_F1) & 0x8000)
		SetAttackSpeed(0.5f);

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

	if (CheckCurrentAnimation("LucidNunNaRightAttack"))
		SetOffset(0.f, 20.f);

	else
		SetOffset(0.f, 0.f);
}

void CPlayer::PostUpdate(float DeltaTime)
{
	CCharacter::PostUpdate(DeltaTime);

	// 현재 애니메이션이 Walk 상태에서 속도가 0이 되었다면 이전까지 움직이다가
	// 지금 멈췄다는 것이다.
	if (CheckCurrentAnimation("LucidNunNaRightWalk") &&
		m_Velocity.Length() == 0.f)
	{
		ChangeAnimation("LucidNunNaRightIdle");
	}
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
	//m_Pos.y -= 200.f * DeltaTime;
	Move(Vector2(0.f, -1.f));
	ChangeAnimation("LucidNunNaRightWalk");
}

void CPlayer::MoveDown(float DeltaTime)
{
	Move(Vector2(0.f, 1.f));
	ChangeAnimation("LucidNunNaRightWalk");
}

void CPlayer::MoveLeft(float DeltaTime)
{
	Move(Vector2(-1.f, 0.f));
	ChangeAnimation("LucidNunNaRightWalk");
}

void CPlayer::MoveRight(float DeltaTime)
{
	Move(Vector2(1.f, 0.f));
	ChangeAnimation("LucidNunNaRightWalk");
}

void CPlayer::BulleFire(float DeltaTime)
{
	ChangeAnimation("LucidNunNaRightAttack");	

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
	ChangeAnimation("LucidNunNaRightSkill1");
}

void CPlayer::AttackEnd()
{
	ChangeAnimation("LucidNunNaRightIdle");
}

void CPlayer::Fire()
{
	CSharedPtr<CBullet> Bullet = m_Scene->CreateObject<CBullet>("Bullet",
		Vector2(m_Pos + Vector2(75.f, 0.f)),
		Vector2(50.f, 50.f));

	Bullet->SetPivot(0.5f, 0.5f);

	CCollider* Collider = Bullet->FindCollider("Body");

	if (Collider)
		Collider->SetCollisionProfile("PlayerAttack");
}

void CPlayer::Skill1End()
{
	ChangeAnimation("LucidNunNaRightIdle");
}

void CPlayer::Skill1Enable()
{
	CGameManager::GetInst()->SetTimeScale(0.01f);
	SetTimeScale(100.f);
	m_Skill1Enable = true;
	//m_Skill1Time = 0.f;
}
