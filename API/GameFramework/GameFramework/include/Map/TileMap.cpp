#include "TileMap.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"

CTileMap::CTileMap() : m_TileCountX(0), m_TileCountY(0), m_StartX(-1), m_StartY(-1), m_EndX(-1), m_EndY(-1)
{
}

CTileMap::~CTileMap()
{
	size_t Size = m_vecTile.size();

	for (size_t i = 0; i < Size; i++)
	{
		SAFE_DELETE(m_vecTile[i]);
	}

	m_vecTile.clear();
}

bool CTileMap::CreateTile(int CountX, int CountY, const Vector2& TileSize)
{
	m_TileCountX = CountX;
	m_TileCountY = CountY;
	m_TileSize = TileSize;

	{
		auto iter = m_vecTile.begin();
		auto iterEnd = m_vecTile.end();

		for (; iter != iterEnd; iter++)
		{
			SAFE_DELETE((*iter));
		}

		m_vecTile.clear();
	}

	m_Size = m_TileSize * Vector2((float)m_TileCountX, (float)m_TileCountY);

	CCamera* Camera = m_Scene->GetCamera();
	Camera->SetWorldResolution(m_Size);

	for (int i = 0; i < m_TileCountY; i++)
	{
		for (int j = 0; j < m_TileCountX; j++)
		{
			CTile* Tile = new CTile;

			Tile->Init();

			Vector2 Pos = Vector2((float)j, (float)i) * m_TileSize;

			Tile->SetTileInfo(Pos, m_TileSize, j, i, i * m_TileCountX + j, m_TileTexture);

			m_vecTile.push_back(Tile);
		}
	}

	for (int i = 0; i < m_TileCountY; i++)
	{
		for (int j = 0; j < m_TileCountX; j++)
		{
			m_vecTile[i * m_TileCountX + j]->SetTileTexture(m_TileTexture);
		}
	}

	return true;
}

bool CTileMap::SetTileTexture(CTexture* Texture)
{
	m_TileTexture = Texture;

	for (int i = 0; i < m_TileCountY; i++)
	{
		for (int j = 0; j < m_TileCountX; j++)
		{
			m_vecTile[i * m_TileCountX + j]->SetTileTexture(m_TileTexture);
		}
	}

	return true;
}

bool CTileMap::SetTileTexture(CTexture* Texture, int IndexX, int IndexY)
{
	m_TileTexture = Texture;

	m_vecTile[IndexY * m_TileCountX + IndexX]->SetTileTexture(m_TileTexture);

	return true;
}

void CTileMap::Start()
{
	CMapBase::Start();
}

bool CTileMap::Init()
{
	CMapBase::Init();

	return true;
}

void CTileMap::Update(float DeltaTime)
{
	CMapBase::Update(DeltaTime);

	if (!m_vecTile.empty())
	{
		CCamera* Camera = m_Scene->GetCamera();

		Vector2 CameraPos = Camera->GetPos();
		Vector2 Resolution = Camera->GetResolution();

		m_StartX = (int)(CameraPos.x / m_TileSize.x);
		m_StartY = (int)(CameraPos.y / m_TileSize.y);
		m_EndX = (int)((CameraPos.x  + Resolution.x) / m_TileSize.x);
		m_EndY = (int)((CameraPos.x + Resolution.y) / m_TileSize.y);

		m_StartX = m_StartX < 0 ? 0 : m_StartX;
		m_StartY = m_StartY < 0 ? 0 : m_StartY;
		m_EndX = m_EndX >= m_TileCountX ? m_TileCountX - 1 : m_EndX;
		m_EndY = m_EndY >= m_TileCountY ? m_TileCountY - 1 : m_EndY;

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->Update(DeltaTime);
			}
		}
	}
}

void CTileMap::PostUpdate(float DeltaTime)
{
	CMapBase::PostUpdate(DeltaTime);

	if (!m_vecTile.empty())
	{
		if (m_StartX == -1 || m_StartY == -1 || m_EndX == -1 || m_EndY == -1)
		{
			return;
		}

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->PostUpdate(DeltaTime);
			}
		}
	}
}

void CTileMap::PrevRender()
{
	CMapBase::PrevRender();

	if (!m_vecTile.empty())
	{
		if (m_StartX == -1 || m_StartY == -1 || m_EndX == -1 || m_EndY == -1)
		{
			return;
		}

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->PrevRender();
			}
		}
	}
}

void CTileMap::Render(HDC hDC)
{
	CMapBase::Render(hDC);

	if (!m_vecTile.empty())
	{
		if (m_StartX == -1 || m_StartY == -1 || m_EndX == -1 || m_EndY == -1)
		{
			return;
		}

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->Render(hDC);
			}
		}
	}
}
