#include "Math.h"

Vector2::Vector2() : x(0.f), y(0.f)
{
}

Vector2::Vector2(float _x, float _y) : x(_x), y(_y)
{
}

Vector2::Vector2(const Vector2& v) : x(v.x), y(v.y)
{
}
