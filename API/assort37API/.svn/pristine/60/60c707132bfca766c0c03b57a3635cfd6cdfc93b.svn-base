
#include "SceneManager.h"
#include "Scene.h"

CSceneManager* CSceneManager::m_Inst = nullptr;

CSceneManager::CSceneManager()	:
	m_Scene(nullptr)
{
}

CSceneManager::~CSceneManager()
{
	SAFE_DELETE(m_Scene);
}

bool CSceneManager::Init()
{
	m_Scene = new CScene;

	m_Scene->Init();

	return true;
}

bool CSceneManager::Update(float DeltaTime)
{
	m_Scene->Update(DeltaTime);

	return false;
}

bool CSceneManager::PostUpdate(float DeltaTime)
{
	m_Scene->PostUpdate(DeltaTime);

	return false;
}

bool CSceneManager::Collision(float DeltaTime)
{
	m_Scene->Collision(DeltaTime);

	return false;
}

bool CSceneManager::Render(HDC hDC)
{
	m_Scene->Render(hDC);

	return false;
}
