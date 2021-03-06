#pragma once

#include "Game.h"

class CObjectManager
{
private:
	CObjectManager();
	~CObjectManager();

public:
	bool Init();

	//몬스터의 이름으로 탐색해서 이몬스터를 이용해서 복제된 새로운 몬스터를 생성할 수 있게 한다.
	class CMonster* CloneMonster(const char* pName);

	void Run();

private:
	class CPlayer* m_pPlayer;
	class CMonster* m_pMonster[3];

	int m_LevelUpExp[LEVEL_MAX];

public:
	class CPlayer* GetPlayer()
	{
		return m_pPlayer;
	}

	int GetLevelUpExp(int Level)
	{
		return m_LevelUpExp[Level - 1];
	}

private:
	static CObjectManager* m_pInst;

public:
	static CObjectManager* GetInst()
	{
		if (m_pInst == nullptr)
		{
			m_pInst = new CObjectManager;
		}

		return m_pInst;
	}

	static void DestroyInst()
	{
		if (m_pInst)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}
	}
};

