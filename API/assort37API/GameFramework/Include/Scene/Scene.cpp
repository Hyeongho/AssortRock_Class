
#include "Scene.h"
#include "SceneResource.h"

CScene::CScene()
{
	m_Resource = new CSceneResource;

}

CScene::~CScene()
{
	m_ObjList.clear();

	SAFE_DELETE(m_Resource);
}

CSceneResource* CScene::GetSceneResource() const
{
	return m_Resource;
}

bool CScene::Init()
{
	return true;
}

bool CScene::Update(float DeltaTime)
{
	auto	iter = m_ObjList.begin();
	auto	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Update(DeltaTime * (*iter)->m_TimeScale);
		++iter;
	}

	return false;
}

bool CScene::PostUpdate(float DeltaTime)
{
	std::list<CSharedPtr<CGameObject>>::iterator	iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->PostUpdate(DeltaTime * (*iter)->m_TimeScale);
		++iter;
	}

	return false;
}

bool CScene::Collision(float DeltaTime)
{
	std::list<CSharedPtr<CGameObject>>::iterator	iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Collision(DeltaTime * (*iter)->m_TimeScale);
		++iter;
	}

	return false;
}

bool CScene::Render(HDC hDC)
{
	std::list<CSharedPtr<CGameObject>>::iterator	iter = m_ObjList.begin();
	std::list<CSharedPtr<CGameObject>>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Render(hDC);
		++iter;
	}

	return false;
}
