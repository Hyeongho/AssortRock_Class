#include "Map.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "Inventory.h"

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
		return CObjectManager::GetInst()->CloneMonster("���");

	case MT_Normal:
		return CObjectManager::GetInst()->CloneMonster("��ũ");

	case MT_Hard:
		return CObjectManager::GetInst()->CloneMonster("�巡��");
	}

	return nullptr;
}

Battle_Menu CMap::Menu()
{
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
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
	// Damage���
	int Attack = pPlayer->GetAttack();

	if (pPlayer->GetEquipItem(Equip_Weapon))
	{
		Attack += pPlayer->GetEquipItem(Equip_Weapon)->GetOption();
	}

	int Damage = Attack - pMonster->GetArmor();

	// ? ������ ������ true�� ��� : ������ ���� ��ȯ�ǰ� false�� ��� : �������� ���� ��ȯ�ȴ�.
	Damage = Damage < 1 ? 1 : Damage;

	// ���Ͱ� �׾��� ���
	if (pMonster->Damage(Damage))
	{
		return BattleResult::Monster_Death;
	}

	int Armor = pPlayer->GetArmor();

	if (pPlayer->GetEquipItem(Equip_Armor))
	{
		Armor += pPlayer->GetEquipItem(Equip_Armor)->GetOption();
	}

	Damage = Attack - pMonster->GetArmor();

	Damage = pMonster->GetAttack() - Armor;

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

				// Item Drop �з��� ����Ѵ�.
				if (!CInventory::GetInst()->IsFull())
				{
					float Percent = rand() % 10001 / 100.f;

					if (Percent < 10.f)
					{
						int Index = -1;

						if (rand() % 2 == 0)
						{
							Index = (int)m_Type * 2;
						}

						else
						{
							Index = (int)m_Type * 2 + 1;
						}

						CItem* DropItem = CObjectManager::GetInst()->CloneItem(Index);

						CInventory::GetInst()->AddItem(DropItem);

						std::cout << DropItem->GetName() << " Item ȹ��" << std::endl;
					}
				}

				delete pMonster;

				pMonster = SpawnMonster();

				system("pause");
			}

				break;
			case BattleResult::Player_Death:
				pPlayer->Death();
				break;

			}

			break;

		case Battle_Menu::Back:
			// ���ʹ� ������ ������ ���ο� ���͸� �����Ҵ��ؼ� ����� ��� ������ �ݵ�� �޸𸮸� �����ؾ� �Ѵ�.
			delete pMonster;
			return;
		}
	}
}
