#pragma once
#include <raylib.h>

class Ball
{
public:
	Ball(Vector2 a_startPostion);
	Vector2 GetBallPostion() const;
	float GetBallRadius() const;
private:
	const float M_START_RADIUS = 7;

	Vector2 m_postion = {};
	Vector2 m_speed = {};
	float m_radius = M_START_RADIUS;
};

