#pragma once
#include <raylib.h>
class Brick
{
public:
	Brick(Vector2 a_position, float a_brickSize);
private:
	Vector2 m_position = {};
	float m_brickSize = {};
	bool m_active = {};
};

