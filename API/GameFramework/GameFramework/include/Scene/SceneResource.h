#pragma once

#include "../Resource/Texture.h"
#include "../Animation/AnimationInfo.h"

class CSceneResource
{
	friend class CScene;

private:
	CSceneResource();
	~CSceneResource();

private:
	std::unordered_map<std::string, CTexture*>	m_mapTexture;

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);
	bool LoadTexture(const std::string& Name, const std::vector<std::wstring>& vecFileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureColorKey(const std::string& Name, const char r, const char g, const char b, int Index = 0);

	CTexture* FindTexture(const std::string& Name);
};

