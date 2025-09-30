#pragma once
#include <raylib.h>
#include "IDrawable.h"
#include "MovementDircetion.h"

class Player : public IDrawable
{
public:
	Player();
	Vector2 GetPostion() const;
	Vector2 GetSize() const;
	void Draw()override;
	void Movement(MovementDirection a_movementDirection);

private:
	const int M_HALFSCREEN = 2;
	

	float m_speed = 5;
	Vector2 m_position = {};
	Vector2 m_size = {};
};