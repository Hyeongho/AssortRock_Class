#pragma once

#include "../GameInfo.h"
#include "Scene.h"

class CSceneManager
{
private:
	CSceneManager();
	~CSceneManager();

private:
	CScene* m_Scene;

public:
	CScene* GetScene()
	{
		return m_Scene;
	}

public:
	bool Init();
	bool Update(float DelataTime);
	bool PostUpdate(float DelataTime);
	bool Collision(float DelataTime);
	bool Render(HDC hDC);

private:
	static CSceneManager* m_Inst;

public:
	static CSceneManager* GetInst()
	{
		if (!m_Inst)
		{
			m_Inst = new CSceneManager;
		}

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}

public:
	template <typename T>
	bool CreateScene()
	{
		SAFE_DELETE(m_Scene);
		m_Scene = new T;

		if (!m_Scene->Init())
		{
			SAFE_DELETE(m_Scene);
			return false;
		}

		return true;
	}
};

