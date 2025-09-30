#include <iostream>
#include "GameManager.h"
#include "raylib.h"
#include "MovementDircetion.h"

void GameManager::InitGame()
{
	InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
	SetTargetFPS(M_TARGET_FPS);

	float totalHorizontalSpace = (M_BRICKS_PER_LINE + 1) * M_BRICK_SPACE;
	Vector2 brickSize = { (M_WIDTH - totalHorizontalSpace) / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };

	m_player = new Player();

	m_drawableObjects.push_back(m_player);

	float ballPostionY = m_player->GetPostion().y - m_player->GetPostion().y / 2;

	m_ball = new Ball(ballPostionY);

	m_drawableObjects.push_back(m_ball);

	SetBricks(brickSize);
}

void GameManager::SetBricks(Vector2& brickSize)
{
	float currentHeight = M_BRICK_SPACE;
	float currentWidth = M_BRICK_SPACE;

	for (int y = 0; y < M_LINES_OF_BRICKS; y++)
	{
		currentWidth = M_BRICK_SPACE;

		for (int x = 0; x < M_BRICKS_PER_LINE; x++)
		{
			Brick* brickPtr(new Brick());

			Vector2 brickPostion = { currentWidth, currentHeight };


			brickPtr->SetBrickPostionAndSize(brickPostion, brickSize);
			brickPtr->SetBrickState(true);

			m_drawableObjects.push_back(brickPtr);
			currentWidth += brickSize.x + M_BRICK_SPACE;
		}
		currentHeight += brickSize.y + M_BRICK_SPACE;
	}
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

void GameManager::DrawGame()
{
	BeginDrawing();
	ClearBackground(BLACK);

	if (!m_gameOver)
	{
		int counter = 0;
		for (size_t i = 0; i < m_drawableObjects.size(); i++)
		{
			m_drawableObjects[i]->Draw();
			counter++;
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

	

	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		m_player->Movement(MovementDirection::Left);
	}

	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		m_player->Movement(MovementDirection::Right);
	}

}

void GameManager::EndGame()
{

}