#pragma once

#include "UIWidget.h"
#include "../Resource/Texture.h"

class CButton :
    public CUIWidget
{
public:
	CButton();
	CButton(const CButton& widget);
	virtual ~CButton();

protected:
	CSharedPtr<CTexture> m_Texture;
	AnimationFrameData m_FrameData[(int)EButton_State::End];
	EButton_State m_ButtomState;

public:
	void SetTexture(CTexture* Texture)
	{
		m_Texture = Texture;

		if (m_Texture)
		{
			m_Size.x = (float)m_Texture->GetWidth();
			m_Size.y = (float)m_Texture->GetHeight();
		}
	}

	void SetTexture(const std::string& Name);
	void SetTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureFullPath(const std::string& Name, const TCHAR* FullPath);
	void SetTexture(const std::string& Name, const std::vector<std::wstring>& vecFileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureColorKey(unsigned char r, unsigned g, unsigned char b, int Index = 0);
	void SetFrameData(EButton_State State, const Vector2& Start, const Vector2& Size);
	void Enable(bool Enable)
	{
		m_ButtomState = Enable ? EButton_State::Normal : EButton_State::Disable;
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);

protected:
	virtual void CollisionMouseHoveredCallback(float DeltaTime);
	virtual void CollisionMouseReleaseCallback(float DeltaTime);
};

