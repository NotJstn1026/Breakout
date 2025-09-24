#include "Player.h"

Player::Player()
{											
	float startHeight = (float)GetScreenHeight() * 7 / 8; //Take one-eighth of the screen height for the start point

	m_postion = Vector2{ (float)GetScreenWidth() / M_HALFSCREEN, startHeight};
	m_size = Vector2{ (float)GetScreenWidth() / 10, 2 };
}

int Player::GetCurrentLife() const
{
	return m_life;
}

Vector2 Player::GetPostion() const
{
	return m_postion;
}

Vector2 Player::GetSize() const
{
	return m_size;
}

void Player::UpadtePlayer()
{
	Movement();
}

void Player::Movement()
{

}