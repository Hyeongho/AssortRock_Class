#include "UIWidget.h"

CUIWidget::CUIWidget() : m_ZOrder(0), m_Visibility(true)
{
}

CUIWidget::CUIWidget(const CUIWidget& widget)
{
	*this = widget;
}

CUIWidget::~CUIWidget()
{
}

bool CUIWidget::Init()
{
	return true;
}

void CUIWidget::Update(float DeltaTime)
{
}

void CUIWidget::PostUpdate(float DeltaTime)
{
}

void CUIWidget::Collision(float DeltaTime)
{
}

void CUIWidget::Render(HDC hDC)
{
}
