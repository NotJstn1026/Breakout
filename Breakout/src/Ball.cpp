#include "Ball.h"

Ball::Ball(Vector2 a_startPostion)
{
	m_postion = a_startPostion;
	m_radius = M_START_RADIUS;
	m_speed = Vector2{ 0,0 };
}

Vector2 Ball::GetBallPostion() const
{
	return m_postion;
}

float Ball::GetBallRadius() const
{
	return m_radius;
}
