#include <iostream>

/*
	��ü���� ���α׷���(OOP): ��ü�� �����Ͽ� ��ü���� �����Ͽ� �ϳ��� �ϼ��� ���α׷��� �������� ���

	ĸ��ȭ: ����ü�� ���� ���� ������ Ȥ�� �Լ��� ��� ����� �� �ְ� ������ִ� �Ӽ�
	����ȭ: ����ü�� Ŭ������ ����� �ܺο� �����ϴ� ������ ������ �� �ִ� �Ӽ��̴�.

	- public: Ŭ���� Ȥ�� ����ü�� ����(Ŭ������ ����ü�� ��������ִ� �Լ� ��)�� �ܺ�(Ŭ������ �Լ� ���̾ƴ� �ٸ� Ŭ���� Ȥ�� �ٸ� �Լ���)���� ��� ������ ������ �Ӽ�
	����ü�� �ƹ��͵� �Ⱥٿ��ٰ�� �⺻���� public�̴�.

	- private: Ŭ���� Ȥ�� ����ü�� ���ο����� ������ �����ϰ� �ܺο����� ������ �Ұ����ϴ�.
	Ŭ������ �ƹ��͵� �Ⱥٿ��ٰ�� �⺻���� private�̴�.

	- protected: 

	��Ӽ�: 
	������: 
*/

class CPlayer
{

public:
	int m_Number1;
	int m_Number2;

	int* m_pArray;

	CPlayer();
	CPlayer(int Number1);
	CPlayer(int Number1, int Number2, int Number3);
	CPlayer(const CPlayer& player);
	~CPlayer();

private:
	int m_Number3;
};

CPlayer::CPlayer()
{
	m_pArray = new int[100];

	for (int i = 0; i < 100; i++)
	{
		m_pArray[i] = i + 1;
	}
}

CPlayer::CPlayer(int Number1) : m_Number1(Number1)
{
	std::cout << "intŸ�� 1���� ���ڰ� �ִ� ������" << std::endl;
}

CPlayer::CPlayer(int Number1, int Number2, int Number3) : m_Number1(Number1), m_Number2(Number2), m_Number3(Number3)
{
	std::cout << "intŸ�� 3���� ���ڰ� �ִ� ������" << std::endl;
}

CPlayer::CPlayer(const CPlayer& player)
{
	//�ܼ��ϰ� ������ ���鸸�� �����ϴ� ����� ���������� �Ѵ�.

	m_Number1 = player.m_Number1;
	m_Number1 = player.m_Number2;
	m_Number1 = player.m_Number3;
}

CPlayer::~CPlayer()
{
	delete[] m_pArray;
}

int main()
{
	CPlayer player;

	player.m_Number1 = 1010;
	player.m_Number2 = 2020;

	CPlayer player1(1000);
	CPlayer player2(1000, 2000, 3000);

	return 0;
}