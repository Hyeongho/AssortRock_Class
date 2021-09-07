#pragma once

#include "../GameInfo.h"
#include "../Object/GameObject.h"
#include "../UI/UIWindow.h"

class CScene
{
	friend class CSceneManager;

protected:
	CScene();
	virtual ~CScene();

private:
	class CSceneResource* m_Resource;
	class CSceneCollision* m_Collision;
	class CCamera* m_Camera;

public:
	class CSceneResource* GetSceneResource() const;
	class CSceneCollision* GetSceneCollision() const;
	class CCamera* GetCamera() const;

private:
	CSharedPtr<CGameObject> m_Player;
	std::list<CSharedPtr<CGameObject>> m_ObjList;
	CGameObject** m_RenderArray;
	int m_RenderCount;
	int m_RenderCapacity;
	std::unordered_map<std::string, CSharedPtr<CGameObject>> m_mapPrototype;
	std::list<CSharedPtr<CUIWindow>> m_UIList;

public:
	CGameObject* FindObject(const std::string& Name);
	void SetPlayer(const std::string& Name);
	void SetPlayer(CGameObject* Player);
	CGameObject* GetPlayer() const
	{
		return m_Player;
	}

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);
	virtual bool Collision(float DeltaTime);
	virtual bool Render(HDC hDC);

public:
	static bool SortObject(CSharedPtr<CGameObject> Src, CSharedPtr<CGameObject> Dest);
	static bool SortUI(CSharedPtr<CUIWindow> Src, CSharedPtr<CUIWindow> Dest);

private:
	CGameObject* FindPrototype(const std::string& Name);

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

		Obj->Start();

		m_ObjList.push_back(Obj);

		return Obj;
	}

	template <typename T>
	T* CreatePrototype(const std::string& Name)
	{
		T* Obj = new T;

		Obj->SetScene(this);
		Obj->SetName(Name);

		if (!Obj->Init())
		{
			SAFE_DELETE(Obj);
			return nullptr;
		}

		m_mapPrototype.insert(std::make_pair(Name, Obj));

		return Obj;
	}

	template <typename T>
	T* CreateObject(const std::string& Name, const std::string& PrototypeName, const Vector2& Pos = Vector2(0.f, 0.f), const Vector2 Size = Vector2(100.f, 100.f))
	{
		CGameObject* Prototype = FindPrototype(PrototypeName);

		if (!Prototype)
			return nullptr;

		T* Obj = (T*)Prototype->Clone();

		Obj->SetScene(this);
		Obj->SetPos(Pos);
		Obj->SetSize(Size);
		Obj->SetName(Name);
		Obj->Start();

		m_ObjList.push_back(Obj);

		return Obj;
	}

	template <typename T>
	T* CreateUIWindow(const std::string& Name)
	{
		T* Window = new T;

		Window->SetName(Name);
		Window->SetScene(this);

		if (!Window->Init())
		{
			SAFE_DELETE(Window);

			return nullptr;
		}

		m_UIList.push_back(Window);

		return Window;
	}
};

