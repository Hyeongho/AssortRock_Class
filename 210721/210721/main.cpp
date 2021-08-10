#include <iostream>

struct Player
{
	char Name[32];
	int Attack;
	int MaxHP;
	int HP;
	int MaxMP;
	int MP;
};

void Output()
{
	std::cout << "Output Function" << std::endl;
}

void Output1()
{
	std::cout << "Output1 Function" << std::endl;
}

int Add(int Number1, int Number2)
{
	return Number1 + Number2;
}

int Minus(int Number1, int Number2)
{
	return Number1 - Number2;
}

float Add1(float Number1, float Number2)
{
	return Number1 + Number2;
}

void ChangeNumber(int* pNumber)
{
	*pNumber = 300;
}

//구조체는 메모리크기가 큰 구조체를 만들어질 수도 있다.
//그렇기 때문에 단순하게 구조체를 인자로 이렇게 넘길뎡우 구조체의 모든 멤버들을
//복사하게 되는 상황이 발생할 수 있다.
//이 경우 구조체의 크기가 크면 클수록 성능이 떨어지게 된다.
void TestPlayer(Player player)
{

}

//구조체의 값을 변경하는 것이 아니라면 const Reference를 이용해서
//참조를 얻어오고 앞에 const가 붙어있기 때문에 대상의 값을 변경하는 것이 아닌
//단순히 얻어오는 용도로만 사용할 수 있는데 당연히 참조를 하는 방식이기 때문에
//새로운 player를 생성해서 복사하는것이 아닌 참조를 하게 되는 것이다.
//그러므로 몇백바이트 몇천바이트를 복사하게 될 경우 느려지게 될텐데
//단순 참조만 하게 되어 인자를 넘겨주는 속도가 향상될 수 있다.
void TestPlayer1(const Player& player)
{

}

int main()
{
	void (*pFunc)();

	pFunc = Output;

	pFunc();

	pFunc = Output1;

	pFunc();

	int (*pFunc1)(int, int);

	pFunc1 = Add;
	std::cout << pFunc1(10, 20) << std::endl;

	pFunc1 = Minus;
	std::cout << pFunc1(10, 20) << std::endl;

	int (*pFunc2[2])(int, int);

	pFunc2[0] = Add;
	pFunc2[1] = Minus;

	for (int i = 0; i < 2; i++)
	{
		std::cout << pFunc2[i](30, 40) << std::endl;
	}

	int Number = 90;

	ChangeNumber(&Number);

	std::cout << Number << std::endl;

	/*
		레퍼런스: 다른 변수를 참조하는 변수를 만들 수 있다.
		레퍼런스는 반드시 선언과 동시에 참조할 변수를 지정해주어야 한다.
		그 이후에는 다른 변수를 넣더라도 참조가 아닌 해당변수의 값을 레퍼런스가 참조하는 변수에 대입해주는 역할을 한다.
	*/

	int& NumberRef = Number;

	NumberRef = 1234;

	int Number1 = 9099;

	//레퍼런스는 선언할때만 참조하는 변수를 지정하는것이고 그 이후부터는 변수의 값을 참조하는 대상에 대입해주는 역할을 한다.

	NumberRef = Number1;

	std::cout << Number << std::endl;

	Player player = {};

	TestPlayer(player);

	TestPlayer1(player);

	/*
		동적할당: 미리 메모리를 생성하는 것이 아닌 내가 원하는 시점에 메모르릴 생성해줄 수 있는 기능이다.

		new, delete를 이용해서 동적할당에 관련된 기능들을 만들어나갈 수 있다.

		동적할당된 메모리는 힙 영역에 공간이 만들어지게 된다.

		형태
		new 생성하고자하는타입; 을 해주게 되면 해당 타입의 크기만큼을 힙 영역에 공간을 생성하고 생성된 공간의 메모리 주소를 반환한다.

		동적할당된 메모리는 자동으로 안지워진다.
		무조건 delete를 이용해서 해당 메모리를 제거해야 한다.
		만약, 동적할당을 해놓고 delete를 안한다면 메모리 릭이 남게된다.
		메모리 릭은 동적할당하고 안지우면 해당 메모리는 계속 사용된 중이라고 인식되는 것을 말한다.

		delete 메모리 주소; 를 통해서 해당 주소를 제거한다.

		new를 이용해서 생성하면 그 주소가 반환되기 떄문에 이 주소를 제거해야 하는 것이다.
	*/


	//new int 를 하면 힙영역에 4바이트만큼 공간이 할당된다.
	//그 후에 해당 주소를 반환해주고
	//pDynamicNumber 
	int* pDynamicNumber = new int;

	*pDynamicNumber = 2929;

	std::cout << *pDynamicNumber << std::endl;

	delete pDynamicNumber;

	/*
		위에서 동적할당된 메모리는 제거가 되었다.
		문제는 pDynamicNumber에는 아직까지 제거된 힙영역의 메모리 주소가 그대로 들어가 있다.

		이렇게 제거된 메모리 주소를 저장하는 포인터를 댕글링 포인터라고 한다.
		만약 이 댕글링포인터를 사용하려고 한다면 프로그램은 그 즉시 문제가 발생하여 종료될 수 있다.
	*/

	//int크기 * 100 만큼의 힙 영역에 만들어지게 되고 그 시작 주소를 반환해서 pArray 포인터 변수가 주소를 가지고 있게 된다.
	int* pArray = new int[100];

	for (int i = 0; i < 100; i++)
	{
		pArray[i] = i + 1;
	}

	std::cout << pArray << std::endl;

	delete[] pArray;

	//제거가 된 메모리 주소를 가지고 있는 포인터 변수는 항상 nullptr로 초기화를 해주는 것이 좋다.
	//포인터는 다 사용을 했다면 항상 nullptr 로 초기화하는 습관이 필요하다.

	pArray = nullptr;

	std::cout << pArray << std::endl;

	if (pArray != nullptr)
	{
		std::cout << "메모리 주소를 가지고 있다." << std::endl;
	}

	return 0;
}