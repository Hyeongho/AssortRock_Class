#include "EditorScene.h"
#include "SceneResource.h"
#include "../Object/EffectHit.h"
#include "Camera.h"
#include "../UI/UIStart.h"
#include "../Input.h"
#include "EditorDlg.h"

CEditorScene::CEditorScene() : m_Dlg(nullptr), m_Start(false)
{
}

CEditorScene::~CEditorScene()
{
	SAFE_DELETE(m_Dlg);
}

bool CEditorScene::Init()
{
	LoadSound();

	LoadAnimationSequence();

	m_Start = false;

	m_Dlg = new CEditorDlg;

	m_Dlg->SetScene(this);
	m_Dlg->Init(IDD_DIALOG_EDITOR);

	//CUIStart* StartWindow = CreateUIWindow<CUIStart>("StartWindow");

	return true;
}

bool CEditorScene::Update(float DeltaTime)
{
	if (!m_Start)
	{
		m_Start = true;

		CInput::GetInst()->SetCallback<CEditorScene>("Editor", KeyState_Down, this, &CEditorScene::OnEditor);
	}

	RECT rc = m_Dlg->GetRect();

	POINT ptMouse;
	GetCursorPos(&ptMouse);

	if (rc.left <= ptMouse.x && ptMouse.x <= rc.right && rc.top <= ptMouse.y && ptMouse.y <= rc.bottom)
	{
		if (!CInput::GetInst()->IsShowCursor())
		{
			CInput::GetInst()->SetShowCursor(true);
			ShowCursor(TRUE);
		}
	}

	else
	{
		if (CInput::GetInst()->IsShowCursor())
		{
			CInput::GetInst()->SetShowCursor(false);
			ShowCursor(FALSE);
		}
	}

	return true;
}

bool CEditorScene::PostUpdate(float DeltaTime)
{
	return false;
}

void CEditorScene::LoadAnimationSequence()
{

}

void CEditorScene::LoadSound()
{
	GetSceneResource()->LoadSound("UI", false, "ButtonMouseOn", "TeemoSmile.mp3");
	GetSceneResource()->LoadSound("UI", false, "ButtonClick", "TeemoStartClicck.mp3");

	GetSceneResource()->SetVolume("UI", 30);
}

void CEditorScene::OnEditor(float DeltaTiem)
{
	
}
