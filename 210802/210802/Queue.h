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

		// ������ �߰��� ���� ����������� �������� ��Ī�Ѵ�.
		if (m_LastNode)
		{
			m_LastNode->m_Next = Node;
		}

		// ���� ó�� �߰��Ǵ� ����� FristNode�� ���λ����� ���� ä���ش�
		if (!m_FristNode)
		{
			m_FristNode = Node;
		}

		// ���� ������ ��带 ���� ������ ���� �����Ѵ�.
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

