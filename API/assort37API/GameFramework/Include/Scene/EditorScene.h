#pragma once
#include "Scene.h"
class CEditorScene :
    public CScene
{
	friend class CSceneManager;

private:
	CEditorScene();
	virtual ~CEditorScene();

private:
	bool	m_Start;
	class CEditorDlg* m_Dlg;

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);

private:
	void LoadAnimationSequence();
	void LoadSound();

public:
	void OnEditor(float DeltaTime);
};

