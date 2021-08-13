#include <iostream>

/*
	���������Լ�: �����Լ� �ڿ� = 0 �� �ٿ��ָ� �ش� �����Լ��� ���������Լ��� �ȴ�.
	���������Լ��� �ڽ�Ŭ�������� ������ �����Ǹ� �ؾߵȴ�.
	���� �ڽ�Ŭ�������� �����Ǹ� ���Ѵٸ� �ش� �ڽ�Ŭ������ �߻�Ŭ������ �Ǿ �ش� Ŭ���� Ÿ���� ������ �Ұ����ϴ�.
	���������Լ��� �ش� ���������Լ��� ������ִ� Ŭ������ �����κ��� ���� �ǰ� �ȸ��� �ȴ�.
	���������Լ��� �ڽ�Ŭ�������� ���� ������ �Ǿ�� �ϴ� ��� ���������Լ��� ���� �ڽĿ��� ������ �����Ǹ� �Ͽ� �����ϰԲ� ���鶧 ����Ѵ�.
 


	�߻� Ŭ����: ���������Լ��� ������ �ִ� Ŭ������ �߻�Ŭ������� �Ѵ�.
	�߻�Ŭ������ ��ü������ �Ұ����ϴ�.
*/

class CParent
{
public:
	CParent()
	{

	}

	virtual ~CParent()
	{

	}

public:
	virtual void Output()
	{
		std::cout << "Parent Output" << std::endl;
	}

	virtual void OutputPure() = 0;

	virtual void OutputPure1() = 0
	{
		std::cout << "Parent OutputPure1" << std::endl;
	}
};

class CChild : public CParent
{
public:
	CChild()
	{

	}

	~CChild()
	{

	}

public:
	virtual void Output()
	{
		std::cout << "Child Output" << std::endl;
	}

	virtual void OutputPure()
	{
		std::cout << "Child OutputPure" << std::endl;
	}

	virtual void OutputPure1()
	{
		std::cout << "Child OutputPure1" << std::endl;
	}

};

class CChild1 : public CParent
{
public:
	CChild1()
	{

	}

	~CChild1()
	{

	}

public:
	virtual void OutputPure()
	{
		std::cout << "Child1 OutputPure" << std::endl;
	}

	virtual void OutputPure1()
	{
		std::cout << "Child1 OutputPure1" << std::endl;
	}
};

int main()
{
	CParent* Child = new CChild;
	CParent* Child1 = new CChild1;

	Child->Output();
	Child1->Output();

	delete Child;
	delete Child1;

	return 0;
}