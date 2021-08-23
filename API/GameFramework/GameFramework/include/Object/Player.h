#pragma once
#include "Character.h"
class CPlayer :
    public CCharacter
{
	friend class CScene;

public:
	CPlayer();
	CPlayer(const CPlayer& obj);
	virtual ~CPlayer();

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CPlayer* Clone();
};

