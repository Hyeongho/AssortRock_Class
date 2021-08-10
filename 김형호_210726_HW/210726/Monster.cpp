#include "Monster.h"

CMonster::CMonster() : m_Name{}, m_Attack(0), m_Armor(0), m_HP(0), m_HPMax(0), m_MP(0), m_MPMax(0), m_Level(0), m_Exp(0), m_Gold(0)
{
}

CMonster::CMonster(const CMonster& monster)
{
	// ��� �����͸� ��������� ó�����ش�.
	*this = monster;
}

CMonster::~CMonster()
{
}

bool CMonster::Init(const char* pName, int Attack, int Armor, int HP, int MP, int Level, int Exp, int Gold)
{
	// ���ڿ��� �����Ѵ�.
	strcpy_s(m_Name, pName);
	m_Attack = Attack;
	m_Armor = Armor;
	m_HP = HP;
	m_HPMax = HP;
	m_MP = MP;
	m_MPMax = MP;
	m_Level = Level;
	m_Exp = Exp;
	m_Gold = Gold;

	return true;
}

CMonster* CMonster::Clone()
{
	// �� �Լ��� ȣ���� ��ü�� ������ ���ο� ��ü�� ���� ��ȯ�Ѵ�.
	return new CMonster(*this);
}

void CMonster::Output()
{
	std::cout << "�̸�: " << m_Name << std::endl;
	std::cout << "����: " << m_Level << " \tȹ�����ġ: " << m_Exp << std::endl;
	std::cout << "���ݷ�: " << m_Attack << "\t����: " << m_Armor << std::endl;
	std::cout << "ü��: " << m_HP << " / " << m_HPMax << "\t ����: " << m_MP << " / " << m_MPMax << std::endl;
	std::cout << "ȹ��ݾ�: " << m_Gold << std::endl;
}

bool CMonster::Damage(int Damage)
{
	m_HP -= Damage;

	if (m_HP <= 0)
	{
		return true;
	}

	return false;
}
