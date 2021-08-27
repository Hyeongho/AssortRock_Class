
#pragma once

/*
stl : standard template library이다.
배열, 더블링크드리스트 등 자료구조들을 미리 구현해놓은 라이브러리이다.
*/

#include <Windows.h>
#include <list>		// 더블링크드리스트 템플릿 자료구조
#include <vector>	// 동적배열 템플릿 자료구조
#include <string>
#include <unordered_map>
#include <crtdbg.h>
#include <functional>
#include "resource.h"

#include "SharedPtr.h"
#include "Math.h"
#include "Flag.h"

#pragma comment(lib, "msimg32.lib")


#define	KEYCOUNT_MAX	256

#define	ROOT_PATH		"RootPath"
#define	TEXTURE_PATH	"TexturePath"
#define	SOUND_PATH		"SoundPath"


#define	SAFE_DELETE(p)	if(p)	{ delete p; p = nullptr; }
#define	SAFE_RELEASE(p)	if(p)	{ p->Release(); p = nullptr; }

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

struct AnimationFrameData
{
	Vector2	StartPos;
	Vector2	Size;
};
