#pragma once

#include "../Ref.h"
#include "../Resource/Texture.h"

class CGameObject : public CRef
{
	friend class CScene;

public:
	CGameObject();
	CGameObject(const CGameObject& obj);
	virtual ~CGameObject();

protected:
	class CScene* m_Scene;
	Vector2 m_PrevPos;
	Vector2 m_Pos;
	Vector2 m_Size;
	Vector2 m_Pivot;
	Vector2 m_Velocitry;
	float m_MoveSpeed;
	float m_TimeScale;

	CSharedPtr<CTexture> m_Texture;

	Vector2 m_ImageStart;

public:
	Vector2 GetPos() const
	{
		return m_Pos;
	}

	Vector2 GetSize() const
	{
		return m_Size;
	}

	Vector2 GetPivot() const
	{
		return m_Pivot;
	}

	Vector2 GetVelocity() const
	{
		return m_Velocitry;
	}

	float GetMoveSpeed() const
	{
		return m_MoveSpeed;
	}

	float GetMoveSpeedFrame() const
	{
		return m_Velocitry.Length();
	}

public:
	void SetScene(class CScene* Scene)
	{
		m_Scene = Scene;
	}

	void SetPos(float x, float y)
	{
		m_Pos.x = x;
		m_Pos.y = y;
	}

	void SetPos(const Vector2& Pos)
	{
		m_Pos = Pos;
	}

	void SetSize(float x, float y)
	{
		m_Size.x = x;
		m_Size.y = y;
	}

	void SetSize(const Vector2& Size)
	{
		m_Size = Size;
	}

	void SetPivot(float x, float y)
	{
		m_Pivot.x = x;
		m_Pivot.y = y;
	}

	void SetPivot(const Vector2& Pivot)
	{
		m_Pivot = Pivot;
	}

	void SetMoveSpeed(float Speed)
	{
		m_MoveSpeed = Speed;
	}

	void SetTimeScale(float TimeScale)
	{
		m_TimeScale = TimeScale;
	}

	void Move(const Vector2& Dir);
	void Move(const Vector2& Dir, float Speed);

	void SetImageStart(float x, float y)
	{
		m_ImageStart.x = x;
		m_ImageStart.y = y;
	}

	void SetImageStart(const Vector2& ImageStart)
	{
		m_ImageStart = ImageStart;
	}

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
	void SetTexFullPath(const std::string& Name, const TCHAR* FullPath);
	void SetTexture(const std::string& Name, const std::vector<std::wstring>& vecFileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureColorKey(unsigned char r, unsigned g, unsigned char b, int Index = 0);
	
public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CGameObject* Clone();
};
