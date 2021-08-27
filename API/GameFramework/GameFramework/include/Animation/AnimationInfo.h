#pragma once

#include "../Resource//Texture.h"

struct AnimationFrameData
{
	Vector2 StartPos;
	Vector2 Size;
};

struct AnimationSequnce
{
	std::string Name;
	ETexture_Type TextureType;
	CSharedPtr<CTexture> Texture;
	std::vector<AnimationFrameData> vecFrameData;
};

struct AnimationInfo
{
	AnimationSequnce* Sequnce;
	int Frame; // ���� �ִϸ��̼��� �� ������°�� ���� �ִ����� �����Ѵ�.
	float Time; // ����ð�
	float FrameTime; // 1�������� ���ʸ��� �귯�� �ϴ���.
	float PlayTime; // ����� �ѹ� ���� �ʿ��� �ð�.
	float PlayScale; // ��� ����
	bool Loop;
	bool Reverse;

	AnimationInfo() : Frame(0), Time(0.f), FrameTime(0.f), PlayTime(0.f), PlayScale(1.f), Loop(false), Reverse(false)
	{

	}
};