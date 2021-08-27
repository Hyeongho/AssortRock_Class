#include "SceneResource.h"
#include "../Resource/ResourceManager.h"

CSceneResource::CSceneResource()
{
}

CSceneResource::~CSceneResource()
{
	auto iter = m_mapTexture.begin();
	auto iterEnd = m_mapTexture.end();

	for (; iter != iterEnd; iter++)
	{
		CResourceManager::GetInst()->ResourceTexture(iter->first);
	}
}

bool CSceneResource::LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	if (FindTexture(Name))
	{
		return true;
	}

	if (!CResourceManager::GetInst()->LoadTexture(Name, FileName, PathName))
	{
		return false;
	}

	CTexture* Texture = CResourceManager::GetInst()->FindTexture(Name);

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

bool CSceneResource::LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath)
{
	if (FindTexture(Name))
	{
		return true;
	}

	if (!CResourceManager::GetInst()->LoadTextureFullPath(Name, FullPath))
	{
		return false;
	}

	CTexture* Texture = CResourceManager::GetInst()->FindTexture(Name);

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

bool CSceneResource::LoadTexture(const std::string& Name, const std::vector<std::wstring>& vecFileName, const std::string& PathName)
{
	if (FindTexture(Name))
	{
		return true;
	}

	if (!CResourceManager::GetInst()->LoadTexture(Name, vecFileName, PathName))
	{
		return false;
	}

	CTexture* Texture = CResourceManager::GetInst()->FindTexture(Name);

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

void CSceneResource::SetTextureColorKey(const std::string& Name, const char r, const char g, const char b, int Index)
{
	CResourceManager::GetInst()->SetTextureColorKey(Name, r, g, b, Index);
}

CTexture* CSceneResource::FindTexture(const std::string& Name)
{
	auto iter = m_mapTexture.find(Name);

	if (iter == m_mapTexture.end())
	{
		return nullptr;
	}

	return iter->second;
}
