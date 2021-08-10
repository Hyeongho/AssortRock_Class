#include <iostream>

class CStatic
{
public:
	CStatic()
	{

	}

	~CStatic()
	{

	}

public:
	int m_iNumber;
	static int m_iNumberStatic;

public:
	void Output()
	{

	}

	// static ����Լ������� this�� ����� �� ����.
	// �׷��� ������ �Ϲ� ��������� ����� �� ����.
	// ���⿡���� static ��������� ����� �����ϴ�.
	// �Լ������� ���°� �����Լ�ó�� ������ ���·� ����� �����ϴ�.
	static void OutputStatic()
	{

	}
};

// Ŭ������ static ��������� �ݵ�� Ŭ���� �ܺο� ����κ��� ������־�� �Ѵ�.
// �⺻���� 0���� �ʱ�ȭ �ȴ�. ���ϴ� ���� �������־ �ȴ�.
// Ŭ������ static ��������� �� Ŭ������ �̿��ؼ� ��ü�� �ƹ��� ���� �����ϴ���
// �� ������ �޸𸮴� �� 1���� ������ �ȴ�.
// �Ϲ� ���������� ��ü�� ����ŭ �޸� ������ �Ҵ� ��

int CStatic::m_iNumberStatic;

class CSingleton
{
private:
	CSingleton()
	{

	}

	~CSingleton()
	{

	}

private:
	static CSingleton* m_pInst;

public:
	static CSingleton* GetInst()
	{
		if (m_pInst == nullptr)
		{
			m_pInst == new CSingleton;
		}

		return m_pInst;
	}

	static void DestroyInst()
	{
		if (m_pInst == nullptr)
		{
			return;
		}

		delete m_pInst;
	}
};

CSingleton* CSingleton::m_pInst = nullptr;

int main()
{
	CStatic std1;

	std1.m_iNumberStatic = 100;
	CStatic::m_iNumberStatic = 300;

	std::cout << std1.m_iNumberStatic << std::endl;

	void(*pFunc)() = CStatic::OutputStatic;

	// �Ϲݸ���Լ��� �����ʹ� ������� �ٸ���.

	void(CStatic:: * pFunc1)() = &CStatic::Output;

	// �Ϲ� ����Լ��� �ݵ�� this�� ������ �Ǿ�� �Ѵ�.
	// �׷��� ������ ���ü�� this�� ���������� �ݵ�� ����Ǿ�� �Ѵ�.

	return 0;
}