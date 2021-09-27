#pragma once

#include "../GameInfo.h"

class CEditorDlg
{
public:
	CEditorDlg();
	~CEditorDlg();

private:
	HWND	m_hDlg;
	int		m_ID;
	bool	m_Open;
	class CScene* m_Scene;

public:
	bool IsOpen()	const
	{
		return m_Open;
	}

	RECT GetRect()	const
	{
		RECT	rc;
		GetWindowRect(m_hDlg, &rc);
		return rc;
	}

	void SetScene(class CScene* Scene)
	{
		m_Scene = Scene;
	}

public:
	bool Init(int ID);
	void Show();
	void CreateMap();

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
