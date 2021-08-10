#pragma once

#include "Game.h"

class CStore
{
public:
	CStore();
	~CStore();

private:
	class CItem* CreateItem(const char* Name, Item_Type Type, int Option, int Price, int Sell, const char* Desc);

	Store_Type m_Type;
	class CItem* m_Item[3];

private:
	void SetWeaponList();
	void SetArmorList();

	Transaction Menu(); // 상점 구매 메뉴

public:
	bool Init(Store_Type Type);

	void Run();
};

