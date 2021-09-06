#pragma once

#include "../GameInfo.h"
#include "../Object/GameObject.h"

class CScene
{
	friend class CSceneManager;

protected:
	CScene();
	virtual ~CScene();

private:
	class CSceneResource* m_Resource;
	class CSceneCollision* m_Collision;

public:
	class CSceneResource* GetSceneResource() const;
	class CSceneCollision* GetSceneCollision() const;
	

private:
	std::list<CSharedPtr<CGameObject>> m_ObjList;

public:
	CGameObject* FindObject(const std::string& Name);

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);
	virtual bool Collision(float DeltaTime);
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

