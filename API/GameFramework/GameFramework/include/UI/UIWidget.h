#pragma once
#include "../Ref.h"
class CUIWidget :
    public CRef
{
public:
    CUIWidget();
    CUIWidget(const CUIWidget& widget);
    virtual ~CUIWidget();

protected:
    class CScene* m_Scene;
    int m_ZOrder;
    bool m_Visibility;
    class CUIWindow* m_Owner;
    Vector2 m_Pos;
    Vector2 m_Size;

public:
    Vector2 GetPos() const
    {
        return m_Pos;
    }

    Vector2 GetSize() const
    {
        return m_Size;
    }

    void SetPos(const Vector2 Pos)
    {
        m_Pos = Pos;
    }

    void SetPos(float x, float y)
    {
        m_Pos = Vector2(x, y);
    }

    void SetSize(const Vector2 Size)
    {
        m_Size = Size;
    }

    void SetSize(float x, float y)
    {
        m_Size = Vector2(x, y);
    }

    void SetOwner(class CUIWindow* Owner)
    {
        m_Owner = Owner;
    }

    void SetScene(class CScene* Scene)
    {
        m_Scene = Scene;
    }

    void SetVisibility(bool Visibility)
    {
        m_Visibility = Visibility;
    }

    bool GetVisibility() const
    {
        return m_Visibility;
    }

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual void Collision(float DeltaTime);
    virtual void Render(HDC hDC);
};
