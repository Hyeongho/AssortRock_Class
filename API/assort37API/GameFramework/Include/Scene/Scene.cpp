
#include "Scene.h"
#include "../Object/GameObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	// 생성된 모든 오브젝트들을 반복하며 메모리에서 제거한다.
	std::list<CGameObject*>::iterator	iter = m_ObjList.begin();
	std::list<CGameObject*>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd; ++iter)
	{
		SAFE_DELETE((*iter));
	}
}

bool CScene::Init()
{
	return true;
}

bool CScene::Update(float DeltaTime)
{
	std::list<CGameObject*>::iterator	iter = m_ObjList.begin();
	std::list<CGameObject*>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			SAFE_DELETE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Update(DeltaTime);
		++iter;
	}

	return false;
}

bool CScene::PostUpdate(float DeltaTime)
{
	std::list<CGameObject*>::iterator	iter = m_ObjList.begin();
	std::list<CGameObject*>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			SAFE_DELETE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->PostUpdate(DeltaTime);
		++iter;
	}

	return false;
}

bool CScene::Collision(float DeltaTime)
{
	std::list<CGameObject*>::iterator	iter = m_ObjList.begin();
	std::list<CGameObject*>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			SAFE_DELETE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Collision(DeltaTime);
		++iter;
	}

	return false;
}

bool CScene::Render(HDC hDC)
{
	std::list<CGameObject*>::iterator	iter = m_ObjList.begin();
	std::list<CGameObject*>::iterator	iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		if (!(*iter)->IsActive())
		{
			SAFE_DELETE((*iter));
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}

		(*iter)->Render(hDC);
		++iter;
	}

	return false;
}
