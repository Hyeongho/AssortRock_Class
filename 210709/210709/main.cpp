#include <iostream>

using namespace std;

/*
	����ü: ����� �̸��� �ο����� �� �ִ� ����

	����ü �̸��� ��� ��
	���� ����ü �̸��� �ۼ����شٸ� ����ü �̸��� �ش� ����ü�� ����Ÿ���� ��
	����ڰ� ����Ÿ���� ����� ����
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
		������ �����: �����ڸ� �ٿ��� ����� �� �ִ�. ��� �����ڿ� ���� ����� �����ϴ�.
	*/

	int Buf = 0;

	// Buf = Buf + 1;
	Buf += 1;

	Buf = 10 / 3;

	//	���� / ������ �ϰ� �� ��� �Ҽ��� �ڸ��� ©���� ������ �����κи� ����
	//	����� �Ǽ��� ������ �ϱ� ���ؼ� ���� �ϳ��� �Ǽ�
	//	3.f�� �ϰ� �Ǹ� 3.0f�� ����.

	float Number = 10 / 3.f;

	cout << Number << endl;

	/*
		���� ������: ++, -- 2���� ���� ����

		���� �տ� ���������ڸ� ���̰� �Ǹ� ��ġ����
		���� �ڿ� ���������ڸ� ���̰� �Ǹ� ��ġ����
	*/

	/*
		���׿�����: ���� ? ��1 : ��2 �� ���·� ���
		������ true��� ��1 false�� ��2
	*/

	cout << "char ũ��: " << sizeof(char) << endl;
	cout << "shaor ũ��: " << sizeof(short) << endl;
	cout << "int ũ��: " << sizeof(int) << endl;
	cout << "_int32 ũ��: " << sizeof(_int32) << endl;
	cout << "_int64 ũ��: " << sizeof(_int64) << endl;
	cout << "float ũ��: " << sizeof(float) << endl;
	cout << "double ũ��: " << sizeof(double) << endl;

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