#include <iostream>
#include <time.h>

#include "Heep.h"
#include "QuickSort.h"
#include "MergeSort.h"

template <typename T>
bool Sort(const T& Left, const T& Right)
{
	return Left < Right;
}

int main()
{
	srand((unsigned int)time(0));
	rand();

	/*CHeap<int> heap;

	heap.SortFunction(Sort);

	for (int i = 0; i < 20; i++)
	{
		heap.push(rand());
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << heap.top() << std::endl;
		heap.pop();
	}*/

	/*CQuickSort<int> Quick;
	Quick.SortFunction(Sort);

	int Array[20] = {};

	for (int i = 0; i < 20; i++)
	{
		Array[i] = rand();
		std::cout << Array[i] << std::endl;
	}

	Quick.Sort(Array, 20);

	std::cout << "======================== Sort ========================" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		std::cout << Array[i] << std::endl;
	}*/

	CMergeSort<int> Merge;
	Merge.SortFunction(Sort);

	int Array[20] = {};

	for (int i = 0; i < 20; i++)
	{
		Array[i] = rand();
		std::cout << Array[i] << std::endl;
	}

	Merge.Sort(Array, 20);

	std::cout << "======================== Sort ========================" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		std::cout << Array[i] << std::endl;
	}

	return 0;
}