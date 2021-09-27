#pragma once
#include "MapBase.h"
class CTileMap :
    public CMapBase
{
	friend class CScene;

protected:
	CTileMap();
	virtual ~CTileMap();

public:
	//bool CreateTile();

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void PrevRender();
	virtual void Render(HDC hDC);
};

