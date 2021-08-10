#include "Store.h"
#include "Item.h"

CStore::CStore() : m_Type(ST_Weapon), m_Item{}
{
}

CStore::~CStore()
{
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

Transaction CStore::Menu()
{
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �Ǹ�" << std::endl;
	std::cout << "3. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int _Menu = 0;

	std::cin >> _Menu;

	if (_Menu <= (int)Transaction::None || _Menu > (int)Transaction::Back)
	{
		return Transaction::None;
	}

	return (Transaction)_Menu;
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
	// �������� �Ǹ��� ������ ����� ����ϴ� �ڵ� �ۼ�

	while (true)
	{
		system("cls");

		switch (m_Type) // Store_Type Ÿ�Ժ��� ó���� �ؼ� ������ �ִ� ������ ���� ���
		{
		case ST_Weapon:
			std::cout << "=============================== �������===============================" << std::endl;

			for (int i = 0; i < 3; i++)
			{
				m_Item[i]->Output();

				std::cout << std::endl;
			}

			break;

		case ST_Armor:
			std::cout << "=============================== ������ ===============================" << std::endl;

			for (int i = 0; i < 3; i++)
			{
				m_Item[i]->Output();

				std::cout << std::endl;
			}

			break;
		}

		switch (Menu())
		{
		case Transaction::Buy:
			break;
		case Transaction::Sale:
			break;
		case Transaction::Back:
			return;
		}
	}
}
