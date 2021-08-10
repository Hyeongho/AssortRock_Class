#include <iostream>
#include <time.h>

enum class SRP
{
	S = 1,
	R,
	P
};

int main()
{
	/*
		rand() �� �̿��ؼ� ������ ���� ���ö� ���������� ������ ���� �� �ִ� ǥ�� �̿��ؼ� ���´ٰ� �� �� �ִ�.
		�׷��� ǥ�� � ǥ�� ����� ���̴� ��� �����������Ѱ� �ƴ� ������ ǥ���� ������ ���� �����Ƿ� ��� ���� ���� ������ �ϴ� ���̴�.
		�׷��� ǥ�� �����Ҷ����� �ٸ� ǥ�� ������ �� �ְ� ����� �־�� �Ѵ�.
	*/

	srand(time(0));
	rand();

	/*
		�ּ� ���ݷ� ~ �ִ� ���ݷ�
		100 ~ 400 ���� % (�ִ� - �ּ� + 1) + �ּ�

		Ȯ���� �Ҽ��� 2�ڸ�����
	*/

	int a = 0;

	for (int i = 0; i < 10000; i++)
	{
		float Percent = rand() % 10001 / 100.0f;

		if (Percent <= 0.01f)
		{
			std::cout << "����" << std::endl;

			a++;
		}
	}

	std::cout << a << std::endl;

	std::cout << std::endl;

	while (true)
	{
		system("cls");

		int Player = 0;

		std::cout << "1. ����" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "3. ��" << std::endl;
		std::cout << "4. ����" << std::endl;

		std::cin >> Player;

		if (Player == 4)
		{
			break;
		}

		int AI = rand() % 3 + 1;

		SRP AISRP = (SRP)AI;
		SRP PlayerSRP = (SRP)Player;

		switch (AISRP)
		{
		case SRP::S:
			std::cout << "AI = ����" << std::endl;
			break;

		case SRP::R:
			std::cout << "AI = ����" << std::endl;
			break;

		case SRP::P:
			std::cout << "AI = ��" << std::endl;
			break;

		default:
			break;
		}

		int result = Player - AI;

		if (result == 1 || result == 2)
		{
			std::cout << "�¸�" << std::endl;
		}

		else if (result == 0)
		{
			std::cout << "���" << std::endl;
		}

		else
		{
			std::cout << "�й�" << std::endl;
		}

		system("pause");
	}

	/*std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;
	std::cout << rand() % 101 + 100 << std::endl;*/


	/*__int64 Start = time(0);

	int Number = 1;

	for (int i = 0; i < 2147483647; i++)
	{
		Number *= -1;
	}

	__int64 End = time(0);

	std::cout << "Time: " << End - Start << std::endl;

	Start = time(0);

	Number = 1;

	for (int i = 0; i < 2147483647; i++)
	{
		Number = ~Number;
	}

	End = time(0);

	std::cout << "Time: " << End - Start << std::endl;*/

	return 0;
}