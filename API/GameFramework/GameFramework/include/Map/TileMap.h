#pragma once

#include "MapBase.h"
#include "../Resource/Texture.h"
#include "Tile.h"

class CTileMap :
    public CMapBase
{
	friend class CScene;

protected:
	CTileMap();
	virtual ~CTileMap();

protected:
	std::vector<CTile*> m_vecTile;
	CSharedPtr<CTexture> m_TileTexture;
	int m_TileCountX;
	int m_TileCountY;
	Vector2 m_TileSize;

	int m_StartX;
	int m_StartY;
	int m_EndX;
	int m_EndY;

public:
	bool CreateTile(int CountX, int CountY, const Vector2& TileSize);
	bool SetTileTexture(CTexture* Texture);
	bool SetTileTexture(CTexture* Texture, int IndexX, int IndexY);

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void PrevRender();
	virtual void Render(HDC hDC);
};

