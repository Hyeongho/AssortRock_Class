#include <iostream>
#include <time.h>

int main()
{
	srand((unsigned int)time(0));
	rand();

	int Number[25];
	int AINumber[25];

	int Width = 0;
	int WidthBingo = 0;

	int Height = 0;
	int HeightBingo = 0;

	int Line = 0;
	int LineBingo = 0;

	//AI 체크용

	int AIWidth = 0;
	int AIWidthBingo = 0;

	int AIHeight = 0;
	int AIHeightBingo = 0;

	int AILine = 0;
	int AILineBingo = 0;

	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 25;
		int Index2 = rand() % 25;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;

		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = AINumber[Index1];
		AINumber[Index1] = AINumber[Index2];
		AINumber[Index2] = Temp;
	}

	std::cout << std::endl;

	int AISelect[25] = {};
	int SelectCount = 0;

	while (true)
	{
		system("cls");

		std::cout << "================================== Player ==================================" << std::endl << std::endl;

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

		std::cout << std::endl;

		std::cout << "가로줄 빙고: " << WidthBingo << ", 세로줄 빙고: " << HeightBingo << ", 대각선 빙고: " << LineBingo << std::endl;

		std::cout << std::endl;

		std::cout << "================================== AI ==================================" << std::endl << std::endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (AINumber[i * 5 + j] == INT_MAX)
				{
					std::cout << "*" << "\t";
				}

				else
				{
					std::cout << AINumber[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "가로줄 빙고: " << AIWidthBingo << ", 세로줄 빙고: " << AIHeightBingo << ", 대각선 빙고: " << AILineBingo << std::endl;

		std::cout << std::endl;

		if (WidthBingo + HeightBingo + LineBingo >= 5)
		{
			std::cout << "Player 승리" << std::endl;

			break;
		}

		else if (AIWidthBingo + AIHeightBingo + AILineBingo >= 5)
		{
			std::cout << "AI 승리" << std::endl;

			break;
		}

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

		// Ai의 빙고숫자에서 플레이어가 입력한 값을 찾아서 *로 바꿈

		for (int i = 0; i < 25; i++)
		{
			if (AINumber[i] == Input)
			{
				AINumber[i] = INT_MAX;

				break;
			}
		}

		// AI가 하나 선택한다. 단, 현재 입력이 안된 숫자중 하나를 랜덤하게 선택해야 한다.

		SelectCount = 0;

		for (int i = 0; i < 25; i++)
		{
			if (AINumber[i] != INT_MAX)
			{
				AISelect[SelectCount] = AINumber[i];

				SelectCount++;
			}
		}

		int RandIndex = rand() % SelectCount;
		Input = AISelect[RandIndex];

		// Ai가 선택한 숫자로 플레이어의 숫자중 찾아서 *로 바꿔준다.

		for (int i = 0; i < 25; i++)
		{
			if (Input == Number[i])
			{
				Number[i] = INT_MAX;
			}
		}

		// Ai가 선택한 숫자로 AI의 숫자중 찾아서 *로 바꿔준다.

		for (int i = 0; i < 25; i++)
		{
			if (AINumber[i] == Input)
			{
				AINumber[i] = INT_MAX;

				break;
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

		//AI 체크

		Bingo = 0;

		// 가로줄 체크

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (AINumber[i * 5 + j] == INT_MAX)
				{
					AIWidth++;
				}
			}

			if (AIWidth == 5)
			{
				Bingo++;

				AIWidth = 0;

				continue;
			}

			AIWidth = 0;
		}

		AIWidthBingo = Bingo;
		Bingo = 0;

		// 세로줄 체크

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (AINumber[j * 5 + i] == INT_MAX)
				{
					AIHeight++;
				}
			}

			if (AIHeight == 5)
			{
				Bingo++;

				AIHeight = 0;
			}

			AIHeight = 0;
		}

		AIHeightBingo = Bingo;
		Bingo = 0;

		// 대각선 체크

		for (int i = 0; i <= 24; i += 6)
		{
			if (AINumber[i] == INT_MAX)
			{
				AILine++;
			}
		}

		if (AILine == 5)
		{
			Bingo++;

			AILine = 0;
		}

		AILine = 0;

		for (int i = 4; i <= 20; i += 4)
		{
			if (AINumber[i] == INT_MAX)
			{
				AILine++;
			}
		}

		if (AILine == 5)
		{
			Bingo++;

			AILine = 0;
		}

		AILineBingo = Bingo;
		Bingo = 0;

		AILine = 0;
	}

	return 0;
}