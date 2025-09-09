#include "Brick.h"

Brick::Brick()
{
}

void Brick::SetBrickPosition(Vector2 a_position)
{
	m_position = a_position;
}

void Brick::SetBrickSize(Vector2 a_size)
{
	m_brickSize = a_size;
}

void Brick::SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size)
{
	SetBrickPosition(a_postion);
	SetBrickSize(a_size);
}

void Brick::SetBrickState(bool a_active)
{
	m_state = a_active;
}

Vector2 Brick::GetBrickPostion() const
{
	return m_position;
}
bool Brick::GetBrickState() const
{
	return m_state;
}
