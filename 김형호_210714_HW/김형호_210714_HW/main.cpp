#include <iostream>
#include <time.h>

int main()
{
	srand((unsigned int)time(0));
	rand();

	int Number[25];

	int Width = 0;
	int WidthBingo = 0;

	int Height = 0;
	int HeightBingo = 0;

	int Line = 0;
	int LineBingo = 0;

	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 25;
		int Index2 = rand() % 25;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	std::cout << std::endl;

	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Number[i * 5 + j] == INT_MAX)
				{
					std::cout << "*" << "\t";
				}

				else
				{
					std::cout << Number[i * 5 + j] << "\t";
				}			
			}

			std::cout << std::endl;
		}

		std::cout << "가로줄 빙고: " << WidthBingo << ", 세로줄 빙고: " << HeightBingo << ", 대각선 빙고: " << LineBingo << std::endl;

		int Input;

		std::cout << std::endl;

		std::cout << "Input Number(0: Exit): ";

		std::cin >> Input;

		if (Input == 0)
		{
			break;
		}

		else if (Input < 0 || Input > 25)
		{
			continue;
		}

		for (int i = 0; i < 25; i++)
		{
			if (Input == Number[i])
			{
				Number[i] = INT_MAX;
			}
		}

		int Bingo = 0;

		// 가로줄 체크

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Number[i * 5 + j] == INT_MAX)
				{
					Width++;
				}
			}

			if (Width == 5)
			{
				Bingo++;

				Width = 0;

				continue;
			}

			Width = 0;
		}

		WidthBingo = Bingo;
		Bingo = 0;

		// 세로줄 체크

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Number[j * 5 + i] == INT_MAX)
				{
					Height++;
				}
			}

			if (Height == 5)
			{
				Bingo++;

				Height = 0;
			}

			Height = 0;
		}

		HeightBingo = Bingo;
		Bingo = 0;

		// 대각선 체크

		for (int i = 0; i <= 24; i += 6)
		{
			if (Number[i] == INT_MAX)
			{
				Line++;
			}
		}

		if (Line == 5)
		{
			Bingo++;

			Line = 0;
		}

		Line = 0;

		for (int i = 4; i <= 20; i += 4)
		{
			if (Number[i] == INT_MAX)
			{
				Line++;
			}
		}

		if (Line == 5)
		{
			Bingo++;

			Line = 0;
		}

		LineBingo = Bingo;
		Bingo = 0;

		Line = 0;
	}

	return 0;
}