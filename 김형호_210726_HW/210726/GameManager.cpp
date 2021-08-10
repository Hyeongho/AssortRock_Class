#include "GameManager.h"
#include "MapManager.h"
#include "ObjectManager.h"
#include "StoreManager.h"

CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	// 메모리를 해제한다.
	CMapManager::DestroyInst();

	CObjectManager::DestroyInst();

	CStoreManager::DestroyInst();
}

Main_Menu CGameManager::Meun()
{
	system("cls");

	std::cout << "1. 맵" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 인벤토리" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요: ";

	int _Meun = 0;

	std::cin >> _Meun;

	if (_Meun <= (int)Main_Menu::None || _Meun > (int)Main_Menu::Exit)
	{
		return Main_Menu::None;
	}

	return (Main_Menu)_Meun;
}

bool CGameManager::Init()
{
	if (!CMapManager::GetInst()->Init())
	{
		return false;
	}

	// 오브젝트 관리자 초기화
	if (!CObjectManager::GetInst()->Init())
	{
		return false;
	}

	// 상점관리자 초기화
	if (!CStoreManager::GetInst()->Init())
	{
		return false;
	}

	return true;
}

void CGameManager::Run()
{
	while (true)
	{
		switch (Meun())
		{
		case Main_Menu::Map:
			CMapManager::GetInst()->Run();
			break;
		case Main_Menu::Store:
			CStoreManager::GetInst()->Run();
			break;
		case Main_Menu::Invertory:
			break;
		case Main_Menu::Exit:
			return;
		default:
			break;
		}
	}
}
