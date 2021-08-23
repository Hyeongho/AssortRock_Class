#pragma once
#include "GameObject.h"
class CCharacter :
    public CGameObject
{
	friend class CScene;

public:
	CCharacter();
	CCharacter(const CCharacter& obj);
	virtual ~CCharacter();

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CCharacter* Clone();
};

