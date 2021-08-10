#include <iostream>

#include "List.h"

/*
	자료구조: 데이터를 관리하는 방법.

*/

// typedef: 타입을 다른 이름으로 재정의 해주는 기능을 제공한다.

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

	// const 객체는 일반 멤버함수 호출이 불가능하다.
	// 함수 뒤에 const가 붙어있는 함수만 호출이 가능하다.
	//const CList<float>	listFloat1;
	//listFloat1.push_back(10.1f);

	return 0;
}