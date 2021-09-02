#pragma once

#include "../Ref.h"

class CCollider :
    public CRef
{
    friend class CGameObject;

protected:
    CCollider();
    CCollider(const CCollider& collider);
    virtual ~CCollider() = 0;

protected:
    class CScene* m_Scene;
    class CGameObject* m_Owner;
    ECollider_Type m_Type;
    Vector2 m_Offset;
    bool m_Enable;
    CollisionProfile* m_Profile;

public:
    void SetEnable(bool Enable)
    {
        m_Enable = Enable;
    }

    void SetOffset(const Vector2& Offset)
    {
        m_Offset = Offset;
    }

    void SetOffset(float x, float y)
    {
        m_Offset = Vector2(x, y);
    }

    void SetScene(class CScene* Scene)
    {
        m_Scene = Scene;
    }

    void SetOwner(class CGameObject* Owner)
    {
        m_Owner = Owner;
    }

public:
    bool GetEnable()
    {
        return m_Enable;
    }

    class CGameObject* GetOwner() const
    {
        return m_Owner;
    }

    class CScene* GetScene() const
    {
        return m_Scene;
    }

    ECollider_Type GetColliderType() const
    {
        return m_Type;
    }

    CollisionProfile* GetProfile() const
    {
        return m_Profile;
    }

public:
    void SetCollisionProfile(const std::string& Name);

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual void Render(HDC hDC);
    virtual CCollider* Clone();
    virtual bool Collision(CCollider* Dest) = 0;
};

