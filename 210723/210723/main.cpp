#include <iostream>

#include "GameInfo.h"
#include "Player.h"
#include "Monster.h"
#include "Template.h"

// ��ȯ����: ������ϳ��� ���� include�� ���־��� ��츦 ���Ѵ�.
// ��ȯ������ �ذ��ϴ� ���: ���漱������ �ذ�

/*
	���ø� Ÿ���� ���������� �ٲ��� �� ����l �� �ִ� �����̴�.
	template <typename ���ϴ��̸�>
	template <class ���ϴ��̸�>
*/

template <typename T>

void Output(T Number)
{
	std::cout << Number << std::endl;

	std::cout << typeid(T).name() << std::endl;
	//std::cout << typeid(Number).name() << std::endl;
}

template <typename T1, typename T2>

void Output(T1 Number1, T2 Number2)
{
	std::cout << Number1 << std::endl;
	std::cout << Number2 << std::endl;

	std::cout << typeid(T1).name() << std::endl;
	std::cout << typeid(T2).name() << std::endl;

	std::cout << typeid(T1).hash_code() << std::endl;
	std::cout << typeid(T2).hash_code() << std::endl;
}

/*
	���ø� Ư��ȭ: ���ø��� �پ��� Ÿ������ ��ȯ�Ǿ� ���� �� �ִ�.
	�پ��� Ÿ���� ���� ���ϴ� Ư�� Ÿ�Ը� �Լ���ü�� ���� ������ �� �ִ� ����� �����ϴµ� �װ��� ���ø� Ư��ȭ ��� �Ѵ�.
*/

template <typename T>
T Add(T Number1, T Number2)
{
	return Number1 + Number2;
}

template <>
float Add(float Number1, float Number2)
{
	std::cout << "float Ÿ���Դϴ�." << std::endl;

	return Number1 + Number2;
}

int main()
{
	CPlayer player;

	player.Output();

	Output<int>(10);
	Output<float>(3.14f);

	//�Ʒ�ó�� �� ������ Ÿ������ �ڵ����� ������ ���� �ִ�.
	Output(5.24);

	Output<int, float>(10, 3.14f);

	Output(10, 20);

	system("cls");

	CTemplate<int, 100> temp;
	CTemplate<float, 400> temp1;

	CTemplate<float> temp2;

	temp.TestTemplateFunction<CPlayer>();
	temp.TestTemplateFunction<CMonster>();

	std::cout << Add<int>(10, 20) << std::endl;
	std::cout << Add<float>(10.235, 3.14f) << std::endl;

	std::cout << COUNT << std::endl;
	PRINTDEFINE;

	return 0;
}