#pragma once

// Ŭ������ ���ø� Ŭ������ ������ְ� �Ǹ� .h �� �����κб��� ��� �Բ� ������־�� �Ѵ�.

template <typename T, int size = 999>

class CTemplate
{
public:
	CTemplate()
	{
		std::cout << typeid(T).name() << std::endl;
		std::cout << "Size: " << size << std::endl;
	}

	~CTemplate()
	{

	}

private:
	T m_T1;
	T m_T2;

public:
	//Ŭ������ ����Լ����� ���� template �� �����Ҽ��� �ִ�.
	template <typename T1>

	void TestTemplateFunction()
	{
		std::cout << "Function Template Type: " << typeid(T1).name() << std::endl;
	}
};

