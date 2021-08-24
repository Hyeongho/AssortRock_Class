#pragma once
#include "Character.h"
#include "Bullet.h"

class CPlayer :
    public CCharacter
{
	friend class CScene;

public:
	CPlayer();
	CPlayer(const CPlayer& obj);
	virtual ~CPlayer();

protected:
	bool m_Skill1Enable;
	float m_Skill1Time;
	std::list<CSharedPtr<CBullet>> m_Skill1BulletList;

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CPlayer* Clone();

public:
	void MoveUp(float DeltaTime);
	void MoveDown(float DeltaTime);
	void MoveLeft(float DeltaTime);
	void MoveRight(float DeltaTime);
	void BulleFire(float DeltaTime);
	void Pause(float DeltaTime);
	void Resume(float DeltaTime);
	void Skill1(float DeltaTime);
};

