#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

CObjectManager* CObjectManager::m_pInst = nullptr;

CObjectManager::CObjectManager() : m_pPlayer(nullptr), m_pMonster{}
{
}

CObjectManager::~CObjectManager()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	for (int i = 0; i < 3; i++)
	{
		if (m_pMonster[i])
		{
			delete m_pMonster[i];
		}
	}
}

bool CObjectManager::Init()
{
	// 플레이어를 생성한다.

	m_pPlayer = new CPlayer;

	if (!m_pPlayer->Init())
	{
		return false;
	}

	m_pMonster[0] = new CMonster;
	m_pMonster[0]->Init("고블린", 60, 5, 100, 10, 1, 1000, 500);

	m_pMonster[1] = new CMonster;
	m_pMonster[1]->Init("오크", 200, 100, 1000, 100, 5, 6000, 2500);

	m_pMonster[2] = new CMonster;
	m_pMonster[2]->Init("드래곤", 500, 500, 10000, 10000, 10, 20000, 1000);

	// 경험치 테이블을 만든다.
	m_LevelUpExp[0] = 5000;
	m_LevelUpExp[1] = 12000;
	m_LevelUpExp[2] = 18000;
	m_LevelUpExp[3] = 25000;
	m_LevelUpExp[4] = 40000;
	m_LevelUpExp[5] = 60000;
	m_LevelUpExp[6] = 80000;
	m_LevelUpExp[7] = 100000;
	m_LevelUpExp[8] = 120000;
	m_LevelUpExp[9] = 140000;

	return true;
}

CMonster* CObjectManager::CloneMonster(const char* pName)
{
	// 배열 전체 수만큼 반복하며 이름을 비교해서 몬스터를 찾는다.
	CMonster* pFindMonster = nullptr;

	for (int i = 0; i < 3; i++)
	{
		if (strcmp(m_pMonster[i]->GetName(), pName) == 0)
		{
			pFindMonster = m_pMonster[i];

			break;
		}
	}

	// pFindMonster 가 nullptr이라면 위의 for문에서 원하는 몬스터를 못찾은 것이므로 nullptr을 반환해준다.
	if (pFindMonster == nullptr)
	{
		return nullptr;
	}

	return pFindMonster->Clone();
}

void CObjectManager::Run()
{
}
