#include <iostream>

/*
	const int* : 참조하고 있는 변수의 값을 변경할 수 없다.
	int *const : 참조하고 있는 메모리 주소를 변경할 수 없다.
	const int* const : 둘다 안된다.
*/

struct Player
{
	char Name[32];
	int Attack;
	int Armor;
	int HP;
	int HPMax;
};

int main()
{
	int Number = 100;
	int Number1 = 200;

	int* pNumber = &Number;

	const int* cpNumber = &Number;
	cpNumber = &Number1;
	//*cpNumber = 300; 참조하고 있는 변수의 값을 바꿀수 없다.

	int* const pcNumber = &Number;
	//pcNumber = &Number1;

	const int* const cpcNumber = &Number;
	//cpcNumber = &Number1;
	//cpcNumber = 999;

	/*
		다중 포인터: 포인터도 변수이기 때문에 메모리에 공간이 할당된다.
		32bit일떄는 4바이트 64bit일때는 8바이트가 할당된다.
		포인터 변수의 주소를 저장하는 포인터도 만들 수 있다.
		일반 변수의 주소는 포인터 변수에 저장하고 포인터 변수의 주소는 포인터의 포인터 변수에 저장한다.
		
	*/

	// 포인터 변수는 다른 변수의 주소를 선언과 동시에 저장해줄것이 아니라면 반드시 nullptr로 초기화를 해주는것이 좋다.

	pNumber = &Number;

	int** ppNumber = &pNumber;
	int*** pppNumber = &ppNumber;

	std::cout << "Number Address: " << &Number << std::endl;
	std::cout << "pNumber Value: " << pNumber << std::endl;
	std::cout << "pNumber Address: " << &pNumber << std::endl;

	std::cout << "ppNumber Value: " << ppNumber << std::endl;
	std::cout << "ppNumber Address: " << &ppNumber << std::endl;

	std::cout << "pppNumber Value: " << pppNumber << std::endl;
	std::cout << "pppNumber Address: " << &pppNumber << std::endl;

	std::cout << "*pNumber: " << *pNumber << std::endl;
	std::cout << "*ppNumber: " << *ppNumber << std::endl;
	std::cout << "*pppNumber: " << *pppNumber << std::endl;

	Player player;

	Player* pPlayer = &player;

	// 역참조 보다 . 이 연산자 우선순위가 높다
	// 그러므로 그냥 *pPlayer.Attack 이렇게 해버릴 경우 문제가 된다.
	// Attack 변수에 대한 역참조가 되버리고 포인터 변수는 실제 구조체 크기만큼 메모리가
	// 만들어져서 사용되는 변수가 아니기 떄문에 참조하는 player의 Attack 변수에 접근하는 것이 아니게 된다.
	// 연산자 우선순위로 인해 (*pPlayer) 를 해서 .을 이용해 접근해야 한다.

	(*pPlayer).Attack = 100;

	pPlayer->Attack = 300;

	std::cout << player.Attack << std::endl;

	Player playerArray[10] = {};
	Player* pPlayerArray = playerArray;

	pPlayerArray[0].Armor = 3939;

	/*
		void: 타입이 없는것을 의미한다.
		void* 타입은 어떤 타입의 메모리 주소든 모두 저장할 수 있다.
		void*는 역참조가 불가능 하다.
		void*는 단순하데 메모리 주소를 저장해두는 용도로만 사용이 된다.
		실제 역참조를 하기 위해서는 정활하게 넣어준 타입으로 형변환을 통해서 역참조를 해야한다.
	*/

	float NumberF = 3.14f;
	float* pNumberF = &NumberF;
	pNumber = (int*)pNumberF;

	void* pTest = &Number;
	pTest = &NumberF;
	pTest = &player;

	((Player*)pTest)->Attack = 300;

	std::cout << *pNumber << std::endl;

	const char* pText = "Test String";
	
	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;
	
	return 0;
}