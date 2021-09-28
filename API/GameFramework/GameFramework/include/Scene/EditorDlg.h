#pragma once

#include "../GameInfo.h"
#include "../Resource/Texture.h"

class CEditorDlg 
{
public:
	CEditorDlg();
	~CEditorDlg();

private:
	HWND m_hDlg;
	int m_ID;
	bool m_Open;
	class CEditorScene* m_Scene;
	HWND m_TextureListBox;
	int m_SelectTextureListIndex;
	TCHAR m_SelectTextureListText[256];
	CSharedPtr<CTexture> m_SelectTileTexture;

public:
	bool IsOpen() const
	{
		return m_Open;
	}

	RECT GetRect() const
	{
		RECT rc;
		GetWindowRect(m_hDlg, &rc);

		return rc;
	}

	void SetScene(class CEditorScene* Scene)
	{
		m_Scene = Scene;
	}

public:
	bool Init(int ID);
	void Show();
	void CreateMap();
	void LoadTileTexture();
	void SelectTexture();
	void SelectList();

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
