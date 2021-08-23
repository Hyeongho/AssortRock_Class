
#include "Character.h"

CCharacter::CCharacter()
{
}

CCharacter::CCharacter(const CCharacter& obj) :
	CGameObject(obj)
{
}

CCharacter::~CCharacter()
{
}

bool CCharacter::Init()
{
	if (!CGameObject::Init())
		return false;

	return true;
}

void CCharacter::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CCharacter::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CCharacter::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CCharacter::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CCharacter* CCharacter::Clone()
{
	return nullptr;
}
