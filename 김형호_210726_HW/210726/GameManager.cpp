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
	// �޸𸮸� �����Ѵ�.
	CMapManager::DestroyInst();

	CObjectManager::DestroyInst();

	CStoreManager::DestroyInst();
}

Main_Menu CGameManager::Meun()
{
	system("cls");

	std::cout << "1. ��" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. �κ��丮" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ���: ";

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

	// ������Ʈ ������ �ʱ�ȭ
	if (!CObjectManager::GetInst()->Init())
	{
		return false;
	}

	// ���������� �ʱ�ȭ
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
