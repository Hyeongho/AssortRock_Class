#include "Tile.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"

CTile::CTile() : m_IndexX(0), m_IndexY(0), m_Index(0)
{
}

CTile::~CTile()
{
}

bool CTile::Init()
{
	return true;
}

void CTile::Update(float DeltaTime)
{
}

void CTile::PostUpdate(float DeltaTime)
{
}

void CTile::PrevRender()
{
}

void CTile::Render(HDC hDC)
{
	if (m_Texture)
	{
		CCamera* Camera = CSceneManager::GetInst()->GetScene()->GetCamera();

		Vector2 CameraPos = Camera->GetPos();

		m_Texture->Render(hDC, m_Pos - CameraPos, Vector2(0.f, 0.f), m_Size);
	}
}
