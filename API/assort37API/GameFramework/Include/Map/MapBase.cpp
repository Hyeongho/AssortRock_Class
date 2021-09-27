
#include "MapBase.h"

CMapBase::CMapBase()	:
	m_Scene(nullptr)
{
}

CMapBase::~CMapBase()
{
}

void CMapBase::Start()
{
}

bool CMapBase::Init()
{
	return false;
}

void CMapBase::Update(float DeltaTime)
{
}

void CMapBase::PostUpdate(float DeltaTime)
{
}

void CMapBase::PrevRender()
{
}

void CMapBase::Render(HDC hDC)
{
}
