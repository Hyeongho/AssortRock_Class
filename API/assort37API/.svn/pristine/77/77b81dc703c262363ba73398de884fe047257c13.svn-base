#pragma once
#include "Collider.h"
class CColliderSphere :
    public CCollider
{
	friend class CGameObject;

protected:
	CColliderSphere();
	CColliderSphere(const CColliderSphere& collider);
	virtual ~CColliderSphere();

protected:
	SphereInfo	m_Info;

public:
	void SetRadius(float Radius)
	{
		m_Info.Radius = Radius;
	}

	SphereInfo GetInfo()	const
	{
		return m_Info;
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CColliderSphere* Clone();
	virtual bool Collision(CCollider* Dest);
};

