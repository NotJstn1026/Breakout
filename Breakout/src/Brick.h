#pragma once
#include <raylib.h>
#include "IGameObject.h"


class GameManager;

class Brick : public IGameObject
{
public:
	Brick(GameManager* a_gameManager);
	~Brick();
	void SetBrickPosition(Vector2 a_position);
	void SetBrickSize(Vector2 a_size);
	void SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size);
	void SetBrickState(bool a_is_active);
	Vector2 GetBrickPostion() const;
	bool GetBrickState() const;

	//Interface
	void Draw() override;
private:
	GameManager* m_gameManager = {};
	Vector2 m_position = {};
	Vector2 m_brickSize = {};
	bool m_state = {};
};

