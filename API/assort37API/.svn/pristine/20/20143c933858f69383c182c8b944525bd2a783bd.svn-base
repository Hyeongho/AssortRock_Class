#pragma once

#include "../Ref.h"
#include "UIWidget.h"

class CUIWindow :
	public CRef
{
public:
	CUIWindow();
	CUIWindow(const CUIWindow& widget);
	virtual ~CUIWindow();

protected:
	class CScene* m_Scene;
	int m_ZOrder;
	std::list<CSharedPtr<CUIWidget>>  m_WidgetList;
	bool    m_Visibility;

public:
	void SetScene(class CScene* Scene)
	{
		m_Scene = Scene;
	}

	void SetZOrder(int ZOrder)
	{
		m_ZOrder = ZOrder;
	}

	int GetZOrder() const
	{
		return m_ZOrder;
	}

	void SetVisibility(bool Visiblity)
	{
		m_Visibility = Visiblity;
	}

	bool GetVisibility()    const
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

