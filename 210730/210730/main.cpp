#include <iostream>
#include <time.h>

#include "List.h"

bool SortInt(const int& Left, const int& Right)
{
	return Left > Right;
}

int main()
{
	srand((unsigned int)time(0));
	rand();

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

	iter = listInt.erase(80);

	std::cout << "Delete Next Node Data : " << *iter << std::endl;

	listInt.clear();

	for (int i = 0; i < 100; ++i)
	{
		listInt.push_back(rand() % 1000);
	}


	std::cout << "======= Before =======" << std::endl;
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	listInt.sort(SortInt);

	std::cout << "======= After =======" << std::endl;
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	//listInt.pop_back();

	// const 객체는 일반 멤버함수 호출이 불가능하다.
	// 함수 뒤에 const가 붙어있는 함수만 호출이 가능하다.
	//const CList<float>	listFloat1;
	//listFloat1.push_back(10.1f);

	return 0;
}