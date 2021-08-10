#pragma once

#include "Game.h"

class CItem
{
public:
	CItem();
	~CItem();

private:
	char m_Name[32];
	Item_Type m_Type;
	int m_Option;
	int m_Price;
	int m_Sell;
	char m_Desc[512];

public:
	bool Init(const char* Name, Item_Type Type, int Option, int Price, int Sell, const char* Desc);

	void Output(); // 상점에서 아이템 정보를 출력 해줌
};

