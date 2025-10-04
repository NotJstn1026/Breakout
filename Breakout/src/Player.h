#pragma once
#include <raylib.h>
#include "RectangleGameObject.h"
#include "MovementDircetion.h"

class Player : public RectangleGameObject
{
public:
	Player(ShapeType a_playerShape);
	~Player();
	Vector2 GetPostion() const;
	Vector2 GetSize() const;
	void Draw()override;
	void Update();
	Rectangle ReturnRectangle();

private:
	void Movement(MovementDirection a_movementDirection);
	const int M_HALFSCREEN = 2;
	float m_speed = 5;
};