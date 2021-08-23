#pragma once

#include "GameInfo.h"

struct KeyState
{
	int Key;
	bool State[KeyState_Max];

	KeyState() : Key(0), State{}
	{

	}
};

struct KeyInfo
{
	std::string Name;
	KeyState State;

	// return type�� void�̰� �Լ��� ���ڴ� floatŸ�� �ϳ��� �޴� �Լ��� �ּҸ� ������ �� �ְ� �Ѵ�.
	std::function<void(float)> Callback[KeyState_Max];
	bool Ctrl;
	bool Alt;
	bool Shift;

	KeyInfo() : Ctrl(false), Alt(false), Shift(false)
	{

	}
};

class CInput
{
private:
	CInput();
	~CInput();

private:
	std::unordered_map<std::string, KeyInfo*> m_mapInfo;
	std::vector<KeyState> m_vecKeyState;
	std::vector<int> m_vecAddKey;

	bool m_Ctrl;
	bool m_Alt;
	bool m_Shift;

public:
	bool CreateKey(const std::string& Name, int Key);
	bool SetCtrlKey(const std::string& Name, bool State);
	bool SetAltKey(const std::string& Name, bool State);
	bool SetShiftKey(const std::string& Name, bool State);

private:
	KeyInfo* FindKeyInfo(const std::string& Name);

public:
	bool Init();
	int Run();
	void Update(float DeltaTime);

private:
	void UpdateKeyState();
	void UpdateKeyInfo(float DeltaTime);

public:
	template <typename T>
	void SetCallback(const std::string& Name, EKeyState State, T* Obj, void(T::* Func)(float))
	{
		KeyInfo* Info = FindKeyInfo(Name);

		// �Լ������͸� �̿��Ͽ� function ��ü�� ������ش�.
		Info->Callback[State] = std::bind(Func, Obj, std::placeholders::_1);
	}

private:
	static CInput* m_Inst;

public:
	static CInput* GetInst()
	{
		if (!m_Inst)
		{
			m_Inst = new CInput;
		}

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}
};
