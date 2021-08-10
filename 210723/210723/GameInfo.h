// #pragma once는 이 헤더파일을 1번만 포함시키도록 해주는 기능이다.
#pragma once

#include <iostream>
#include <time.h>

// #define은 앞에 #이 있기 때문제 전처리기로 처리된다.
// 전처리기란 컴파일 이전에 먼저 처리하는것을 말한다.
// 그래서 전처리기가 모두 처리되고 그 후에 완성된 코드로 컴파일이 일어나게 되는것이다.
// 예를 들어 코드창에 COUNT를 하면 컴파일 전에 COUNT 뒤에 있는 코드를 붙여준다
#define COUNT 10

#define PRINTDEFINE std::cout << "PrintDefine" << std::endl