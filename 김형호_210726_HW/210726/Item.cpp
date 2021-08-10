#include "Item.h"

CItem::CItem() : m_Name{}, m_Type(IT_Weapon), m_Option(0), m_Price(0), m_Sell(0)
{
}

CItem::~CItem()
{
}

bool CItem::Init(const char* Name, Item_Type Type, int Option, int Price, int Sell, const char* Desc)
{
	strcpy_s(m_Name, Name);
	m_Type = Type;
	m_Option = Option;
	m_Price = Price;
	m_Sell = Sell;
	strcpy_s(m_Desc, Desc);

	return true;
}

void CItem::Output()
{
	switch (m_Type) // 아이템 타입별로 분류
	{
	case IT_Weapon:
		std::cout << "이름: " << m_Name << "\n공격력: " << m_Option <<std::endl;
		std::cout << "구입가격: " << m_Price << "\t판매가격: " << m_Sell << std::endl;
		std::cout << m_Desc << std::endl;
		break;

	case IT_Armor:
		std::cout << "이름: " << m_Name << "\n방어력: " << m_Option << std::endl;
		std::cout << "구입가격: " << m_Price << "\t판매가격: " << m_Sell << std::endl;
		std::cout << m_Desc << std::endl;
		break;
	
	}
}
