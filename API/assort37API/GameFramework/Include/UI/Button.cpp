
#include "Button.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"
#include "UIWindow.h"

CButton::CButton()
{
	m_ButtonState = EButton_State::Normal;
}

CButton::CButton(const CButton& widget)
{
}

CButton::~CButton()
{
}

void CButton::SetTexture(const std::string& Name)
{
	m_Texture = m_Scene->GetSceneResource()->FindTexture(Name);

	if (m_Texture)
	{
		m_Size.x = (float)m_Texture->GetWidth();
		m_Size.y = (float)m_Texture->GetHeight();

		for (int i = 0; i < (int)EButton_State::End; ++i)
		{
			m_FrameData[i].Size = m_Size;
		}
	}
}

void CButton::SetTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	m_Scene->GetSceneResource()->LoadTexture(Name, FileName, PathName);

	m_Texture = m_Scene->GetSceneResource()->FindTexture(Name);

	if (m_Texture)
	{
		m_Size.x = (float)m_Texture->GetWidth();
		m_Size.y = (float)m_Texture->GetHeight();

		for (int i = 0; i < (int)EButton_State::End; ++i)
		{
			m_FrameData[i].Size = m_Size;
		}
	}
}

void CButton::SetTextureFullPath(const std::string& Name, const TCHAR* FullPath)
{
	m_Scene->GetSceneResource()->LoadTextureFullPath(Name, FullPath);

	m_Texture = m_Scene->GetSceneResource()->FindTexture(Name);

	if (m_Texture)
	{
		m_Size.x = (float)m_Texture->GetWidth();
		m_Size.y = (float)m_Texture->GetHeight();

		for (int i = 0; i < (int)EButton_State::End; ++i)
		{
			m_FrameData[i].Size = m_Size;
		}
	}
}

void CButton::SetTexture(const std::string& Name,
	const std::vector<std::wstring>& vecFileName,
	const std::string& PathName)
{
	m_Scene->GetSceneResource()->LoadTexture(Name, vecFileName, PathName);

	m_Texture = m_Scene->GetSceneResource()->FindTexture(Name);

	if (m_Texture)
	{
		m_Size.x = (float)m_Texture->GetWidth();
		m_Size.y = (float)m_Texture->GetHeight();

		for (int i = 0; i < (int)EButton_State::End; ++i)
		{
			m_FrameData[i].Size.x = (float)m_Texture->GetWidth(i);
			m_FrameData[i].Size.y = (float)m_Texture->GetHeight(i);
		}
	}
}

void CButton::SetTextureColorKey(unsigned char r, unsigned char g, unsigned char b, int Index)
{
	if (m_Texture)
		m_Texture->SetColorKey(r, g, b, Index);
}

void CButton::SetFrameData(EButton_State State, const Vector2& Start,
	const Vector2& Size)
{
	m_FrameData[(int)State].StartPos = Start;
	m_FrameData[(int)State].Size = Size;
}

bool CButton::Init()
{
	return true;
}

void CButton::Update(float DeltaTime)
{
}

void CButton::PostUpdate(float DeltaTime)
{
}

void CButton::Collision(float DeltaTime)
{
}

void CButton::Render(HDC hDC)
{
	if (m_Texture)
	{
		Vector2	Pos = m_Pos + m_Owner->GetPos();

		if (m_Texture->GetTextureType() == ETexture_Type::Atlas)
		{
			// 이미지를 이용해서 출력한다.
			m_Texture->Render(hDC, Pos, Vector2(0.f, 0.f), m_Size);
		}

		else
		{
			// 이미지를 이용해서 출력한다.
			m_Texture->Render(hDC, Pos, Vector2(0.f, 0.f), m_Size, (int)m_ButtonState);
		}
	}
}
