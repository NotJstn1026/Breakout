#include "GameManager.h"
#include "raylib.h"
#include <iostream>

void GameManager::InitGame()
{
	InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
	SetTargetFPS(M_TARGET_FPS);

	float totalHorizontalSpace = (M_BRICKS_PER_LINE + 1) * M_BRICK_SPACE;
	Vector2 brickSize = { (M_WIDTH - totalHorizontalSpace) / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };

	m_player = std::make_shared<Player>();
	m_drawableObjects.push_back(m_player);

	float ballPostionY = m_player->GetPostion().y - m_player->GetPostion().y / 2;

	std::shared_ptr<Ball> ballPtr(new Ball(ballPostionY));
	m_drawableObjects.push_back(ballPtr);

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
			std::shared_ptr<Brick> brickSharedPtr(new Brick());

			Vector2 brickPostion = { currentWidth, currentHeight };


			brickSharedPtr->SetBrickPostionAndSize(brickPostion, brickSize);
			brickSharedPtr->SetBrickState(true);

			m_drawableObjects.push_back(std::move(brickSharedPtr));
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

}

void GameManager::EndGame()
{

}