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
	m_Item[0] = CreateItem("목검", IT_Weapon, 50, 1000, 500, "나무로 만든 검");
	m_Item[1] = CreateItem("B.F.대검", IT_Weapon, 200, 8000, 4000, "조금 센 검");
	m_Item[2] = CreateItem("무한의 대검", IT_Weapon, 600, 40000, 20000, "치명타 맞고 죽어라.");
}

void CStore::SetArmorList()
{
	m_Item[0] = CreateItem("천갑옷", IT_Armor, 50, 1000, 500, "약한 방어구");
	m_Item[1] = CreateItem("거인의 벨트", IT_Armor, 100, 8000, 4000, "조금 단단한 벨트");
	m_Item[2] = CreateItem("가시갑옷", IT_Armor, 600, 40000, 20000, "구른다!!");
}

Transaction CStore::Menu()
{
	std::cout << "1. 구매" << std::endl;
	std::cout << "2. 판매" << std::endl;
	std::cout << "3. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
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
	// 상점에서 판매할 아이템 목록을 출력하는 코드 작성

	while (true)
	{
		system("cls");

		switch (m_Type) // Store_Type 타입별로 처리를 해서 상점에 있는 아이템 정보 출력
		{
		case ST_Weapon:
			std::cout << "=============================== 무기상점===============================" << std::endl;

			for (int i = 0; i < 3; i++)
			{
				m_Item[i]->Output();

				std::cout << std::endl;
			}

			break;

		case ST_Armor:
			std::cout << "=============================== 방어구상점 ===============================" << std::endl;

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
