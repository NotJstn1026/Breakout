#pragma once
#include <raylib.h>
#include "IDrawable.h"

class Brick : public IDrawable
{
public:
	Brick();
	void SetBrickPosition(Vector2 a_position);
	void SetBrickSize(Vector2 a_size);
	void SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size);
	void SetBrickState(bool a_is_active);
	Vector2 GetBrickPostion() const;
	bool GetBrickState() const;

	//Interface
	void Draw() override;
private:
	Vector2 m_position = {};
	Vector2 m_brickSize = {};
	bool m_state = {};
};

