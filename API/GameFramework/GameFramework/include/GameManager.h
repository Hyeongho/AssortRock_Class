#pragma once

#include "GameInfo.h"

class CGameManager
{
private:
	CGameManager();
	~CGameManager();

private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	HDC m_hDC;
	HDC m_hBackDC;
	HBITMAP m_hBackBmp;
	HBITMAP m_hPrevBackBmp;
	Resolution m_RS;

	class CTimer* m_Timer;
	float m_TimeScale;

	static bool m_Loop;

public:
	HDC GetWindowDC() const
	{
		return m_hDC;
	}

	HWND GetWindowHandle() const
	{
		return m_hWnd;
	}

	HINSTANCE GetWindowInstance() const
	{
		return m_hInst;
	}

public:
	void SetTimeScale(float TimeScale)
	{
		m_TimeScale = TimeScale;
	}

public:
	float GetDeltaTime() const;

public:
	bool Init(HINSTANCE hInst);
	int Run();

private:
	void Logic();
	bool Update(float DeltaTime);
	bool PostUpdate(float DeltaTime);
	bool Collision(float DeltaTime);
	void Render(float DeltaTime);

private:
	ATOM Register();
	BOOL Create();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	static CGameManager* m_Inst;

public:
	static CGameManager* GetInst()
	{
		if (!m_Inst)
		{
			m_Inst = new CGameManager;
		}

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}
};

