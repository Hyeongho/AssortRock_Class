#include <iostream>
#include <time.h>

#include "Array.h"

bool SortInt(const int& Left, const int& Right)
{
	return Left > Right;
}

int main()
{
	srand((unsigned int)time(0));
	rand();

	CArray<int>	Arr1;

	for (int i = 0; i < 10; ++i)
	{
		Arr1.push_back(i);
	}

	int	Size = Arr1.size();

	for (int i = 0; i < Size; ++i)
	{
		std::cout << Arr1[i] << std::endl;
	}

	std::cout << std::endl;

	Arr1.erase(8);

	Size = Arr1.size();

	for (int i = 0; i < Size; ++i)
	{
		std::cout << Arr1[i] << std::endl;
	}

	// 복사생성자
	//CArray<int>	Arr2 = Arr1;


	//CArray<int>	Arr3;

	//// 대입연산자
	//Arr3 = Arr1;

	//Arr1.erase(8);

	//Size = Arr1.size();
	//for (int i = 0; i < Size; ++i)
	//{
	//	std::cout << Arr1[i] << std::endl;
	//}

	//std::cout << "Sort" << std::endl;

	//Arr1.sort(SortInt);

	//Size = Arr1.size();
	//for (int i = 0; i < Size; ++i)
	//{
	//	std::cout << Arr1[i] << std::endl;
	//}

	return 0;
}