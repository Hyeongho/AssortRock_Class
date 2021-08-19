
#pragma once

/*
stl : standard template library이다.
배열, 더블링크드리스트 등 자료구조들을 미리 구현해놓은 라이브러리이다.
*/

#include <Windows.h>
#include <list>		// 더블링크드리스트 템플릿 자료구조
#include <vector>	// 동적배열 템플릿 자료구조
#include "resource.h"

#include "Math.h"


#define	SAFE_DELETE(p)	if(p)	{ delete p; p = nullptr; }

struct Resolution
{
	int	Width;
	int	Height;
};

struct RectInfo
{
	float	Left;
	float	Top;
	float	Right;
	float	Bottom;
};

struct BulletInfo
{
	RectInfo	rc;
	float		Distance;
};

