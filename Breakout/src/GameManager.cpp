#include <iostream>
#include "GameManager.h"
#include "raylib.h"
#include "MovementDircetion.h"

/// <summary>
/// Inintiales the window and game.
/// </summary>
void GameManager::InitGame()
{
	InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
	SetTargetFPS(M_TARGET_FPS);

	float totalHorizontalSpace = (M_BRICKS_PER_LINE + 1) * M_BRICK_SPACE;
	Vector2 brickSize = { (M_WIDTH - totalHorizontalSpace) / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };


	m_player = new Player();

	m_gameObjects.push_back(m_player);

	AddBall();

	SetBricks(brickSize);
}

/// <summary>
/// 
/// </summary>
/// <param name="brickSize"></param>
void GameManager::SetBricks(Vector2& brickSize)
{
	float currentHeight = M_BRICK_SPACE;
	float currentWidth = M_BRICK_SPACE;

	for (int y = 0; y < M_LINES_OF_BRICKS; y++)
	{
		currentWidth = M_BRICK_SPACE;

		for (int x = 0; x < M_BRICKS_PER_LINE; x++)
		{
			Brick* brickPtr(new Brick(this));

			Vector2 brickPostion = { currentWidth, currentHeight };


			brickPtr->SetBrickPostionAndSize(brickPostion, brickSize);
			brickPtr->SetBrickState(true);

			m_gameObjects.push_back(brickPtr);

			currentWidth += brickSize.x + M_BRICK_SPACE;
		}
		currentHeight += brickSize.y + M_BRICK_SPACE;
	}
}

void GameManager::AddBall()
{
	float ballPostionY = m_player->GetPostion().y - m_player->GetPostion().y / 2;
	Ball* newBall = new Ball(ballPostionY);
	m_balls.push_back(newBall);

	m_gameObjects.push_back(newBall);
}

void GameManager::StartGame()
{
	InitGame();
	while (WindowShouldClose() == false)
	{
		Update();
		DrawGame();
	}
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{

}

void GameManager::DrawGame()
{
	BeginDrawing();
	ClearBackground(BLACK);

	if (!m_gameOver)
	{
		int counter = 0;
		for (size_t i = 0; i < m_gameObjects.size(); i++)
		{
			if (m_gameObjects[i] != nullptr)
			{
				m_gameObjects[i]->Draw();
				counter++;
			}
		}
	}

	EndDrawing();
}

void GameManager::Update()
{
	if (m_gameOver)
	{
		m_gameOver = true;
		EndGame();
		CloseWindow();
		return;
	}

	//Game Logic

	m_player->Update();
	for (size_t i = 0; i < m_balls.size(); i++)
	{
		m_balls[i]->Update();
	}

}

void GameManager::EndGame()
{
	delete m_player;
	m_player = nullptr;

	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		delete m_gameObjects[i];
		m_gameObjects[i] = nullptr;
	}

	for (size_t i = 0; i < m_balls.size(); i++)
	{
		delete m_balls[i];
		m_balls[i] = nullptr;
	}
}