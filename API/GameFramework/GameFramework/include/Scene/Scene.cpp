#include "Scene.h"
#include "SceneResource.h"
#include "SceneCollision.h"

CScene::CScene()
{
	m_Resource = new CSceneResource;
	m_Collision = new CSceneCollision;
}

CScene::~CScene()
{
	m_ObjList.clear();

	SAFE_DELETE(m_Resource);
	SAFE_DELETE(m_Collision);
}

CSceneResource* CScene::GetSceneResource() const
{
	return m_Resource;
}

CSceneCollision* CScene::GetSceneCollision() const
{
	return m_Collision;
}

bool CScene::Init()
{
	return true;
}

bool CScene::Update(float DeltaTime)
{
	std::list<CSharedPtr<CGameObject>>::iterator iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Update(DeltaTime * (*iter)->m_TimeScale);

		iter++;
	}

	return false;
}

bool CScene::PostUpdate(float DeltaTime)
{
	std::list<CSharedPtr<CGameObject>>::iterator iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->PostUpdate(DeltaTime * (*iter)->m_TimeScale);

		iter++;
	}

	return false;
}

bool CScene::Collision(float DeltaTime)
{
	std::list<CSharedPtr<CGameObject>>::iterator iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Collision(DeltaTime * (*iter)->m_TimeScale);

		iter++;
	}

	m_Collision->Collision(DeltaTime);

	return false;
}

bool CScene::Render(HDC hDC)
{
	std::list<CSharedPtr<CGameObject>>::iterator iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Render(hDC);

		iter++;
	}

	return false;
}
