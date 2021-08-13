#include <iostream>

/*
	파일입출력: 하드디스크에 파일을 만들거나 있는 파일의 데이터를 업어올때 사용한다.

	C언어 방식: fopen 함수를 이용해서 처리한다.
	C++ 방식: ifstream, ofstream 을 이용해서 처리한다.
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
		3번 인자에는 Mode가 들어간다
		r: 파일을 읽어온다.
		w: 파일을 만든다.
		a: 파일에 접근하여 이어쓰기를 한다.
		r+: 파일이 존재하면 해당 파일을 읽고 쓰기 가능하게 연다. 파일이 없으면 에러를 반환한다.
		w+: 파일이 존재하면 해당 파일을 읽고 쓰기 가능하게 연다. 파일이 없으면 새로 만들어준다.
		a+: 파일이 존재하면 파일의 끝부터 읽고 쓰기가 둘다 가능하게 연다. 파일이 없으면 새로 만든다.

		t: 텍스트 파일
		b: 바이너리 파일
		rt: 텍스트파일을 읽어온다.
		rb: 바이너리파일을 읽어온다.
	*/

	fopen_s(&FileStream, "Test.txt", "wt");

	if (FileStream != nullptr)
	{
		// fputc: 파일에 문자하나를 추가한다.
		fputc('A', FileStream);
		fputc('T', FileStream);

		fputs("문자 여러줄입니다.\n", FileStream);

		fprintf(FileStream, "fprintf 출력입니다.\n");

		int Number = 100;

		fprintf(FileStream, "숫자는 %d 입니다.\n", Number);

		// 파일 스트림을 열었으면 반드시 닫아줘야 된다.
		fclose(FileStream);
	}

	fopen_s(&FileStream, "Test.txt", "rt");

	if (FileStream)
	{
		// 1번인자: 파일 스트림이 들어간다.
		// 2번인자: 3번인자에 지정된 기준점으로부터 몇 바이트를 이동할것인지를 지정한다.
		// 3번인자: 기준점을 정해준다.
		// SEEK_CUR: 현재 파일 포인터의 위치이다.
		// SEEK_END: 파일의 가장 끝 위치로 이동한다.
		// SEEK_SET: 파일의 시작위치로 이동한다.
		fseek(FileStream, 0, SEEK_END);
		
		// ftell: 현재 파일커서의 위치를 얻어온다.
		int FileSize = ftell(FileStream);

		std::cout << "FileSize: " << FileSize << std::endl;

		fseek(FileStream, 0, SEEK_SET);

		char c = fgetc(FileStream);

		std::cout << c << std::endl;

		char Line[128] = {};

		// fgets 함수는 \n을 만나게 되면 거기까지만 읽어오게 된다.
		fgets(Line, 127, FileStream);

		std::cout << Line << std::endl;

		fclose(FileStream);
	}

	/*CPlayer* pPlayer = nullptr;

	CreatePlayer(&pPlayer);*/

	//fopen_s(, );

	return 0;
}