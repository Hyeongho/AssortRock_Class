#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "CircleQueue.h"

/*
Queue, Stack
Stack: 선입 후출의 자료구조이다. 먼저 들어간 데이터가 나중에 나오는 구조이다.
Queue: 선입 선출의 자료구조이다. 먼저 들어간 데이터가 먼저 나오는 구조이다.
*/

int main()
{
	int Array[100] = {};

	/*CStack<int> stackInt;

	for (int i = 0; i < 100; i++)
	{
		stackInt.push(i);
	}

	for (int i = 0; i < 100; i++)
	{
		Array[i] = stackInt.top();
		stackInt.pop();
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << Array[i] << std::endl;
	}

	while (!stackInt.empty())
	{
		std::cout << stackInt.top() << std::endl;

		stackInt.pop();
	}*/

	/*CQueue<int> Queue;

	for (int i = 0; i < 100; i++)
	{
		Queue.push(i);
	}

	while (!Queue.empty())
	{
		std::cout << Queue.front() << std::endl;

		Queue.pop();
	}*/

	CCircleQueue<int, 10> CQueue;

	for (int i = 0; i < 5; i++)
	{
		CQueue.push(i);
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << CQueue.front() << std::endl;

		CQueue.pop();
	}

	for (int i = 0; i < 10; i++)
	{
		CQueue.push(i);
	}

	std::cout << "====" << std::endl;

	while (!CQueue.empty())
	{
		std::cout << CQueue.front() << std::endl;

		CQueue.pop();
	}

	return 0;
}