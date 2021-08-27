#pragma once

#include "Texture.h"

class CResourceManager
{
private:
	CResourceManager();
	~CResourceManager();

private:
	std::unordered_map<std::string, CSharedPtr<CTexture>> m_mapTexture;
	
public:
	bool Init();

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);
	bool LoadTexture(const std::string& Name, const std::vector<std::wstring>& vecFileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureColorKey(const std::string& Name, const char r, const char g, const char b, int Index = 0);

	void ResourceTexture(const std::string& Name);

	CTexture* FindTexture(const std::string& Name);

private:
	static CResourceManager* m_Inst;

public:
	static CResourceManager* GetInst()
	{
		if (!m_Inst)
		{
			m_Inst = new CResourceManager;
		}

		return m_Inst;
	}

	static void DestroyInst()
	{
		CResourceManager(m_Inst);
	}
};
