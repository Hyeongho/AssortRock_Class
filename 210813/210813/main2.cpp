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
	strcpy_s(player.Name, "ö��");

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

		// 1������: �����ϰ��� �ϴ� ������ �ּҰ� ����.
		// 2������: �����ϰ��� �ϴ� Ÿ���� ũ�⸦ �����Ѵ�.
		// 3������: �����ϰ��� �ϴ� ������ �����Ѵ�.
		// 2������ * 3�������� ����Ʈ ����ŭ 1�����ڿ� ������ �ּҷκ��� �����ϰ� �ȴ�.
		// 4������: ���Ͻ�Ʈ���� ����.
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

		std::cout << "�̸�: " << player1.Name << std::endl;

		std::cout << "����: ";

		switch (player1.Job)
		{
		case EJob::Knight:
			std::cout << "���" << std::endl;
			break;

		case EJob::Archer:
			std::cout << "�ü�" << std::endl;
			break;

		case EJob::Magician:
			std::cout << "������" << std::endl;
			break;
		}

		fclose(FileStream);
	}

	return 0;
}