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
