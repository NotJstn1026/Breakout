#pragma once
#include <raylib.h>
class Player
{
public: 
	Player(Vector2 a_playerSize);
	int GetCurrentLife() const;
	Vector2 GetPostion() const;
	void UpadtePlayer();

private:
	const int M_MAXLIFE = 5;
	const int M_HALFSCREEN = 2;

	void Movement();

	Vector2 m_postion = {};
	Vector2 m_size = {};
	int m_life = M_MAXLIFE;
};

