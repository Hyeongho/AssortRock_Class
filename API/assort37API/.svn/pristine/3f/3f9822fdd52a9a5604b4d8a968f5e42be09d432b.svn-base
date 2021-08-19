#pragma once

#include "../Ref.h"

class CGameObject	:
	public CRef
{
public:
	CGameObject();
	virtual ~CGameObject();

private:
	Vector2		m_Pos;
	Vector2		m_Size;

public:
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
};

