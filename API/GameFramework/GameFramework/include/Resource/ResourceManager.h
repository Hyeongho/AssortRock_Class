#pragma once

#include "Texture.h"
#include "AnimationSequence.h"

class CResourceManager
{
private:
	CResourceManager();
	~CResourceManager();

private:
	std::unordered_map<std::string, CSharedPtr<CTexture>> m_mapTexture;
	std::unordered_map<std::string, CSharedPtr<CAnimationSequence>> m_mapAnimationSequence;
	
public:
	bool Init();

public:
	bool LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);
	bool LoadTexture(const std::string& Name, const std::vector<std::wstring>& vecFileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureColorKey(const std::string& Name, const char r, const char g, const char b, int Index = 0);

	void ResourceTexture(const std::string& Name);

	CTexture* FindTexture(const std::string& Name);

public:
	bool CreateAnimationSequence(const std::string& SequenceName, const std::string& TextureName);
	bool CreateAnimationSequence(const std::string& SequenceName, const std::string& TextureName, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
	bool CreateAnimationSequence(const std::string& SequenceName, const std::string& TextureName, const std::vector<std::wstring>& vecFilName, const std::string& PathName = TEXTURE_PATH);

	void AddAnimationFrameData(const std::string& SequenceName, const Vector2& StartPos, const Vector2& Size);
	void AddAnimationFrameData(const std::string& SequenceName, float PosX, float PosY, float SizeX, float SizeY);

	void ResourceAnimationSequence(const std::string& Name);

	CAnimationSequence* FindAnimationSequence(const std::string& Name); 

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
