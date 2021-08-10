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
		rand() 를 이용해서 랜덤한 값을 얻어올때 내부적으로 랜덤한 값이 들어가 있는 표를 이용해서 얻어온다고 볼 수 있다.
		그런데 표를 어떤 표를 사용할 것이다 라고 지정을지정한게 아닌 고정된 표에서 랜덤한 값을 얻어오므로 계속 같은 값이 나오게 하는 것이다.
		그래서 표를 실행할때마다 다른 표로 가져올 수 있게 만들어 주어야 한다.
	*/

	srand(time(0));
	rand();

	/*
		최소 공격력 ~ 최대 동격력
		100 ~ 400 난수 % (최대 - 최소 + 1) + 최소

		확률을 소수점 2자리까지
	*/

	int a = 0;

	for (int i = 0; i < 10000; i++)
	{
		float Percent = rand() % 10001 / 100.0f;

		if (Percent <= 0.01f)
		{
			std::cout << "성공" << std::endl;

			a++;
		}
	}

	std::cout << a << std::endl;

	std::cout << std::endl;

	while (true)
	{
		system("cls");

		int Player = 0;

		std::cout << "1. 가위" << std::endl;
		std::cout << "2. 바위" << std::endl;
		std::cout << "3. 보" << std::endl;
		std::cout << "4. 종료" << std::endl;

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
			std::cout << "AI = 가위" << std::endl;
			break;

		case SRP::R:
			std::cout << "AI = 바위" << std::endl;
			break;

		case SRP::P:
			std::cout << "AI = 보" << std::endl;
			break;

		default:
			break;
		}

		int result = Player - AI;

		if (result == 1 || result == 2)
		{
			std::cout << "승리" << std::endl;
		}

		else if (result == 0)
		{
			std::cout << "비김" << std::endl;
		}

		else
		{
			std::cout << "패배" << std::endl;
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