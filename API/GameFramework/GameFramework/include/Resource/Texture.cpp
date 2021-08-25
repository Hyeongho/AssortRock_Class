#include "Texture.h"
#include "../PathManager.h"
#include "../GameManager.h"

CTexture::CTexture()
{
}

CTexture::~CTexture()
{
}

bool CTexture::LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	// 최종 경로를 만들어준다.
	const PathInfo* Info = CPathManager::GetInst()->FindPath(PathName);

	TCHAR FullPath[MAX_PATH] = {};

	if (Info)
	{
		lstrcpy(FullPath, Info->Path);
	}

	lstrcat(FullPath, FileName);

	return LoadTextureFullPath(Name, FullPath);
}

bool CTexture::LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath)
{
	SetName(Name);

	TextureInfo* Info = new TextureInfo;

	// 메모리DC를 만든다.
	Info->hDC = CreateCompatibleDC(CGameManager::GetInst()->GetWindowDC());
	Info->hBmp = (HBITMAP)LoadImage(CGameManager::GetInst()->GetWindowInstance(), FullPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	// 위에서 생성한 메모리 DC에 불러온 비트맵을 지정해준다.
	// SelectObject는 아래처럼 HGDIOBJ을 지정하면 원래 가지고 있던 HGDIOBJ를 반환해준다.
	// 그래서 이 DC를 지워줄때에는 반드시 원본 HGDIOBJ로 지정을 해두고 지워줘야 한다.
	Info->hPrev = (HBITMAP)SelectObject(Info->hDC, Info->hBmp);

	// 비트맵 정보를 얻어와서 저장해둔다.
	GetObject(Info->hBmp, sizeof(BITMAP), &Info->BmpInfo);

	m_vecTextureInfo.push_back(Info);

	return true;
}
