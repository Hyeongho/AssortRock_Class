#pragma once

#include "../Resource/Texture.h"

class CSceneResource
{
	friend class CScene;

private:
	CSceneResource();
	~CSceneResource();

private:
	std::unordered_map<std::string, CSharedPtr<CTexture>>	m_mapTexture;

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName,
		const std::string& PathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);

	CTexture* FindTexture(const std::string& Name);
};

