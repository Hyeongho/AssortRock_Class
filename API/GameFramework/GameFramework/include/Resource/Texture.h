#pragma once
#include "../GameInfo.h"
#include "../Ref.h"

struct TextureInfo
{
    // �̹��������� �ҷ��ͼ� HBITMAP�� ����� �� HBITMAP�� ȭ�鿡 ����� �޸�DC�� ���� ����ϰ� �Ѵ�.
    HDC hDC;
    HBITMAP hBmp;
    HBITMAP hPrev;
    BITMAP BmpInfo;

    bool ColorKeyEnable;
    unsigned int ColorKey;

    TextureInfo() : hDC(0), hBmp(0), hPrev(0), BmpInfo{}, ColorKeyEnable(false), ColorKey(0)
    {

    }

    ~TextureInfo()
    {
        // ������ HGDIOBJ�� �ǵ����ش�.
        SelectObject(hDC, hPrev);

        // HBITMAP�� HDC�� �����Ѵ�.
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
    ETexture_Type m_TextureType;
    std::vector<TextureInfo*> m_vecTextureInfo;

public:
    ETexture_Type GetTextureType() const
    {
        return m_TextureType;
    }

    unsigned int GetWidth(int idx = 0) const
    {
        return (unsigned int)m_vecTextureInfo[idx]->BmpInfo.bmWidth;
    }

    unsigned int GetHeight(int idx = 0) const
    {
        return (unsigned int)m_vecTextureInfo[idx]->BmpInfo.bmHeight;
    }

    void SetColorKey(const char r, const char g, const char b, int index = 0)
    {
        m_vecTextureInfo[index]->ColorKeyEnable = true;
        m_vecTextureInfo[index]->ColorKey = RGB(r, g, b);
    }

public:
    bool LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
    bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);
    bool LoadTexture(const std::string& Name, const std::vector<std::wstring>& vecFilName, const std::string& PathName);

    void Render(HDC hDC, const Vector2& WindowPos, const Vector2& ImgPos, const Vector2& Size, int Index = 0);
};

