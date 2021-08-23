#include "MainScene.h"
#include "../Object/Player.h"
#include "../Object/Bullet.h"
#include "../Object/Monster.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	CPlayer* Player = CreateObject<CPlayer>("Player");

	CMonster* Monster = CreateObject<CMonster>("Monster", Vector2(1000.0f, 100.f));

	return true;
}
