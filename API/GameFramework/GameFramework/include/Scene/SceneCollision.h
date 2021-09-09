#pragma once

#include "../GameInfo.h"

class CSceneCollision
{
	friend class CScene;

private:
	CSceneCollision();
	~CSceneCollision();

private:
	class CScene* m_Scene;
	std::vector<class CCollider*> m_vecCollider;
	std::vector<class CUIWindow*> m_vecUIWindow;
	class CUIWidget* m_MouseHoveredWidget;
	class CUIWidget* m_SelectWidget;

public:
	void SetSelectWidget(class CUIWidget* Widget)
	{
		m_SelectWidget = Widget;
	}

public:
	void AddCollider(class CCollider* Collider);
	void AddUIWindow(class CUIWindow* Window);
	void CollisionMouse(float DeltaTime);
	void Collision(float DeltaTime);
};

