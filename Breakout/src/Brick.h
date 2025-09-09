#pragma once
#include <raylib.h>

class Brick
{
public:
	Brick();
	void SetBrickPosition(Vector2 a_position);

private:
	Vector2 m_position = {};
	Vector2 m_brickSize = {};
	bool m_active = {};
};

