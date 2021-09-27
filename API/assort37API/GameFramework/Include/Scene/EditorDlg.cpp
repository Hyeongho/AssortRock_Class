
#include "EditorDlg.h"
#include "../GameManager.h"

CEditorDlg* g_Dlg;

CEditorDlg::CEditorDlg()	:
	m_ID(0),
	m_hDlg(0),
	m_Open(true),
	m_Scene(nullptr)
{
	g_Dlg = this;
}

CEditorDlg::~CEditorDlg()
{
	if (m_hDlg)
		DestroyWindow(m_hDlg);
}

bool CEditorDlg::Init(int ID)
{
	// Modal : 부모윈도우는 멈추고 열리는 다이얼로그만 동작되는 방식
	// Modeless : 부모윈도우와 다이얼로그 모두 동작되는 방식
	m_hDlg	= CreateDialog(CGameManager::GetInst()->GetWindowInstance(),
		MAKEINTRESOURCE(ID), CGameManager::GetInst()->GetWindowHandle(),
		CEditorDlg::WndProc);

	ShowWindow(m_hDlg, SW_SHOW);

	return true;
}

void CEditorDlg::Show()
{
	if (m_Open)
	{
		m_Open = false;
		ShowWindow(m_hDlg, SW_HIDE);
	}

	else
	{
		m_Open = true;
		ShowWindow(m_hDlg, SW_SHOW);
	}
}

void CEditorDlg::CreateMap()
{
	BOOL	Transfer = FALSE;

	int	TileCountX = GetDlgItemInt(m_hDlg, IDC_EDIT_TILECOUNTX, &Transfer, TRUE);
	int	TileCountY = GetDlgItemInt(m_hDlg, IDC_EDIT_TILECOUNTY, &Transfer, TRUE);
	int	TileSizeX = GetDlgItemInt(m_hDlg, IDC_EDIT_TILESIZEX, &Transfer, TRUE);
	int	TileSizeY = GetDlgItemInt(m_hDlg, IDC_EDIT_TILESIZEY, &Transfer, TRUE);

	int a = 0;
}

LRESULT CEditorDlg::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			break;
		case IDCANCEL:
			break;
		case IDC_BUTTON_CREATEMAP:
			//MessageBox(0, TEXT("맵 생성"), TEXT("맵 생성"), MB_OK);
			g_Dlg->CreateMap();
			break;
		}
		break;
	default:
		break;
	}

	return 0;
}
