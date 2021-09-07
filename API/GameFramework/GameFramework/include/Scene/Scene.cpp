#include "Scene.h"
#include "SceneResource.h"
#include "SceneCollision.h"
#include "Camera.h"

CScene::CScene()
{
	m_Resource = new CSceneResource;
	m_Collision = new CSceneCollision;
	m_RenderCount = 0;
	m_RenderCapacity = 100;
	m_RenderArray = new CGameObject * [m_RenderCapacity];

	m_Camera = new CCamera;

	m_Camera->Init();
}

CScene::~CScene()
{
	SAFE_DELETE(m_Camera);
	SAFE_DELETE_ARRAY(m_RenderArray);

	m_ObjList.clear();

	m_mapPrototype.clear();

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

CCamera* CScene::GetCamera() const
{
	return m_Camera;
}

CGameObject* CScene::FindObject(const std::string& Name)
{
	auto iter = m_ObjList.begin();
	auto iterEnd = m_ObjList.end();

	for (; iter != iterEnd; iter++)
	{
		if ((*iter)->GetName() == Name)
		{
			return *iter;
		}
	}

	return nullptr;
}

void CScene::SetPlayer(const std::string& Name)
{
	CGameObject* Player = FindObject(Name);

	SetPlayer(Player);

}

void CScene::SetPlayer(CGameObject* Player)
{
	m_Player = Player;

	auto iter = m_ObjList.begin();
	auto iterEnd = m_ObjList.end();

	for (; iter != iterEnd; iter++)
	{
		if (*iter == Player)
		{
			m_ObjList.erase(iter);

			break;
		}
	}
}

bool CScene::Init()
{
	return true;
}

bool CScene::Update(float DeltaTime)
{
	m_Player->Update(DeltaTime);

	{
		auto iter = m_ObjList.begin();
		auto iterEnd = m_ObjList.end();

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
	}

	{
		auto iter = m_UIList.begin();
		auto iterEnd = m_UIList.end();

		for (; iter != iterEnd;)
		{
			if (!(*iter)->IsActive())
			{
				iter = m_UIList.erase(iter);
				iterEnd = m_UIList.end();
				continue;
			}

			(*iter)->Update(DeltaTime);

			iter++;
		}
	}

	return false;
	
}

bool CScene::PostUpdate(float DeltaTime)
{
	m_Player->PostUpdate(DeltaTime);

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
	}
	
	{
		auto iter = m_UIList.begin();
		auto iterEnd = m_UIList.end();

		for (; iter != iterEnd;)
		{
			if (!(*iter)->IsActive())
			{
				iter = m_UIList.erase(iter);
				iterEnd = m_UIList.end();
				continue;
			}

			(*iter)->PostUpdate(DeltaTime);

			iter++;
		}
	}

	m_Camera->Update(DeltaTime);

	return false;
}

bool CScene::Collision(float DeltaTime)
{
	m_Player->Collision(DeltaTime);

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
	}

	{
		auto iter = m_UIList.begin();
		auto iterEnd = m_UIList.end();

		for (; iter != iterEnd;)
		{
			if (!(*iter)->IsActive())
			{
				iter = m_UIList.erase(iter);
				iterEnd = m_UIList.end();
				continue;
			}

			(*iter)->Collision(DeltaTime);

			iter++;
		}
	}

	m_Collision->Collision(DeltaTime);

	return false;
}

bool CScene::Render(HDC hDC)
{
	m_Player->PrevRender();

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

			(*iter)->PrevRender();

			if (!(*iter)->IsCull())
			{
				if (m_RenderCount == m_RenderCapacity)
				{
					m_RenderCapacity *= 2;

					CGameObject** Array = new CGameObject * [m_RenderCapacity];

					memcpy(Array, m_RenderArray, sizeof(CGameObject*) * m_RenderCount);

					delete[] m_RenderArray;

					m_RenderArray = Array;
				}

				m_RenderArray[m_RenderCount] = *iter;
				m_RenderCount++;
			}

			iter++;
		}
	}

	if (m_RenderCount == m_RenderCapacity)
	{
		m_RenderCapacity *= 2;

		CGameObject** Array = new CGameObject * [m_RenderCapacity];

		memcpy(Array, m_RenderArray, sizeof(CGameObject*) * m_RenderCount);

		delete[] m_RenderArray;

		m_RenderArray = Array;
	}

	m_RenderArray[m_RenderCount] = m_Player;
	m_RenderCount++;

	{
		m_RenderCount = 0;

		// 출력 전에 리스트를 정렬한다.

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
	}

	{
		auto iter = m_UIList.begin();
		auto iterEnd = m_UIList.end();

		for (; iter != iterEnd;)
		{
			if (!(*iter)->IsActive())
			{
				iter = m_UIList.erase(iter);
				iterEnd = m_UIList.end();
				continue;
			}

			(*iter)->Render(hDC);

			iter++;
		}
	}

	return false;
}

CGameObject* CScene::FindPrototype(const std::string& Name)
{
	auto iter = m_mapPrototype.find(Name);

	if (iter == m_mapPrototype.end())
	{
		return nullptr;
	}

	return iter->second;
}
