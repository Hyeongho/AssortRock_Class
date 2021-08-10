#pragma once

template <typename T>
class CQueueNode
{
	template <typename T>
	friend class CQueue;

private:
	CQueueNode() : m_Next(nullptr)
	{

	}

	~CQueueNode()
	{

	}

private:
	CQueueNode<T>* m_Next;
	T m_Data;
};

template <typename T>
class CQueue
{
public:
	CQueue()
	{
		m_FristNode = nullptr;
		m_LastNode = nullptr;

		m_Size = 0;
	}

	~CQueue()
	{

	}

private:
	CQueueNode<T>* m_FristNode;
	CQueueNode<T>* m_LastNode;

	int m_Size;

public:
	void push(const T& data)
	{
		CQueueNode<T>* Node = new CQueueNode<T>;

		Node->m_Data = data;

		// 기존에 추가된 가장 마지막노드의 다음노드로 지칭한다.
		if (m_LastNode)
		{
			m_LastNode->m_Next = Node;
		}

		// 만약 처음 추가되는 노드라면 FristNode를 새로생성된 노드로 채워준다
		if (!m_FristNode)
		{
			m_FristNode = Node;
		}

		// 가장 마지막 노드를 새로 생성된 노드로 갱신한다.
		m_LastNode = Node;

		m_Size++;
	}

	T& front() const
	{
		if (empty())
		{
			assert(false);
		}

		return m_FristNode->m_Data;
	}

	void pop()
	{
		if (empty())
		{
			assert(false);
		}

		CQueueNode<T>* Next = m_FristNode->m_Next;

		delete m_FristNode;

		m_FristNode = Next;

		if (!m_FristNode)
		{
			m_LastNode = nullptr;
		}

		m_Size--;
	}

	int size() const
	{
		return m_Size;
	}

	bool empty() const
	{
		return m_Size == 0;
	}

	void clear()
	{
		while (m_FristNode)
		{
			CQueueNode<T>* Next = m_FristNode->m_Next;

			delete Next;

			m_FristNode = Next;
		}

		m_LastNode = nullptr;
		m_Size = 0;
	}
};

