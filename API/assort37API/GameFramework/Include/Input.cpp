#include "Input.h"

CInput* CInput::m_Inst = nullptr;

CInput::CInput()
{
	// vector�� size�� capacity�� �ִ�.
	// capacity �� ���� �迭�� �Ҵ�� �����̴�.
	// size �� ���� �߰��� �����̴�.
	// vector resize �Լ� : �� �Լ��� ���ϴ� ������ �����صθ�
	// �ش� ������ŭ�� �̸� �Ҵ��صд�.
	m_vecKeyState.resize(KEYCOUNT_MAX);

	for (int i = 0; i < KEYCOUNT_MAX; ++i)
	{
		m_vecKeyState[i].Key = i;
	}

	// vector reserve �Լ� : capacity�� ���ϴ� ������ŭ �����صд�.

	m_Ctrl = false;
	m_Alt = false;
	m_Shift = false;
}

CInput::~CInput()
{
	std::unordered_map<std::string, KeyInfo*>::iterator iter = m_mapInfo.begin();
	std::unordered_map<std::string, KeyInfo*>::iterator iterEnd = m_mapInfo.end();

	for (; iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}
}

bool CInput::CreateKey(const std::string& Name, int Key)
{
	KeyInfo* Info = FindKeyInfo(Name);

	if (Info)
		return false;

	Info = new KeyInfo;

	Info->Name = Name;
	Info->State.Key = Key;

	m_mapInfo.insert(std::make_pair(Name, Info));

	bool	Add = false;

	size_t	Size = m_vecAddKey.size();

	for (size_t i = 0; i < Size; ++i)
	{
		if (m_vecAddKey[i] == Key)
		{
			// �̹� ���� Ű�� �߰��� �Ǿ��ִ� �����
			// Add�� true�� ������ش�.
			Add = true;
			break;
		}
	}

	// �̹� ���� Ű�� �߰��� �Ǿ� �ִٸ� AddKey�� ����� ���Ѵ�.
	if (!Add)
		m_vecAddKey.push_back(Key);

	return true;
}

bool CInput::SetCtrlKey(const std::string& Name, bool State)
{
	KeyInfo* Info = FindKeyInfo(Name);

	if (!Info)
		return false;

	Info->Ctrl = State;

	return true;
}

bool CInput::SetAltKey(const std::string& Name, bool State)
{
	KeyInfo* Info = FindKeyInfo(Name);

	if (!Info)
		return false;

	Info->Alt = State;

	return true;
}

bool CInput::SetShiftKey(const std::string& Name, bool State)
{
	KeyInfo* Info = FindKeyInfo(Name);

	if (!Info)
		return false;

	Info->Shift = State;

	return true;
}

KeyInfo* CInput::FindKeyInfo(const std::string& Name)
{
	std::unordered_map<std::string, KeyInfo*>::iterator iter = m_mapInfo.find(Name);

	// ��ã���� ��� end�� �����Ѵ�.
	if (iter == m_mapInfo.end())
		return nullptr;

	return iter->second;
}

bool CInput::Init()
{
	// ���ӿ��� ����ϴ� Ű�� �����Ѵ�.
	CreateKey("MoveUp", 'W');
	CreateKey("MoveDown", 'S');
	CreateKey("MoveLeft", 'A');
	CreateKey("MoveRight", 'D');
	CreateKey("Fire", VK_SPACE);
	SetCtrlKey("Fire", true);

	return true;
}

void CInput::Update(float DeltaTime)
{
	// Ű ���¸� ������Ʈ ���ش�.
	UpdateKeyState();

	// ������ ������Ʈ�� ���� ���¸� �̿��ؼ� ���� Ű ������ ������Ʈ�Ѵ�.
	UpdateKeyInfo(DeltaTime);
}

void CInput::UpdateKeyState()
{
	// ��ϵ� Ű ����ŭ �ݺ��ϸ� �ش� Ű�� ������������ �Ǵ��س��´�.
	size_t	Size = m_vecAddKey.size();

	for (size_t i = 0; i < Size; ++i)
	{
		int	Key = m_vecAddKey[i];

		if (GetAsyncKeyState(Key) & 0x8000)
		{
			// ���� �� �������� �ƴϸ� ���� �����Ӻ��� ��� ������ �ִ�������
			// �Ǵ��Ѵ�.
			if (!m_vecKeyState[Key].State[KeyState_Down] &&
				!m_vecKeyState[Key].State[KeyState_Push])
			{
				m_vecKeyState[Key].State[KeyState_Down] = true;
				m_vecKeyState[Key].State[KeyState_Push] = true;
			}

			else
			{
				m_vecKeyState[Key].State[KeyState_Down] = false;
			}
		}

		else if (m_vecKeyState[Key].State[KeyState_Push])
		{
			m_vecKeyState[Key].State[KeyState_Push] = false;
			m_vecKeyState[Key].State[KeyState_Down] = false;
			m_vecKeyState[Key].State[KeyState_Up] = true;
		}

		else if(m_vecKeyState[Key].State[KeyState_Up])
		{
			m_vecKeyState[Key].State[KeyState_Up] = false;
		}
	}

	if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
	{
		m_Ctrl = true;
	}

	else
		m_Ctrl = false;

	if (GetAsyncKeyState(VK_MENU) & 0x8000)
	{
		m_Alt = true;
	}

	else
		m_Alt = false;

	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		m_Shift = true;
	}

	else
		m_Shift = false;
}

void CInput::UpdateKeyInfo(float DeltaTime)
{
	std::unordered_map<std::string, KeyInfo*>::iterator iter = m_mapInfo.begin();
	std::unordered_map<std::string, KeyInfo*>::iterator iterEnd = m_mapInfo.end();

	for (; iter != iterEnd; ++iter)
	{
		int	Key = iter->second->State.Key;

		if (m_vecKeyState[Key].State[KeyState_Down] &&
			iter->second->Ctrl == m_Ctrl &&
			iter->second->Alt == m_Alt &&
			iter->second->Shift == m_Shift)
		{
			if (iter->second->Callback[KeyState_Down])
				iter->second->Callback[KeyState_Down](DeltaTime);
		}

		if (m_vecKeyState[Key].State[KeyState_Push] &&
			iter->second->Ctrl == m_Ctrl &&
			iter->second->Alt == m_Alt &&
			iter->second->Shift == m_Shift)
		{
			if (iter->second->Callback[KeyState_Push])
				iter->second->Callback[KeyState_Push](DeltaTime);
		}

		if (m_vecKeyState[Key].State[KeyState_Up] &&
			iter->second->Ctrl == m_Ctrl &&
			iter->second->Alt == m_Alt &&
			iter->second->Shift == m_Shift)
		{
			if (iter->second->Callback[KeyState_Up])
				iter->second->Callback[KeyState_Up](DeltaTime);
		}
	}
}