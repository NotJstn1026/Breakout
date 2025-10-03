#pragma once
#include <raylib.h>
#include "IGameObject.h"
#include "MovementDircetion.h"

class Player : public IGameObject
{
public:
	Player();
	~Player();
	Vector2 GetPostion() const;
	Vector2 GetSize() const;
	void Draw()override;

	void Update();
	

private:

	void Movement(MovementDirection a_movementDirection);

	const int M_HALFSCREEN = 2;
	

	float m_speed = 5;
	Vector2 m_position = {};
	Vector2 m_size = {};
};