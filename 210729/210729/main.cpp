#include <iostream>

#include "List.h"

/*
	�ڷᱸ��: �����͸� �����ϴ� ���.

*/

// typedef: Ÿ���� �ٸ� �̸����� ������ ���ִ� ����� �����Ѵ�.

int main()
{

	//MyInt	Test = 100;
	CList<int>		listInt;
	CList<float>	listFloat;

	for (int i = 0; i < 100; ++i)
	{
		listInt.push_back(i);
	}

	std::cout << listInt.back() << std::endl;
	std::cout << listInt.front() << std::endl;

	CList<int>::iterator	iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	//listInt.pop_back();

	// const ��ü�� �Ϲ� ����Լ� ȣ���� �Ұ����ϴ�.
	// �Լ� �ڿ� const�� �پ��ִ� �Լ��� ȣ���� �����ϴ�.
	//const CList<float>	listFloat1;
	//listFloat1.push_back(10.1f);

	return 0;
}