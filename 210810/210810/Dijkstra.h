#pragma once

#pragma once

#include <assert.h>
#include "Queue.h"
#include "Stack.h"
#include "Heap.h"
#include "List.h"

template <typename T>
class CEdge
{
	template <typename T>
	friend class CDijktra;

	template <typename T>
	friend class CDijktraNode;

private:
	CEdge()
	{
		m_Node = nullptr;
	}

	~CEdge()
	{
	}

private:
	class CDijktraNode<T>* m_Node;
	int m_Cost;
};

template <typename T>
class CDijktraNode
{
	template <typename T>
	friend class CDijktra;

private:
	CDijktraNode()
	{
		m_Size = 0;
		m_Capacity = 1;
		m_EdgeArray = new CEdge<T>*[m_Capacity];
		m_Visit = false;
		m_Cost = INT_MAX;
		m_Parent = nullptr;
	}

	~CDijktraNode()
	{
		for (int i = 0; i < m_Size; ++i)
		{
			delete	m_EdgeArray[i];
		}

		delete[]	m_EdgeArray;
	}

private:
	CDijktraNode<T>* m_Parent;
	CEdge<T>** m_EdgeArray;
	int	m_Size;
	int	m_Capacity;
	T m_Data;
	bool m_Visit;
	int m_Cost;

private:
	void AddEdge(CDijktraNode<T>* Node, int Cost)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;

			CEdge<T>** Array = new CEdge<T>*[m_Capacity];

			memcpy(Array, m_EdgeArray, sizeof(CEdge<T>*) * m_Size);

			delete[]	m_EdgeArray;

			m_EdgeArray = Array;
		}

		CEdge<T>* Edge = new CEdge<T>;
		Edge->m_Node = Node;
		Edge->m_Cost = Cost;

		m_EdgeArray[m_Size] = Edge;
		m_Size++;
	}

	void Add(CHeap<CDijktraNode<T>*>& heap)
	{
		for (int i = 0; i < m_Size; i++)
		{
			// 현재 노드의 비용과 Edge의 비용을 더하여 Edge에 연결된 노드의 비용과 비교를 하고
			// 만약 이 비용이 Edge에 연결된 노드의 비용보다 더 작다면 부모 노드를 교체해주고 비용을 교체한다.
			if (m_Cost + m_EdgeArray[i]->m_Cost < m_EdgeArray[i]->m_Node->m_Cost)
			{
				m_EdgeArray[i]->m_Node->m_Cost = m_Cost + m_EdgeArray[i]->m_Cost;
				m_EdgeArray[i]->m_Node->m_Parent = this;
			}

			// 방문을 안한 노드라면 heap에 넣어서 연결된 노드를 판단해본다.
			if (!m_EdgeArray[i]->m_Node->m_Visit)
			{
				heap.push(m_EdgeArray[i]->m_Node);
				m_EdgeArray[i]->m_Node->m_Visit = true;
			}
		}
	}
};

template <typename T>
class CDijktra
{
public:
	CDijktra()
	{
		m_Size = 0;
		m_Capacity = 4;

		m_NodeArray = new CDijktraNode<T>*[m_Capacity];
	}

	~CDijktra()
	{
		for (int i = 0; i < m_Size; ++i)
		{
			delete	m_NodeArray[i];
		}

		delete[]	m_NodeArray;
	}

private:
	CDijktraNode<T>** m_NodeArray;
	int m_Size;
	int m_Capacity;

public:
	void insert(const T& data)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;

			CDijktraNode<T>** Array = new CDijktraNode<T>*[m_Capacity];

			memcpy(Array, m_NodeArray, sizeof(CDijktraNode<T>*) * m_Size);

			delete[] m_NodeArray;

			m_NodeArray = Array;
		}

		CDijktraNode<T>* Node = new CDijktraNode<T>;

		Node->m_Data = data;

		m_NodeArray[m_Size] = Node;
		m_Size++;
	}

	// 노드에 edge를 추가해준다.
	void AddEdge(const T& Src, const T& Dest, int Cost)
	{
		CDijktraNode<T>* SrcNode = nullptr;
		CDijktraNode<T>* DestNode = nullptr;

		for (int i = 0; i < m_Size; i++)
		{
			if (m_NodeArray[i]->m_Data == Src)
			{
				SrcNode = m_NodeArray[i];
			}

			else if (m_NodeArray[i]->m_Data == Dest)
			{
				DestNode = m_NodeArray[i];
			}

			if (SrcNode && DestNode)
			{
				break;
			}		
		}

		if (!SrcNode || !DestNode)
		{
			return;
		}

		SrcNode->AddEdge(DestNode, Cost);
		DestNode->AddEdge(SrcNode, Cost);
	}

	bool Find(CList<T>* ResultList, const T& Start, const T& End)
	{
		CDijktraNode<T>* StartNode = FindNode(Start);

		if (!StartNode)
		{
			return false;
		}

		CDijktraNode<T>* EndNode = FindNode(End);

		if (!EndNode)
		{
			return false;
		}

		// 모든 노드의 정보를 초기화해준다.
		for (int i = 0; i < m_Size; i++)
		{
			m_NodeArray[i]->m_Cost = INT_MAX;
			m_NodeArray[i]->m_Parent = nullptr;
			m_NodeArray[i]->m_Visit = false;
		}

		// 시작노드의 비용을 0으로 처리한다.
		StartNode->m_Cost = 0;

		// 비용의 크기에 따라 정렬해서 사용해야 하므로 Heap을 사용한다
		CHeap<CDijktraNode<T>*> heap;
		heap.SetSortFunction(SortNode);

		// 시작노드를 방문상태로 만들고 heap에 넣어준다
		StartNode->m_Visit = true;

		heap.push(StartNode);

		while (!heap.empty())
		{
			CDijktraNode<T>* Node = heap.top();

			heap.pop();

			Node->Add(heap);
		}

		CDijktraNode<T>* Node = EndNode;

		while (Node)
		{
			ResultList->push_front(Node->m_Data);
			Node = Node->m_Parent;
		}

		return true;
	}

private:
	CDijktraNode<T>* FindNode(const T& data)
	{
		for (int i = 0; i < m_Size; i++)
		{
			if (m_NodeArray[i]->m_Data == data)
			{
				return m_NodeArray[i];
			}
		}

		return nullptr;
	}

	static bool SortNode(CDijktraNode<T>* const& Left, CDijktraNode<T>* const& Right)
	{
		return Left->m_Cost > Right->m_Cost;
	}
};