#include "SceneResource.h"

CSceneResource::CSceneResource()
{
}

CSceneResource::~CSceneResource()
{
}

bool CSceneResource::LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	return false;
}

bool CSceneResource::LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath)
{
	return false;
}

CTexture* CSceneResource::FindTexture(const std::string& Name)
{
	return nullptr;
}
