#include <iostream>

/*
	const int* : �����ϰ� �ִ� ������ ���� ������ �� ����.
	int *const : �����ϰ� �ִ� �޸� �ּҸ� ������ �� ����.
	const int* const : �Ѵ� �ȵȴ�.
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
	//*cpNumber = 300; �����ϰ� �ִ� ������ ���� �ٲܼ� ����.

	int* const pcNumber = &Number;
	//pcNumber = &Number1;

	const int* const cpcNumber = &Number;
	//cpcNumber = &Number1;
	//cpcNumber = 999;

	/*
		���� ������: �����͵� �����̱� ������ �޸𸮿� ������ �Ҵ�ȴ�.
		32bit�ϋ��� 4����Ʈ 64bit�϶��� 8����Ʈ�� �Ҵ�ȴ�.
		������ ������ �ּҸ� �����ϴ� �����͵� ���� �� �ִ�.
		�Ϲ� ������ �ּҴ� ������ ������ �����ϰ� ������ ������ �ּҴ� �������� ������ ������ �����Ѵ�.
		
	*/

	// ������ ������ �ٸ� ������ �ּҸ� ����� ���ÿ� �������ٰ��� �ƴ϶�� �ݵ�� nullptr�� �ʱ�ȭ�� ���ִ°��� ����.

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

	// ������ ���� . �� ������ �켱������ ����
	// �׷��Ƿ� �׳� *pPlayer.Attack �̷��� �ع��� ��� ������ �ȴ�.
	// Attack ������ ���� �������� �ǹ����� ������ ������ ���� ����ü ũ�⸸ŭ �޸𸮰�
	// ��������� ���Ǵ� ������ �ƴϱ� ������ �����ϴ� player�� Attack ������ �����ϴ� ���� �ƴϰ� �ȴ�.
	// ������ �켱������ ���� (*pPlayer) �� �ؼ� .�� �̿��� �����ؾ� �Ѵ�.

	(*pPlayer).Attack = 100;

	pPlayer->Attack = 300;

	std::cout << player.Attack << std::endl;

	Player playerArray[10] = {};
	Player* pPlayerArray = playerArray;

	pPlayerArray[0].Armor = 3939;

	/*
		void: Ÿ���� ���°��� �ǹ��Ѵ�.
		void* Ÿ���� � Ÿ���� �޸� �ּҵ� ��� ������ �� �ִ�.
		void*�� �������� �Ұ��� �ϴ�.
		void*�� �ܼ��ϵ� �޸� �ּҸ� �����صδ� �뵵�θ� ����� �ȴ�.
		���� �������� �ϱ� ���ؼ��� ��Ȱ�ϰ� �־��� Ÿ������ ����ȯ�� ���ؼ� �������� �ؾ��Ѵ�.
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