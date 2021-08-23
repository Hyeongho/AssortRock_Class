#pragma once
#include "GameObject.h"
class CBullet :
    public CGameObject
{
	friend class CScene;

protected:
	CBullet();
	CBullet(const CBullet& obj);
	virtual ~CBullet();

protected:
	Vector2		m_Dir;
	float		m_Speed;
	float		m_Distance;

public:
	void SetDir(float x, float y)
	{
		m_Dir.x = x;
		m_Dir.y = y;
	}

	void SetSpeed(float Speed)
	{
		m_Speed = Speed;
	}

	void SetDistance(float Distance)
	{
		m_Distance = Distance;
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CBullet* Clone();
};

