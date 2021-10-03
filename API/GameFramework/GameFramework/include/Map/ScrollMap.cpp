#include "ScrollMap.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"
#include "../Scene/Camera.h"

CScrollMap::CScrollMap() : m_ScroolRatio(1.f, 1.f)
{
}

CScrollMap::~CScrollMap()
{
}

void CScrollMap::SetTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	m_Scene->GetSceneResource()->LoadTexture(Name, FileName, PathName);

	SetTexture(Name);
}

void CScrollMap::SetTextureFullPath(const std::string& Name, const TCHAR* FullPath)
{
	m_Scene->GetSceneResource()->LoadTextureFullPath(Name, FullPath);

	SetTexture(Name);
}

void CScrollMap::SetTexture(const std::string& Name, const std::vector<std::wstring>& vecFilName, const std::string& PathName)
{
	m_Scene->GetSceneResource()->LoadTexture(Name, vecFilName, PathName);

	SetTexture(Name);
}

void CScrollMap::SetTexture(const std::string& Name)
{
	m_ScrollTexture = m_Scene->GetSceneResource()->FindTexture(Name);
}

void CScrollMap::SetTextureColorKey(const unsigned char r, const unsigned char g, const unsigned char b, int Index)
{
	if (m_ScrollTexture)
	{
		m_ScrollTexture->SetColorKey(r, g, b);
	}
}

void CScrollMap::Start()
{
	CMapBase::Start();
}

bool CScrollMap::Init()
{
	CMapBase::Init();

	return true;
}

void CScrollMap::Update(float DeltaTime)
{
	CMapBase::Update(DeltaTime);
}

void CScrollMap::PostUpdate(float DeltaTime)
{
	CMapBase::PostUpdate(DeltaTime);
}

void CScrollMap::PrevRender()
{
	CMapBase::PrevRender();
}

void CScrollMap::Render(HDC hDC)
{
	CMapBase::Render(hDC);

	if (m_ScrollTexture)
	{
		if (!m_Loop)
		{
			CCamera* Camera = m_Scene->GetCamera();

			Vector2 Resolution = Camera->GetResolution();

			Vector2 ImagePos = Camera->GetPos() * m_ScroolRatio;

			unsigned int Width = m_ScrollTexture->GetWidth();
			unsigned int Height = m_ScrollTexture->GetHeight();

			ImagePos.x = ImagePos.x < 0.f ? 0.f : ImagePos.x;
			ImagePos.x = ImagePos.x + Resolution.x > Width ? Width - Resolution.x : ImagePos.x;

			ImagePos.y = ImagePos.y < 0.f ? 0.f : ImagePos.y;
			ImagePos.y = ImagePos.y + Resolution.y > Height ? Width - Resolution.y : ImagePos.y;

			m_ScrollTexture->Render(hDC, m_Pos, ImagePos, m_Size);
		}

		else
		{
			CCamera* Camera = m_Scene->GetCamera();

			Vector2 CameraPos = Camera->GetPos();

			Vector2 Resolution = Camera->GetResolution();

			Vector2 ImagePos;

			int XRatio = (int)(CameraPos.x / Resolution.x);
			int YRatio = (int)(CameraPos.y / Resolution.y);

			ImagePos.x = CameraPos.x - Resolution.x * XRatio;
			ImagePos.y = CameraPos.y - Resolution.y * XRatio;

			// 화요일에 잘라서 이어붙이기.

			// 왼쪽 출력
			m_ScrollTexture->Render(hDC, m_Pos, ImagePos, m_Size);

			if (ImagePos.x + Resolution.x > (float)m_ScrollTexture->GetWidth())
			{

			}
		}
	}
}

void CScrollMap::Save(FILE* pFile)
{
}

void CScrollMap::Load(FILE* pFile)
{
}
