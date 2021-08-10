#include "Store.h"
#include "Item.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Inventory.h"

CStore::CStore() : m_Type(ST_Weapon), m_Item{}
{
}

CStore::~CStore()
{
	for (int i = 0; i < 3; i++)
	{
		delete m_Item[i];
	}
}

CItem* CStore::CreateItem(const char* Name, Item_Type Type, int Option, int Price, int Sell, const char* Desc)
{
	CItem* Item = new CItem;

	Item->Init(Name, Type, Option, Price, Sell, Desc);

	return Item;
}

void CStore::SetWeaponList()
{
	m_Item[0] = CreateItem("���", IT_Weapon, 50, 1000, 500, "������ ���� ��");
	m_Item[1] = CreateItem("B.F.���", IT_Weapon, 200, 8000, 4000, "���� �� ��");
	m_Item[2] = CreateItem("������ ���", IT_Weapon, 600, 40000, 20000, "ġ��Ÿ �°� �׾��.");
}

void CStore::SetArmorList()
{
	m_Item[0] = CreateItem("õ����", IT_Armor, 50, 1000, 500, "���� ��");
	m_Item[1] = CreateItem("������ ��Ʈ", IT_Armor, 100, 8000, 4000, "���� �ܴ��� ��Ʈ");
	m_Item[2] = CreateItem("���ð���", IT_Armor, 600, 40000, 20000, "������!!");
}

int CStore::Menu(CPlayer* Player)
{
	system("cls");

	switch (m_Type)
	{
	case ST_Weapon:
		std::cout << "=========================================== ������� ===========================================" << std::endl;
		break;

	case ST_Armor:
		std::cout << "=========================================== �� ���� ===========================================" << std::endl;
		break;
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << ". ";
		m_Item[i]->Output();
	}

	std::cout << "4. �ڷΰ���" << std::endl;
	std::cout << "�����ݾ�: " << Player->GetGold() << std::endl;
	std::cout << "������ �������� �����ϼ��� : ";
	int Item = 0;

	std::cin >> Item;

	if (Item < 1 || Item > 4)
	{
		return 0;
	}

	return Item;
}

bool CStore::Init(Store_Type Type)
{
    m_Type = Type;

	switch (m_Type)
	{
	case ST_Weapon:
		SetWeaponList();
		break;

	case ST_Armor:
		SetArmorList();
		break;
	}

    return true;
}

void CStore::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	// �������� �Ǹ��� ������ ����� ����ϴ� �ڵ� �ۼ�

	while (true)
	{
		int Item = Menu(Player);

		if (Item == 0)
		{
			continue;
		}

		else if (Item == 4)
		{
			break;
		}

		int Index = Item - 1;

		// �������� ������ �� �ִ��� �Ǵ��ؾ� �Ѵ�.
		// �������� ������ �� ���� ���� �÷��̾ ���� ���� �����ϰų�
		// �κ��丮�� ���̻� ������ ���� ��� �̴�.
		if (Player->GetGold() < m_Item[Index]->GetPrice())
		{
			std::cout << "�ݷ��� �����մϴ�." << std::endl;
			system("pause");
			continue;
		}

		else if (CInventory::GetInst()->IsFull())
		{
			std::cout << "�κ��丮�� ������ �����մϴ�. ĳ���� �κ��丮�� �ø�����." << std::endl;
			system("pause");
			continue;
		}

		// ������� ������ �������� ������ �� �ִٴ� ���� �ȴ�.
		CItem* CloneItem = m_Item[Index]->Clone();

		// �÷��̾��� ���� ���ҽ�Ų��.
		Player->AddGold(-m_Item[Index]->GetPrice());

		// �κ��丮�� ������ �������� �߰����ش�.
		CInventory::GetInst()->AddItem(CloneItem);

		std::cout << "���ſϷ�" << std::endl;
		system("pause");
	}
}
