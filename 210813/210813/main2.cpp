#include <iostream>

enum class EJob
{
	None, 
	Knight, 
	Archer, 
	Magician
};

struct Player
{
	char Name[32];

	EJob Job;

	int Attack = 0;
	int Armor = 0;
};

int main()
{
	Player player = {};
	strcpy_s(player.Name, "철수");

	player.Job = EJob::Knight;

	player.Attack = 10;
	player.Armor = 5;

	FILE* FileStream;

	fopen_s(&FileStream, "Test.khh", "wb");

	if (FileStream)
	{
		int Number = 100;

		int Array[10] = {};
		for (int i = 0; i < 10; i++)
		{
			Array[i] = i + 1;
		}

		// 1번인자: 저장하고자 하는 변수의 주소가 들어간다.
		// 2번인자: 저장하고자 하는 타입의 크기를 지정한다.
		// 3번인자: 저장하고자 하는 개수를 지정한다.
		// 2번인자 * 3번인자의 바이트 수만큼 1번인자에 지정한 주소로부터 저장하게 된다.
		// 4번인자: 파일스트림이 들어간다.
		fwrite(&Number, sizeof(int), 1, FileStream);
		fwrite(Array, sizeof(int), 10, FileStream);
		fwrite(&player, sizeof(Player), 10, FileStream);

		fclose(FileStream);
	}

	Player player1 = {};
	int Number1 = 0;
	int Array1[10] = {};

	fopen_s(&FileStream, "Test.khh", "rb");

	if (FileStream)
	{
		fread(&Number1, sizeof(int), 1, FileStream);
		fread(Array1, sizeof(int), 10, FileStream);
		fread(&player1, sizeof(Player), 1, FileStream);

		std::cout << "Number1: " << Number1 << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::cout << "Array1[" << i << "]: " << Array1[i] << std::endl;
		}

		std::cout << "이름: " << player1.Name << std::endl;

		std::cout << "직업: ";

		switch (player1.Job)
		{
		case EJob::Knight:
			std::cout << "기사" << std::endl;
			break;

		case EJob::Archer:
			std::cout << "궁수" << std::endl;
			break;

		case EJob::Magician:
			std::cout << "마법사" << std::endl;
			break;
		}

		fclose(FileStream);
	}

	return 0;
}