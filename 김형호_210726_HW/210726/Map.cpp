#include "Map.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

CMap::CMap()
{
}

CMap::~CMap()
{
}

CMonster* CMap::SpawnMonster()
{
	switch (m_Type)
	{
	case MT_Easy:
		return CObjectManager::GetInst()->CloneMonster("고블린");

	case MT_Normal:
		return CObjectManager::GetInst()->CloneMonster("오크");

	case MT_Hard:
		return CObjectManager::GetInst()->CloneMonster("드래곤");
	}

	return nullptr;
}

Battle_Menu CMap::Menu()
{
	std::cout << "1. 공격" << std::endl;
	std::cout << "2. ㅌㅌ" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int _Menu = 0;

	std::cin >> _Menu;

	if (_Menu <= (int)Battle_Menu::None || _Menu > (int)Battle_Menu::Back)
	{
		return Battle_Menu::None;
	}

	return (Battle_Menu)_Menu;

}

BattleResult CMap::Battle(CPlayer* pPlayer, CMonster* pMonster)
{
	// Damage계산
	int Damage = pPlayer->GetAttack() - pMonster->GetArmor();

	// ? 왼쪽의 조건이 true일 경우 : 왼쪽의 값이 반환되고 false일 경우 : 오른쪽의 값이 반환된다.
	Damage = Damage < 1 ? 1 : Damage;

	// 몬스터가 죽었을 경우
	if (pMonster->Damage(Damage))
	{
		return BattleResult::Monster_Death;
	}

	Damage = pMonster->GetAttack() - pPlayer->GetArmor();

	Damage = Damage < 1 ? 1 : Damage;

	if (pPlayer->Damage(Damage))
	{
		return BattleResult::Player_Death;
	}

	return BattleResult::None;
}

bool CMap::Init(Map_Type Type)
{
	m_Type = Type;

	return true;
}

void CMap::Run()
{
	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();
	CMonster* pMonster = SpawnMonster();

	while (true)
	{
		system("cls");

		std::cout << "===================================== Player =====================================" << std::endl;
		pPlayer->Output();
		std::cout << std::endl;

		std::cout << "===================================== Monster =====================================" << std::endl;
		pMonster->Output();
		std::cout << std::endl;

		switch (Menu())
		{
		case Battle_Menu::Attack:
			switch (Battle(pPlayer, pMonster))
			{
			case BattleResult::Monster_Death:
			{
				pPlayer->AddExp(pMonster->GetExp());
				pPlayer->AddGold(pMonster->GetGold());

				delete pMonster;

				pMonster = SpawnMonster();
			}

				break;
			case BattleResult::Player_Death:
				pPlayer->Death();
				break;

			}

			break;

		case Battle_Menu::Back:
			// 몬스터는 원본을 복제한 새로운 몬스터를 동적할당해서 만들어 줬기 떄문에 반드시 메모리를 제거해야 한다.
			delete pMonster;
			return;
		}
	}
}
