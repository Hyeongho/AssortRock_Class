#pragma once

#include "AnimationInfo.h"

class CAnimation
{
	friend class CGameObject;

private:
	CAnimation();
	CAnimation(const CAnimation& Anim);
	~CAnimation();

private:
	class CGameObject* m_Owner;
	class CScene* m_Scene;
	std::unordered_map<std::string, AnimationInfo*>	m_mapAnimation;
	AnimationInfo* m_CurrentAnimation;

public:
	void AddAnimation(const std::string& SequenceName,
		bool Loop = true, float PlayTime = 1.f, float PlayScale = 1.f,
		bool Reverse = false);
	void SetPlayTime(const std::string& Name, float PlayTime);
	void SetPlayScale(const std::string& Name, float PlayScale);
	void SetCurrentAnimation(const std::string& Name);
	void ChangeAnimation(const std::string& Name);
	void SetReverse(const std::string& Name, bool Reverse);
	void SetLoop(const std::string& Name, bool Loop);
	void Update(float DeltaTime);
	CAnimation* Clone();

private:
	AnimationInfo* FindInfo(const std::string& Name);
};

