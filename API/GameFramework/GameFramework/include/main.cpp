#include "GameManager.h"

#include "resource.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    CGameManager::GetInst();

    if (!CGameManager::GetInst()->Init(hInstance))
    {
        CGameManager::DestroyInst();
        return 0;
    }

    CGameManager::GetInst()->run();

    CGameManager::DestroyInst();

	return 0;
}