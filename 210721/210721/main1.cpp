#include <iostream>

/*
	operator: 모든 연산자를 내가 원하는 대로 재정의를 해서 사용할 수 있는 기능

	구조체 혹은 나중에 배울 클래스에서 operator를 이용해서 원하는 연산자를 원하는 기능을 만들어줄 수가 있다.

	형태
	반환타입 operator 재정의할연산자(인자)
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

	//++을 뒤에 붙일때는 아래와 같이 설정된 operator을 사용해야 된다.
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