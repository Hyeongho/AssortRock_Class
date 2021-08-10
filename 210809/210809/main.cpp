#include <iostream>

#include "Graph.h"

void OutputNode(const int& data)
{
	std::cout << data << " -> ";
}

int main()
{
	CGraph<int> graph;

	for (int i = 1; i <= 9; i++)
	{
		graph.insert(i);
	}

	graph.AddEdge(1, 2);
	graph.AddEdge(1, 5);
	graph.AddEdge(1, 7);

	graph.AddEdge(2, 3);
	graph.AddEdge(5, 6);
	graph.AddEdge(7, 8);

	graph.AddEdge(3, 4);
	graph.AddEdge(8, 9);

	//graph.BFS(1);

	graph.BFS(OutputNode);

	std::cout << std::endl;

	//graph.DFS(1);

	return 0;
}