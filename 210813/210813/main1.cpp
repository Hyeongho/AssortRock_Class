#include <iostream>

/*
	���������: �ϵ��ũ�� ������ ����ų� �ִ� ������ �����͸� ����ö� ����Ѵ�.

	C��� ���: fopen �Լ��� �̿��ؼ� ó���Ѵ�.
	C++ ���: ifstream, ofstream �� �̿��ؼ� ó���Ѵ�.
*/

class CPlayer
{
public:
	CPlayer()
	{

	}

	~CPlayer()
	{

	}
};

void CreatePlayer(CPlayer** ppPlayer)
{
	*ppPlayer = new CPlayer;
}

int main()
{
	FILE* FileStream = nullptr;

	/*
		3�� ���ڿ��� Mode�� ����
		r: ������ �о�´�.
		w: ������ �����.
		a: ���Ͽ� �����Ͽ� �̾�⸦ �Ѵ�.
		r+: ������ �����ϸ� �ش� ������ �а� ���� �����ϰ� ����. ������ ������ ������ ��ȯ�Ѵ�.
		w+: ������ �����ϸ� �ش� ������ �а� ���� �����ϰ� ����. ������ ������ ���� ������ش�.
		a+: ������ �����ϸ� ������ ������ �а� ���Ⱑ �Ѵ� �����ϰ� ����. ������ ������ ���� �����.

		t: �ؽ�Ʈ ����
		b: ���̳ʸ� ����
		rt: �ؽ�Ʈ������ �о�´�.
		rb: ���̳ʸ������� �о�´�.
	*/

	fopen_s(&FileStream, "Test.txt", "wt");

	if (FileStream != nullptr)
	{
		// fputc: ���Ͽ� �����ϳ��� �߰��Ѵ�.
		fputc('A', FileStream);
		fputc('T', FileStream);

		fputs("���� �������Դϴ�.\n", FileStream);

		fprintf(FileStream, "fprintf ����Դϴ�.\n");

		int Number = 100;

		fprintf(FileStream, "���ڴ� %d �Դϴ�.\n", Number);

		// ���� ��Ʈ���� �������� �ݵ�� �ݾ���� �ȴ�.
		fclose(FileStream);
	}

	fopen_s(&FileStream, "Test.txt", "rt");

	if (FileStream)
	{
		// 1������: ���� ��Ʈ���� ����.
		// 2������: 3�����ڿ� ������ ���������κ��� �� ����Ʈ�� �̵��Ұ������� �����Ѵ�.
		// 3������: �������� �����ش�.
		// SEEK_CUR: ���� ���� �������� ��ġ�̴�.
		// SEEK_END: ������ ���� �� ��ġ�� �̵��Ѵ�.
		// SEEK_SET: ������ ������ġ�� �̵��Ѵ�.
		fseek(FileStream, 0, SEEK_END);
		
		// ftell: ���� ����Ŀ���� ��ġ�� ���´�.
		int FileSize = ftell(FileStream);

		std::cout << "FileSize: " << FileSize << std::endl;

		fseek(FileStream, 0, SEEK_SET);

		char c = fgetc(FileStream);

		std::cout << c << std::endl;

		char Line[128] = {};

		// fgets �Լ��� \n�� ������ �Ǹ� �ű������ �о���� �ȴ�.
		fgets(Line, 127, FileStream);

		std::cout << Line << std::endl;

		fclose(FileStream);
	}

	/*CPlayer* pPlayer = nullptr;

	CreatePlayer(&pPlayer);*/

	//fopen_s(, );

	return 0;
}