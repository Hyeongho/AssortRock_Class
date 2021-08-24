#pragma once

#include "../Ref.h"

class CGameObject : public CRef
{
	friend class CScene;

public:
	CGameObject();
	CGameObject(const CGameObject& obj);
	virtual ~CGameObject();

protected:
	class CScene* m_Scene;
	Vector2 m_PrevPos;
	Vector2 m_Pos;
	Vector2 m_Size;
	Vector2 m_Pivot;
	Vector2 m_Velocitry;
	float m_MoveSpeed;
	float m_TimeScale;

public:
	Vector2 GetPos() const
	{
		return m_Pos;
	}

	Vector2 GetSize() const
	{
		return m_Size;
	}

	Vector2 GetPivot() const
	{
		return m_Pivot;
	}

	Vector2 GetVelocity() const
	{
		return m_Velocitry;
	}

	float GetMoveSpeed() const
	{
		return m_MoveSpeed;
	}

	float GetMoveSpeedFrame() const
	{
		return m_Velocitry.Length();
	}

public:
	void SetScene(class CScene* Scene)
	{
		m_Scene = Scene;
	}

	void SetPos(float x, float y)
	{
		m_Pos.x = x;
		m_Pos.y = y;
	}

	void SetPos(const Vector2& Pos)
	{
		m_Pos = Pos;
	}

	void SetSize(float x, float y)
	{
		m_Size.x = x;
		m_Size.y = y;
	}

	void SetSize(const Vector2& Size)
	{
		m_Size = Size;
	}

	void SetPivot(float x, float y)
	{
		m_Pivot.x = x;
		m_Pivot.y = y;
	}

	void SetPivot(const Vector2& Pivot)
	{
		m_Pivot = Pivot;
	}

	void SetMoveSpeed(float Speed)
	{
		m_MoveSpeed = Speed;
	}

	void SetTimeScale(float TimeScale)
	{
		m_TimeScale = TimeScale;
	}

	void Move(const Vector2& Dir);
	void Move(const Vector2& Dir, float Speed);

	
public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CGameObject* Clone();
};
