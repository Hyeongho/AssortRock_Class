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
	switch (m_Type) // ������ Ÿ�Ժ��� �з�
	{
	case IT_Weapon:
		std::cout << "�̸�: " << m_Name << "\n���ݷ�: " << m_Option <<std::endl;
		std::cout << "���԰���: " << m_Price << "\t�ǸŰ���: " << m_Sell << std::endl;
		std::cout << m_Desc << std::endl;
		break;

	case IT_Armor:
		std::cout << "�̸�: " << m_Name << "\n����: " << m_Option << std::endl;
		std::cout << "���԰���: " << m_Price << "\t�ǸŰ���: " << m_Sell << std::endl;
		std::cout << m_Desc << std::endl;
		break;
	
	}
}
