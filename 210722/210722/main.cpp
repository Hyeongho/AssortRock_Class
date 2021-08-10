#include <iostream>

/*
	객체지향 프로그래밍(OOP): 객체를 제작하여 객체들을 조립하여 하나의 완성된 프로그램을 만들어나가는 방식

	캡슐화: 구조체와 같이 여러 데이터 혹은 함수를 묶어서 사용할 수 있게 만들어주는 속성
	은닉화: 구조체나 클래스의 멤버를 외부에 공개하는 수준을 설정할 수 있는 속성이다.

	- public: 클래스 혹은 구조체의 내부(클래스나 구조체에 만들어져있는 함수 안)와 외부(클래스의 함수 안이아닌 다른 클래스 혹은 다른 함수안)에서 모두 접근이 가능한 속성
	구조체는 아무것도 안붙여줄경우 기본으로 public이다.

	- private: 클래스 혹은 구조체의 내부에서만 접근이 가능하고 외부에서는 접근이 불가능하다.
	클래스는 아무것도 안붙여줄경우 기본으로 private이다.

	- protected: 

	상속성: 
	다형성: 
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
	std::cout << "int타입 1개의 인자가 있는 생성자" << std::endl;
}

CPlayer::CPlayer(int Number1, int Number2, int Number3) : m_Number1(Number1), m_Number2(Number2), m_Number3(Number3)
{
	std::cout << "int타입 3개의 인자가 있는 생성자" << std::endl;
}

CPlayer::CPlayer(const CPlayer& player)
{
	//단순하게 변수의 값들만을 복사하는 방식을 얕은복사라고 한다.

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