#include "Player.h"

Player::Player()
{
	float startHeight = (float)GetScreenHeight() * 7 / 8; //Take one-eighth of the screen height for the start point

	m_size = Vector2{ (float)GetScreenWidth() / 8, 8 };
	float startPostionX = ((float)GetScreenWidth() / M_HALFSCREEN);
	m_position = Vector2{ startPostionX - m_size.x * 0.5f, startHeight };
}

Player::~Player()
{
}

Vector2 Player::GetPostion() const
{
	return m_position;
}

Vector2 Player::GetSize() const
{
	return m_size;
}

void Player::Draw()
{
	DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, WHITE);
}

void Player::Update() 
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		Movement(MovementDirection::Left);
	}

	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		Movement(MovementDirection::Right);
	}
}

void Player::Movement(MovementDirection a_movementDirection)
{
	float newPostionX{0};
	if (MovementDirection::Left == a_movementDirection)
	{
		m_position.x -= m_speed;
	}
	else
	{
		m_position.x += m_speed;
	}
}