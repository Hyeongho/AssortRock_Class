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

//����ü�� �޸�ũ�Ⱑ ū ����ü�� ������� ���� �ִ�.
//�׷��� ������ �ܼ��ϰ� ����ü�� ���ڷ� �̷��� �ѱ浲�� ����ü�� ��� �������
//�����ϰ� �Ǵ� ��Ȳ�� �߻��� �� �ִ�.
//�� ��� ����ü�� ũ�Ⱑ ũ�� Ŭ���� ������ �������� �ȴ�.
void TestPlayer(Player player)
{

}

//����ü�� ���� �����ϴ� ���� �ƴ϶�� const Reference�� �̿��ؼ�
//������ ������ �տ� const�� �پ��ֱ� ������ ����� ���� �����ϴ� ���� �ƴ�
//�ܼ��� ������ �뵵�θ� ����� �� �ִµ� �翬�� ������ �ϴ� ����̱� ������
//���ο� player�� �����ؼ� �����ϴ°��� �ƴ� ������ �ϰ� �Ǵ� ���̴�.
//�׷��Ƿ� ������Ʈ ��õ����Ʈ�� �����ϰ� �� ��� �������� ���ٵ�
//�ܼ� ������ �ϰ� �Ǿ� ���ڸ� �Ѱ��ִ� �ӵ��� ���� �� �ִ�.
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
		���۷���: �ٸ� ������ �����ϴ� ������ ���� �� �ִ�.
		���۷����� �ݵ�� ����� ���ÿ� ������ ������ �������־�� �Ѵ�.
		�� ���Ŀ��� �ٸ� ������ �ִ��� ������ �ƴ� �ش纯���� ���� ���۷����� �����ϴ� ������ �������ִ� ������ �Ѵ�.
	*/

	int& NumberRef = Number;

	NumberRef = 1234;

	int Number1 = 9099;

	//���۷����� �����Ҷ��� �����ϴ� ������ �����ϴ°��̰� �� ���ĺ��ʹ� ������ ���� �����ϴ� ��� �������ִ� ������ �Ѵ�.

	NumberRef = Number1;

	std::cout << Number << std::endl;

	Player player = {};

	TestPlayer(player);

	TestPlayer1(player);

	/*
		�����Ҵ�: �̸� �޸𸮸� �����ϴ� ���� �ƴ� ���� ���ϴ� ������ �޸𸣸� �������� �� �ִ� ����̴�.

		new, delete�� �̿��ؼ� �����Ҵ翡 ���õ� ��ɵ��� ������ �� �ִ�.

		�����Ҵ�� �޸𸮴� �� ������ ������ ��������� �ȴ�.

		����
		new �����ϰ����ϴ�Ÿ��; �� ���ְ� �Ǹ� �ش� Ÿ���� ũ�⸸ŭ�� �� ������ ������ �����ϰ� ������ ������ �޸� �ּҸ� ��ȯ�Ѵ�.

		�����Ҵ�� �޸𸮴� �ڵ����� ����������.
		������ delete�� �̿��ؼ� �ش� �޸𸮸� �����ؾ� �Ѵ�.
		����, �����Ҵ��� �س��� delete�� ���Ѵٸ� �޸� ���� ���Եȴ�.
		�޸� ���� �����Ҵ��ϰ� ������� �ش� �޸𸮴� ��� ���� ���̶�� �νĵǴ� ���� ���Ѵ�.

		delete �޸� �ּ�; �� ���ؼ� �ش� �ּҸ� �����Ѵ�.

		new�� �̿��ؼ� �����ϸ� �� �ּҰ� ��ȯ�Ǳ� ������ �� �ּҸ� �����ؾ� �ϴ� ���̴�.
	*/


	//new int �� �ϸ� �������� 4����Ʈ��ŭ ������ �Ҵ�ȴ�.
	//�� �Ŀ� �ش� �ּҸ� ��ȯ���ְ�
	//pDynamicNumber 
	int* pDynamicNumber = new int;

	*pDynamicNumber = 2929;

	std::cout << *pDynamicNumber << std::endl;

	delete pDynamicNumber;

	/*
		������ �����Ҵ�� �޸𸮴� ���Ű� �Ǿ���.
		������ pDynamicNumber���� �������� ���ŵ� �������� �޸� �ּҰ� �״�� �� �ִ�.

		�̷��� ���ŵ� �޸� �ּҸ� �����ϴ� �����͸� ��۸� �����Ͷ�� �Ѵ�.
		���� �� ��۸������͸� ����Ϸ��� �Ѵٸ� ���α׷��� �� ��� ������ �߻��Ͽ� ����� �� �ִ�.
	*/

	//intũ�� * 100 ��ŭ�� �� ������ ��������� �ǰ� �� ���� �ּҸ� ��ȯ�ؼ� pArray ������ ������ �ּҸ� ������ �ְ� �ȴ�.
	int* pArray = new int[100];

	for (int i = 0; i < 100; i++)
	{
		pArray[i] = i + 1;
	}

	std::cout << pArray << std::endl;

	delete[] pArray;

	//���Ű� �� �޸� �ּҸ� ������ �ִ� ������ ������ �׻� nullptr�� �ʱ�ȭ�� ���ִ� ���� ����.
	//�����ʹ� �� ����� �ߴٸ� �׻� nullptr �� �ʱ�ȭ�ϴ� ������ �ʿ��ϴ�.

	pArray = nullptr;

	std::cout << pArray << std::endl;

	if (pArray != nullptr)
	{
		std::cout << "�޸� �ּҸ� ������ �ִ�." << std::endl;
	}

	return 0;
}