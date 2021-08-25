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
	// ���� ��θ� ������ش�.
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

	// �޸�DC�� �����.
	Info->hDC = CreateCompatibleDC(CGameManager::GetInst()->GetWindowDC());
	Info->hBmp = (HBITMAP)LoadImage(CGameManager::GetInst()->GetWindowInstance(), FullPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	// ������ ������ �޸� DC�� �ҷ��� ��Ʈ���� �������ش�.
	// SelectObject�� �Ʒ�ó�� HGDIOBJ�� �����ϸ� ���� ������ �ִ� HGDIOBJ�� ��ȯ���ش�.
	// �׷��� �� DC�� �����ٶ����� �ݵ�� ���� HGDIOBJ�� ������ �صΰ� ������� �Ѵ�.
	Info->hPrev = (HBITMAP)SelectObject(Info->hDC, Info->hBmp);

	// ��Ʈ�� ������ ���ͼ� �����صд�.
	GetObject(Info->hBmp, sizeof(BITMAP), &Info->BmpInfo);

	m_vecTextureInfo.push_back(Info);

	return true;
}
