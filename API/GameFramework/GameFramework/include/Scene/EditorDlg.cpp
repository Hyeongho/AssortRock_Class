#include "EditorDlg.h"
#include "../GameManager.h"
#include "../PathManager.h"
#include "Scene.h"
#include "SceneResource.h"
#include "EditorScene.h"

CEditorDlg* g_Dlg;

CEditorDlg::CEditorDlg() : m_ID(0), m_hDlg(0), m_Open(true), m_Scene(nullptr), m_SelectTextureListText{}
{
	g_Dlg = this;
}

CEditorDlg::~CEditorDlg()
{
	if (m_hDlg)
	{
		DestroyWindow(m_hDlg);
	}
}

bool CEditorDlg::Init(int ID)
{
	// Modal: 부모윈도우는 멈추고 열리는 다이얼로그만 동작되는 방식
	// Modeless: 부모윈도우와 다이얼로그 모두 동작되는 방식
	m_hDlg = CreateDialog(CGameManager::GetInst()->GetWindowInstance(), MAKEINTRESOURCE(ID), CGameManager::GetInst()->GetWindowHandle(), CEditorDlg::WndProc);

	ShowWindow(m_hDlg, SW_SHOW);

	SetDlgItemInt(m_hDlg, IDC_EDIT_TILECOUNTX, 40, TRUE);
	SetDlgItemInt(m_hDlg, IDC_EDIT_TILECOUNTY, 40, TRUE);

	SetDlgItemInt(m_hDlg, IDC_EDIT_TILESIZEX, 40, TRUE);
	SetDlgItemInt(m_hDlg, IDC_EDIT_TILESIZEY, 53, TRUE);

	m_TextureListBox = GetDlgItem(m_hDlg, IDC_LIST_TILETEXTURE);

	m_SelectTextureListIndex = -1;

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
	BOOL Transfer = FALSE;

	int TileCountX = GetDlgItemInt(m_hDlg, IDC_EDIT_TILECOUNTX, &Transfer, TRUE);
	int TileCountY = GetDlgItemInt(m_hDlg, IDC_EDIT_TILECOUNTY, &Transfer, TRUE);
	int TileSizeX = GetDlgItemInt(m_hDlg, IDC_EDIT_TILESIZEX, &Transfer, TRUE);
	int TileSizeY = GetDlgItemInt(m_hDlg, IDC_EDIT_TILESIZEY, &Transfer, TRUE);

	m_Scene->CreateTileMap();

	m_Scene->SetTileInfo(TileCountX, TileCountY, TileSizeX, TileSizeY);
}

void CEditorDlg::LoadTileTexture()
{
	TCHAR FilePath[MAX_PATH] = {};

	OPENFILENAME OpenFile = {};

	OpenFile.lStructSize = sizeof(OPENFILENAME);
	OpenFile.hwndOwner = m_hDlg;
	OpenFile.lpstrFilter = TEXT("모든파일\0*.*\0BmpFile\0*.bmp");
	OpenFile.lpstrFile = FilePath;
	OpenFile.nMaxFile = MAX_PATH;
	OpenFile.lpstrInitialDir = CPathManager::GetInst()->FindPath(TEXTURE_PATH)->Path;

	if (GetOpenFileName(&OpenFile) != 0)
	{
		//전테 경로에서 파일이름만 얻어온다.
		TCHAR FileName[128] = {};

		_wsplitpath_s(FilePath, nullptr, 0, nullptr, 0, FileName, 128, nullptr, 0);

		char TextureName[256] = {};

#ifdef UNICODE
		// 유니코드 문자열을 멀티바이트 문자열로 변환한다.
		int ConvertLength = WideCharToMultiByte(CP_ACP, 0, FileName, -1, nullptr, 0, 0, 0);

		WideCharToMultiByte(CP_ACP, 0, FileName, -1, TextureName, ConvertLength, 0, 0);
#else
		strcpy_s(TextureName, FileName);
#endif // UNICODE

		if (!m_Scene->GetSceneResource()->LoadTextureFullPath(TextureName, FilePath))
		{
			return;
		}

		CTexture* Texture = m_Scene->GetSceneResource()->FindTexture(TextureName);

		SendMessage(m_TextureListBox, LB_ADDSTRING, 0, (LPARAM)FileName);
	}
}

void CEditorDlg::SelectTexture()
{
	if (m_SelectTextureListIndex != -1)
	{
		char TextureName[256] = {};

#ifdef UNICODE
		// 유니코드 문자열을 멀티바이트 문자열로 변환한다.
		int ConvertLength = WideCharToMultiByte(CP_ACP, 0, m_SelectTextureListText, -1, nullptr, 0, 0, 0);

		WideCharToMultiByte(CP_ACP, 0, m_SelectTextureListText, -1, TextureName, ConvertLength, 0, 0);
#else
		strcpy_s(TextureName, FileName);
#endif // UNICODE

		m_SelectTileTexture = m_Scene->GetSceneResource()->FindTexture(TextureName);

		m_Scene->CreateTileMap();

		m_Scene->SetTileTexture(m_SelectTileTexture);
	}
}

void CEditorDlg::SelectList()
{
	m_SelectTextureListIndex = (int)SendMessage(m_TextureListBox, LB_GETCURSEL, 0, 0);

	if (m_SelectTextureListIndex != -1)
	{
		memset(m_SelectTextureListText, 0, sizeof(TCHAR) * 256);
		SendMessage(m_TextureListBox, LB_GETTEXT, m_SelectTextureListIndex, (LPARAM)m_SelectTextureListText);
	}
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
		case IDC_LIST_TILETEXTURE:
			switch (HIWORD(wParam))
			{
			case LBN_SELCHANGE:
			{
				g_Dlg->SelectList();
			}
				break;
			}
			break;

		case IDOK:
			break;

		case IDCANCEL:
			break;

		case IDC_BUTTON_CREATEMAP:
			//MessageBox(0, TEXT("맵 생성"), TEXT("맵 생성"), MB_OK);
			g_Dlg->CreateMap();
			break;

		case IDC_BUTTON_TILETEXTURELOAD:
			g_Dlg->LoadTileTexture();
			break;

		case IDC_BUTTON_SETTEXTURE:
			g_Dlg->SelectTexture();
			break;
		}
		break;

	default:
		break;
	}

	return 0;
}
