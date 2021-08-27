#pragma once

#include "../Resource/AnimationSequence.h"

struct AnimationInfo
{
	CSharedPtr<CAnimationSequence> Sequence;
	int		Frame;	// 현재 애니메이션이 몇 프레임째를 돌고 있는지를 저장한다.
	float	Time;	// 현재 시간
	float	FrameTime;	// 1프레임이 몇초만에 흘러야 하는지.
	float	PlayTime;	// 모션이 한번 돌때 필요한 시간.
	float	PlayScale;	// 재생 배율
	bool	Loop;
	bool	Reverse;

	AnimationInfo()	:
		Frame(0),
		Time(0.f),
		FrameTime(0.f),
		PlayTime(0.f),
		PlayScale(1.f),
		Loop(false),
		Reverse(false)
	{
	}
};
