#pragma once
#include <raylib.h>
#include "RectangleGameObject.h"

class GameManager;

class Brick : public RectangleGameObject
{
public:
	Brick(GameManager* a_gameManager, ShapeType a_brickShape);
	~Brick();
	void SetBrickPosition(Vector2 a_position);
	void SetBrickSize(Vector2 a_size);
	void SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size);
	Vector2 GetBrickPostion() const;
	void DestroyBrick();

	//Interface
	void Draw() override;
private:
	GameManager* m_gameManager = nullptr;
};

