#pragma once

#include "../Ref.h"

class CCollider :
	public CRef
{
	friend class CGameObject;

protected:
	CCollider();
	CCollider(const CCollider& collider);
	virtual ~CCollider() = 0;

protected:
	class CScene* m_Scene;
	class CGameObject* m_Owner;
	ECollider_Type  m_Type;
	Vector2	m_Offset;
	bool	m_Enable;
	CollisionProfile* m_Profile;
	std::function<void(CCollider*, CCollider*, float)>	m_BeginFunction;
	std::function<void(CCollider*, CCollider*, float)>	m_EndFunction;

	std::list<CSharedPtr<CCollider>>	m_CollisionList;

public:
	void SetEnable(bool Enable)
	{
		m_Enable = Enable;
	}

	void SetOffset(const Vector2& Offset)
	{
		m_Offset = Offset;
	}

	void SetOffset(float x, float y)
	{
		m_Offset = Vector2(x, y);
	}

	void SetScene(class CScene* Scene)
	{
		m_Scene = Scene;
	}

	void SetOwner(class CGameObject* Owner)
	{
		m_Owner = Owner;
	}

public:
	bool GetEnable()	const
	{
		return m_Enable;
	}

	class CGameObject* GetOwner()	const
	{
		return m_Owner;
	}

	class CScene* GetScene()	const
	{
		return m_Scene;
	}

	ECollider_Type GetColliderType()	const
	{
		return m_Type;
	}

	CollisionProfile* GetProfile()	const
	{
		return m_Profile;
	}

public:
	void SetCollisionProfile(const std::string& Name);
	void AddCollisionList(CCollider* Collider);
	bool CheckCollisionList(CCollider* Collider);
	void DeleteCollisionList(CCollider* Collider);
	void ClearCollisionList();
	void CallCollisionBegin(CCollider* Dest, float DeltaTime);
	void CallCollisionEnd(CCollider* Dest, float DeltaTime);

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CCollider* Clone();
	virtual bool Collision(CCollider* Dest) = 0;

public:
	template <typename T>
	void SetCollisionBeginFunction(T* Obj, void(T::* Func)(CCollider*, CCollider*, float))
	{
		m_BeginFunction = std::bind(Func, Obj, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	}

	template <typename T>
	void SetCollisionEndFunction(T* Obj, void(T::* Func)(CCollider*, CCollider*, float))
	{
		m_EndFunction = std::bind(Func, Obj, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	}
};
