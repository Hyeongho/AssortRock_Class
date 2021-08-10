#include <iostream>

/*
	operator: ��� �����ڸ� ���� ���ϴ� ��� �����Ǹ� �ؼ� ����� �� �ִ� ���

	����ü Ȥ�� ���߿� ��� Ŭ�������� operator�� �̿��ؼ� ���ϴ� �����ڸ� ���ϴ� ����� ������� ���� �ִ�.

	����
	��ȯŸ�� operator �������ҿ�����(����)
	{

	}
*/

struct Point
{
	int x;
	int y;

	Point operator + (const Point& pt)
	{
		Point result;
		
		result.x = x + pt.x;
		result.y = y + pt.y;

		return result;
	}

	Point operator + (int Value)
	{
		Point result;

		result.x = x + Value;
		result.y = y + Value;

		return result;
	}

	void operator += (const Point& pt)
	{
		x += pt.x;
		y += pt.y;
	}

	void operator ++ ()
	{
		++x;
		++y;
	}

	//++�� �ڿ� ���϶��� �Ʒ��� ���� ������ operator�� ����ؾ� �ȴ�.
	void operator ++ (int)
	{
		++x;
		++y;
	}
};

int main()
{
	Point pt1, pt2, pt3;

	pt1.x = 10;
	pt1.y = 20;

	pt2.x = 30;
	pt2.y = 40;

	pt3 = pt1 + pt2;

	std::cout << "x: " << pt3.x << ", y: " << pt3.y << std::endl;

	pt3 = pt1 + 5;

	std::cout << "x: " << pt3.x << ", y: " << pt3.y << std::endl;

	pt3 += pt1;

	std::cout << "x: " << pt3.x << ", y: " << pt3.y << std::endl;

	++pt3;

	std::cout << "x: " << pt3.x << ", y: " << pt3.y << std::endl;

	pt3++;

	std::cout << "x: " << pt3.x << ", y: " << pt3.y << std::endl;

	return 0;
}