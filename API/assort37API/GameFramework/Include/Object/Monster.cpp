
#include "Monster.h"
#include "Bullet.h"
#include "../Scene/Scene.h"

CMonster::CMonster()
{
	m_Dir.x = 0.f;
	m_Dir.y = 1.f;
}

CMonster::CMonster(const CMonster& obj) :
	CCharacter(obj)
{
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	if (!CCharacter::Init())
		return false;

	return true;
}

void CMonster::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	m_Pos += m_Dir * 300.f * DeltaTime;

	if (m_Pos.y + m_Size.y >= 720.f)
	{
		m_Pos.y = 720.f - m_Size.y;
		m_Dir.y = -1.f;
	}

	else if (m_Pos.y <= 0.f)
	{
		m_Pos.y = 0.f;
		m_Dir.y = 1.f;
	}

	/*
	���Ͱ� ���� �ð����� �ѹ��� �Ѿ��� �������� �߻��ϰ� ��������.
	*/
}

void CMonster::PostUpdate(float DeltaTime)
{
	CCharacter::PostUpdate(DeltaTime);
}

void CMonster::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CMonster::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}

CMonster* CMonster::Clone()
{
	return new CMonster(*this);
}