#pragma once

enum EKeyState
{
	KeyState_Down, 
	KeyState_Push,
	KeyState_Up, 
	KeyState_Max
};

enum class ETexture_Type
{
	Atlas,
	Frame
};

enum class ECollider_Type
{
	Box, 
	Sphere, 
	Point
};