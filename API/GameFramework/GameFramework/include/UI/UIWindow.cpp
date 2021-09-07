#include "UIWindow.h"

CUIWindow::CUIWindow() : m_Visibility(true)
{
}

CUIWindow::CUIWindow(const CUIWindow& widget)
{
}

CUIWindow::~CUIWindow()
{
}

bool CUIWindow::Init()
{
	return true;
}

void CUIWindow::Update(float DeltaTime)
{
}

void CUIWindow::PostUpdate(float DeltaTime)
{
}

void CUIWindow::Collision(float DeltaTime)
{
}

void CUIWindow::Render(HDC hDC)
{
}
