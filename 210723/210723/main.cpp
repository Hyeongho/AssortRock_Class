#include <iostream>

#include "GameInfo.h"
#include "Player.h"
#include "Monster.h"
#include "Template.h"

// 순환참조: 헤더파일끼리 서로 include를 해주었을 경우를 말한다.
// 순환참조를 해결하는 방법: 전방선언으로 해결

/*
	템플릿 타입을 가변적으로 바꿔줄 떄 사용햘 수 있는 문법이다.
	template <typename 원하는이름>
	template <class 원하는이름>
*/

template <typename T>

void Output(T Number)
{
	std::cout << Number << std::endl;

	std::cout << typeid(T).name() << std::endl;
	//std::cout << typeid(Number).name() << std::endl;
}

template <typename T1, typename T2>

void Output(T1 Number1, T2 Number2)
{
	std::cout << Number1 << std::endl;
	std::cout << Number2 << std::endl;

	std::cout << typeid(T1).name() << std::endl;
	std::cout << typeid(T2).name() << std::endl;

	std::cout << typeid(T1).hash_code() << std::endl;
	std::cout << typeid(T2).hash_code() << std::endl;
}

/*
	템플릿 특수화: 템플릿은 다양한 타입으로 변환되어 들어올 수 있다.
	다양한 타입중 내가 원하는 특정 타입만 함수자체를 새로 구현할 수 있는 기능을 제공하는데 그것을 템플릿 특수화 라고 한다.
*/

template <typename T>
T Add(T Number1, T Number2)
{
	return Number1 + Number2;
}

template <>
float Add(float Number1, float Number2)
{
	std::cout << "float 타입입니다." << std::endl;

	return Number1 + Number2;
}

int main()
{
	CPlayer player;

	player.Output();

	Output<int>(10);
	Output<float>(3.14f);

	//아래처럼 들어간 인자의 타입으로 자동으로 정해질 수도 있다.
	Output(5.24);

	Output<int, float>(10, 3.14f);

	Output(10, 20);

	system("cls");

	CTemplate<int, 100> temp;
	CTemplate<float, 400> temp1;

	CTemplate<float> temp2;

	temp.TestTemplateFunction<CPlayer>();
	temp.TestTemplateFunction<CMonster>();

	std::cout << Add<int>(10, 20) << std::endl;
	std::cout << Add<float>(10.235, 3.14f) << std::endl;

	std::cout << COUNT << std::endl;
	PRINTDEFINE;

	return 0;
}