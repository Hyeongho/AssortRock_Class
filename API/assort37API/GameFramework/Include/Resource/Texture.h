#pragma once

#include "../Ref.h"

struct TextureInfo
{
	// 이미지파일을 불러와서 HBITMAP을 만들고 이 HBITMAP을 화면에 출력할
	// 메모리DC를 만들어서 출력하게 한다.
	HDC		hDC;
	HBITMAP	hBmp;
	HBITMAP	hPrev;
	BITMAP	BmpInfo;
	bool	ColorKeyEnable;
	unsigned int	ColorKey;

	TextureInfo()	:
		hDC(0),
		hBmp(0),
		hPrev(0),
		BmpInfo{},
		ColorKeyEnable(false),
		ColorKey(0)
	{
	}

	~TextureInfo()
	{
		// 원래의 HGDIOBJ로 되돌려준다.
		SelectObject(hDC, hPrev);

		// HBITMAP과 HDC를 제거한다.
		DeleteObject(hBmp);

		DeleteDC(hDC);
	}
};

class CTexture :
	public CRef
{
public:
	CTexture();
	~CTexture();

private:
	std::vector<TextureInfo*>	m_vecTextureInfo;

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName,
		const std::string& PathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const std::string& Name,
		const TCHAR* FullPath);
};

