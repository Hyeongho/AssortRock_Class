#pragma once

#include "../GameInfo.h"

class CScene
{
	friend class CSceneManager;

protected:
	CScene();
	virtual ~CScene();

private:
	std::list<class CGameObject*> m_ObjList;

public:
	virtual bool Init();
	virtual bool Update(float DelataTime);
	virtual bool PostUpdate(float DelataTime);
	virtual bool Collision(float DelataTime);
	virtual bool Render(HDC hDC);

public:
	template <typename T>
	T* CreateObject(const std::string& Name, const Vector2& Pos = Vector2(0.f, 0.f), const Vector2 Size = Vector2(100.f, 100.f))
	{
		T* Obj = new T;

		Obj->SetScene(this);
		Obj->SetPos(Pos);
		Obj->SetSize(Size);
		Obj->SetName(Name);

		if (!Obj->Init())
		{
			SAFE_DELETE(Obj);
			return nullptr;
		}

		m_ObjList.push_back(Obj);

		return Obj;
	}
};

