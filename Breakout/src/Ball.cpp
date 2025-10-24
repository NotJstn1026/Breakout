#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include "GameManager.h"


Ball::Ball(float a_startPostionX, std::vector<GameObject*> a_gameObjectList, GameManager* a_gameManager, ShapeType a_ballShape) : GameObject(a_ballShape)
{
	Vector2 spawnPostion = { GetScreenWidth() * M_HALF, a_startPostionX };
	m_postion = spawnPostion;
	m_radius = M_START_RADIUS;
	m_speed = Vector2{ M_RANDOM_VALUES.GetRandomValue(),M_VERTICAL_SPEED };
	m_gameObjects = a_gameObjectList;
	m_gameManager = a_gameManager;
}

Ball::~Ball()
{
	m_gameManager = nullptr;
}


void Ball::Update()
{
	m_postion.x += m_speed.x;
	m_postion.y += m_speed.y;

	HitCheck();

	OutOfBoundsCheck();
}


void Ball::OutOfBoundsCheck()
{
	if (((m_postion.x + m_radius) >= GetScreenWidth()) || ((m_postion.x - m_radius) <= 0))
	{
		m_speed.x *= M_MINUS_ONE;
	}

	// Hitting top of the screen
	if ((m_postion.y - m_radius) <= 0)
	{
		m_speed.y *= M_MINUS_ONE;
	}

	// Hitting bottom of the screen
	if ((m_postion.y + m_radius) >= GetScreenHeight())
	{
		m_gameManager->DestroyBall(this);
	}
}


void Ball::Draw()
{
	DrawCircle(m_postion.x, m_postion.y, m_radius, WHITE);
}


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
				if(m_postion.x < rec.x || m_postion.x > rec.x + rec.width)
				{
					m_speed.x *= M_MINUS_ONE;
				}

				m_speed.y *= M_MINUS_ONE;
				float playerCenterPostionX = player->GetPostion().x + player->GetSize().x * M_HALF;

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
				m_bounceCounter++;

				if (m_bounceCounter % M_BOUNCE_FOR_EXTRA_BALL == 0)
				{
					m_gameManager->AddBall();
				}

				// Random version

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
		else if (Brick* currentBrick = dynamic_cast<Brick*>(m_gameObjects[i]))
		{
			Rectangle rec = currentBrick->ReturnRectangle();
			if (CheckCollisionCircleRec(m_postion, m_radius, rec))
			{
				if (rec.width + rec.x <= m_postion.x || rec.x >= m_postion.x)
				{
					m_speed.x *= M_MINUS_ONE;
				}
				else
				{
					m_speed.y *= M_MINUS_ONE;
				}

				currentBrick->DestroyBrick();
				m_bounceCounter++;
				if (m_bounceCounter % 10 == 0)
				{
					m_gameManager->AddBall();
				}
				break;
			}
		}
	}
}
