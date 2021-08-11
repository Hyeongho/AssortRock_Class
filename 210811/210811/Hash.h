#pragma once

#include <string>

class CHash
{
public:
	CHash()
	{

	}

	~CHash()
	{

	}

private:
	unsigned __int64 m_HasyKey;

public:
	template <typename Key>
	unsigned __int64 GetHash(Key key)
	{
		m_HasyKey = 0;

		size_t Length = sizeof(key);

		unsigned __int64 Newkey = (unsigned __int64)key;

		for (size_t i = 0; i < Length; i++)
		{
			unsigned char data = Newkey & 0xff;

			m_HasyKey += data;

			Newkey >>= 8;
		}

		return m_HasyKey;
	}

	// ���ø� Ư��ȭ: ���ø��� ���� Ÿ�Կ� ���� ������ ó���Լ��� ����� ���� �۾��� �ϰ� ���ش�.
	template <>
	unsigned __int64 GetHash(std::string key)
	{
		m_HasyKey = 0;

		size_t Length = key.length();

		for (size_t i = 0; i < Length; i++)
		{
			if (i % 2 == 0)
			{
				m_HasyKey += (unsigned __int64)key[i];
			}

			else
			{
				m_HasyKey *= (unsigned __int64)key[i];
			}
		}

		return m_HasyKey;

		return m_HasyKey;
	}

	template <>
	unsigned __int64 GetHash(const char* key)
	{
		m_HasyKey = 0;

		size_t Length = strlen(key);

		for (size_t i = 0; i < Length; i++)
		{
			if (i % 2 == 0)
			{
				m_HasyKey += (unsigned __int64)key[i];
			}

			else
			{
				m_HasyKey *= (unsigned __int64)key[i];
			}
		}

		return m_HasyKey;
	}
};

