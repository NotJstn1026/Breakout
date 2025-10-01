#pragma once
#include <raylib.h>
#include "IDrawable.h"
#include "MinMaxValue.h"

class Ball : public IDrawable
{
public:
	Ball(float a_startPostion);
	~Ball();
	Vector2 GetBallPostion() const;
	float GetBallRadius() const;
	void Update();

	void Draw() override;
private:
	const float M_START_RADIUS = 7;
	const float M_VERTICAL_SPEED = 3.0f;
	const MinMaxValue<float> m_randomXValues = { -3.0f,3.0f };
	Vector2 m_postion = {};
	Vector2 m_speed = {};
	float m_radius = M_START_RADIUS;
};

