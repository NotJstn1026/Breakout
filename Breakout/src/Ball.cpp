#include "Ball.h"
#include "Brick.h"
#include "Player.h"

/// <summary>
/// Constructs a Ball object at a specified vertical position, initializing its position, radius, and speed.
/// </summary>
/// <param name="a_startPostionX">The vertical (Y-axis) position where the ball will be spawned.</param>
Ball::Ball(float a_startPostionX, std::vector<GameObject*> a_gameObjectList, ShapeType a_ballShape) : GameObject(a_ballShape)
{
	Vector2 spawnPostion = { GetScreenWidth() * 0.5f, a_startPostionX };
	m_postion = spawnPostion;
	m_radius = M_START_RADIUS;
	m_speed = Vector2{ M_RANDOM_VALUES.GetRandomValue(),M_VERTICAL_SPEED };
	m_gameObjects = a_gameObjectList;
}

Ball::~Ball()
{
}

/// <summary>
/// Returns the current position of the ball.
/// </summary>
/// <returns>The position of the ball as a Vector2 object.</returns>
Vector2 Ball::GetBallPostion() const
{
	return m_postion;
}

/// <summary>
/// Retrieves the radius of the ball.
/// </summary>
/// <returns>The radius of the ball as a float.</returns>
float Ball::GetBallRadius() const
{
	return m_radius;
}

/// <summary>
/// Updates the ball´s postion and checks for bounces.
/// </summary>
void Ball::Update()
{
	m_postion.x += m_speed.x;
	m_postion.y += m_speed.y;

	OutOfBoundsCheck();

	HitCheck();
}

/// <summary>
/// Checks if the ball has moved out of the screen bounds and reverses its velocity if necessary.
/// </summary>
void Ball::OutOfBoundsCheck()
{
	if (((m_postion.x + m_radius) >= GetScreenWidth()) || ((m_postion.x - m_radius) <= 0))
	{
		m_speed.x *= -1;
	}
	if ((m_postion.y - m_radius) <= 0 || (m_postion.y + m_radius) >= GetScreenHeight())
	{
		m_speed.y *= -1;
	}
}

/// <summary>
/// Draws the ball on the screen at its current position with its specified radius.
/// </summary>
void Ball::Draw()
{
	DrawCircle(m_postion.x, m_postion.y, m_radius, WHITE);
}


/// <summary>
/// 
/// </summary>
void Ball::HitCheck()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i] == nullptr)
			continue;

		if (m_gameObjects[i]->GetShape() != ShapeType::Rectangle)
			continue;

		if (Player* player = dynamic_cast<Player*>(m_gameObjects[i]))
		{
			Rectangle rec = player->ReturnRectangle();
			if (CheckCollisionCircleRec(m_postion, m_radius, rec))
			{
				m_speed.y *= -1;
				float playerCenterPostionX = player->GetPostion().x + player->GetSize().x * 0.5f;

				float newSpeedX = m_postion.x - playerCenterPostionX;
				newSpeedX *= M_SPEED_FACTOR;

				if (newSpeedX > M_MAX_SPEED.x)
				{
					newSpeedX = M_MAX_SPEED.x;
				}
				if (newSpeedX < -M_MAX_SPEED.x)
				{
					newSpeedX = -M_MAX_SPEED.x;
				}

				m_speed.x = newSpeedX;
				//if (playerCenterPostionX <= m_postion.x)
				//{
				//	MinMaxValue<float> randomX = { 0.5f,3.0f };
				//	float randomValueX = randomX.GetRandomValue();
				//	m_speed.x = randomValueX;
				//}
				//else
				//{
				//	MinMaxValue<float> randomX = { -3.0f,-0.5f };
				//	float randomValueX = randomX.GetRandomValue();
				//	m_speed.x = randomValueX;
				//}
				break;
			}
		}


		if (Brick* currentBrick = dynamic_cast<Brick*>(m_gameObjects[i]))
		{
			Rectangle rec = currentBrick->ReturnRectangle();
			if (CheckCollisionCircleRec(m_postion, m_radius, rec))
			{
				currentBrick->DestroyBrick();
				m_speed.y *= -1;
				if (m_postion.y >= currentBrick->GetBrickPostion().y)
				{
					m_speed.x *= 1;
				}
				break;
			}
		}
	}
}
