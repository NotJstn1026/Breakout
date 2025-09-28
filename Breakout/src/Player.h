#pragma once
#include <raylib.h>
#include "IDrawable.h"

class Player : public IDrawable
{
public:
	Player();
	int GetCurrentLife() const;
	Vector2 GetPostion() const;
	Vector2 GetSize() const;
	void Draw()override;
	void UpadtePlayer();

private:
	const int M_MAXLIFE = 5;
	const int M_HALFSCREEN = 2;

	void Movement();

	Vector2 m_position = {};
	Vector2 m_size = {};
	int m_life = M_MAXLIFE;
};

