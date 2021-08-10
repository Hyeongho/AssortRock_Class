#include <iostream>

using namespace std;

/*
	열거체: 상수에 이름을 부여해줄 수 있는 문법

	열거체 이름은 없어도 됨
	만약 열거체 이름을 작성해준다면 열거체 이름은 해당 열거체의 변수타입이 됨
	사용자가 변수타입을 만들수 있음
*/

enum JOB
{

};

enum class JOB1
{
	Knight, 
	Archer, 
	Magicion
};

int main()
{
	/*
		연산자 축약형: 연산자를 줄여서 사용할 수 있다. 모든 연산자에 대해 축약이 가능하다.
	*/

	int Buf = 0;

	// Buf = Buf + 1;
	Buf += 1;

	Buf = 10 / 3;

	//	정수 / 정수를 하게 될 경우 소수점 자리가 짤리고 무조건 정수부분만 남음
	//	결과로 실수가 나오게 하기 위해서 둘중 하나는 실수
	//	3.f를 하게 되면 3.0f와 같다.

	float Number = 10 / 3.f;

	cout << Number << endl;

	/*
		증감 연산자: ++, -- 2가지 연산 지원

		변수 앞에 증감연산자를 붙이게 되면 전치연산
		변수 뒤에 증감연산자를 붙이게 되면 후치연산
	*/

	/*
		삼항연산자: 조건 ? 값1 : 값2 의 현태로 사용
		조건이 true라면 값1 false면 값2
	*/

	cout << "char 크기: " << sizeof(char) << endl;
	cout << "shaor 크기: " << sizeof(short) << endl;
	cout << "int 크기: " << sizeof(int) << endl;
	cout << "_int32 크기: " << sizeof(_int32) << endl;
	cout << "_int64 크기: " << sizeof(_int64) << endl;
	cout << "float 크기: " << sizeof(float) << endl;
	cout << "double 크기: " << sizeof(double) << endl;

	JOB1 job1 = JOB1::Archer;

	switch (job1)
	{
	case JOB1::Knight:
		break;
	case JOB1::Archer:
		break;
	case JOB1::Magicion:
		break;
	default:
		break;
	}

	return 0;
}