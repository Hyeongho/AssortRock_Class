#pragma once

#include "Texture.h"

class CResourceManager
{
private:
	CResourceManager();
	~CResourceManager();

private:
	std::unordered_map<std::string, CSharedPtr<CTexture>>	m_mapTexture;


public:
	bool Init();

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName,
		const std::string& PathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);

	CTexture* FindTexture(const std::string& Name);

private:
	static CResourceManager* m_Inst;

public:
	static CResourceManager* GetInst()
	{
		if (!m_Inst)
			m_Inst = new CResourceManager;

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}
};

