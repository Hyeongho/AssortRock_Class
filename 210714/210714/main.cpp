#include <iostream>
#include <time.h>

int main()
{

	//그대로 쓰면 warning이 생겨서 unsigned int로 형변환
	srand((unsigned int)time(0));
	rand();

	/*int Number[6] = {};

	for (int i = 0; i < 6; i++)
	{
		Number[i] = rand() % 45 + 1;

		bool Acc = false;

		for (int j = 0; j <= i; j++)
		{
			if (Number[i] == Number[j])
			{
				Acc = true;

				break;
			}
		}

		if (!Acc)
		{
			i--;

			continue;
		}

		std::cout << rand() % 45 + 1 << std::endl;
	}*/

	//복권게임
	/*int Number[45] = {};
	int Grade[6] = {};

	for (int i = 0; i < 45; i++)
	{
		Number[i] = i + 1;
	}

	int Result[6] = {};

	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 45;
		int Index2 = rand() % 45;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	for (int i = 0; i < 6; i++)
	{
		Result[i] = Number[i];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (Result[i] > Result[j])
			{
				int Temp = Result[i];
				Result[i] = Result[j];
				Result[j] = Temp;
			}
		}
	}

	std::cout << "당첨번호: ";

	for (int i = 0; i < 6; i++)
	{
		std::cout << Result[i] << "\t";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int Game = 0; Game < 1000; Game++)
	{
		for (int i = 0; i < 100; i++)
		{
			int Index1 = rand() % 45;
			int Index2 = rand() % 45;

			int Temp = Number[Index1];
			Number[Index1] = Number[Index2];
			Number[Index2] = Temp;
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (Number[i] > Number[j])
				{
					int Temp = Number[i];
					Number[i] = Number[j];
					Number[j] = Temp;
				}
			}
		}

		for (int i = 0; i < 6; i++)
		{
			std::cout << Number[i] << "\t";
		}

		std::cout << "/ " << Number[6] << " : ";

		int Pair = 0;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Number[i] == Result[j])
				{
					Pair++;

					break;
				}
			}
		}

		switch (Pair)
		{
		case 6:
			std::cout << "1등" << std::endl;
			Grade[0]++;
			break;

		case 5:
		{
			bool Second = false;

			for (int i = 0; i < 6; i++)
			{
				if (Number[6] == Result[i])
				{
					Second = true;

					break;
				}
			}

			if (Second)
			{
				std::cout << "2등" << std::endl;

				Grade[1]++;
			}

			else
			{
				std::cout << "3등" << std::endl;

				Grade[2]++;
			}
		}
			break;

		case 4:
			std::cout << "4등" << std::endl;

			Grade[3]++;
			break;

		case 3:
			std::cout << "5등" << std::endl;

			Grade[4]++;
			break;

		default:
			std::cout << "꽝" << std::endl;

			Grade[5]++;
			break;
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "등: " << Grade[i] << std::endl;
	}

	std::cout << "꽝: " << Grade[5] << std::endl;*/

	
	int Number[9];

	for (int i = 0; i < 9; i++)
	{
		Number[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 9;
		int Index2 = rand() % 9;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	std::cout << Number[0] << ", " << Number[1] << ", " << Number[3] << std::endl;

	int Input[3];

	while (true)
	{
		std::cout << "Input Number(0: Exit)";

		bool Exit = false;

		for (int i = 0; i < 3; i++)
		{
			std::cin >> Input[i];

			if (Input[i] == 0)
			{
				Exit = true;

				break;
			}
		}

		if (Exit)
		{
			break;
		}

		int Strike = 0;
		int Ball = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Number[i] == Input[j])
				{
					if (i == j)
					{
						Strike++;
					}

					else
					{
						Ball++;
					}
				}
			}
		}

		if (Ball == 0 && Strike == 0)
		{
			std::cout << "Out!" << std::endl;
		}

		else if (Strike == 3)
		{
			std::cout << "모두 맞췄습니다." << std::endl;
			break;
		}

		else
		{
			std::cout << "Strike: " << Strike << ", Ball: " << Ball << std::endl;
		}

	}

	return 0;
}