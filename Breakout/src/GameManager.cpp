#include <iostream>
#include "GameManager.h"
#include "raylib.h"
#include "MOVEMENTDIRECTION.h"
#include <string>

/// <summary>
/// Inintiales the window and game.
/// </summary>
void GameManager::InitGame()
{
	if (!IsWindowReady())
	{
		InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
		SetTargetFPS(M_TARGET_FPS);
	}

	float totalHorizontalSpace = (M_BRICKS_PER_LINE + 1) * M_BRICK_SPACE;

	Vector2 brickSize = { (M_WIDTH - totalHorizontalSpace) / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };

	m_player = new Player(ShapeType::Rectangle);

	m_gameObjects.push_back(m_player);

	SetBricks(brickSize);

	AddBall();
}

/// <summary>
/// 
/// </summary>
/// <param name="brickSize"></param>
void GameManager::SetBricks(Vector2& a_brickSize)
{
	float currentHeight = M_BRICK_SPACE;
	float currentWidth = M_BRICK_SPACE;

	// Make Room for Text above the bricks
	currentHeight += M_START_HEIGTH_BRICKS;

	for (int y = 0; y < M_LINES_OF_BRICKS; y++)
	{
		currentWidth = M_BRICK_SPACE;

		for (int x = 0; x < M_BRICKS_PER_LINE; x++)
		{
			Brick* brickPtr(new Brick(this, ShapeType::Rectangle));

			Vector2 brickPostion = { currentWidth, currentHeight };

			brickPtr->SetColor(M_BRICK_COLOR[y]);

			brickPtr->SetBrickPostionAndSize(brickPostion, a_brickSize);

			m_gameObjects.push_back(brickPtr);

			currentWidth += a_brickSize.x + M_BRICK_SPACE;
		}
		currentHeight += a_brickSize.y + M_BRICK_SPACE;
	}
}

void GameManager::AddBall()
{
	float ballPostionY = m_player->GetPostion().y - m_player->GetPostion().y / 1.5f;
	Ball* newBall = new Ball(ballPostionY, m_gameObjects, this, ShapeType::Circle);
	m_balls.push_back(newBall);

	m_gameObjects.push_back(newBall);
}

void GameManager::DestroyBall(Ball* a_ballPtr)
{
	for (size_t i = 0; i < m_balls.size(); i++)
	{
		if (m_balls[i] == a_ballPtr)
		{
			m_balls[i] = nullptr;
			m_balls.erase(m_balls.begin() + i);
			break;
		}
	}

	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i] == a_ballPtr)
		{
			delete m_gameObjects[i];
			m_gameObjects[i] = nullptr;
			m_gameObjects.erase(m_gameObjects.begin() + i);
			break;
		}
	}
}

void GameManager::StartGameManager()
{
	InitGame();
	while (WindowShouldClose() == false)
	{
		Update();
		DrawGame();
	}
}

void GameManager::DestroyBrick(Brick* a_brickPtr)
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		if (a_brickPtr == m_gameObjects[i])
		{
			delete m_gameObjects[i];
			m_gameObjects[i] = nullptr;
			m_gameObjects.erase(m_gameObjects.begin() + i);
			m_playerScore += M_BRICK_POINTS;
			break;
		}
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
	switch (m_currentGameScene)
	{
	case GAMESCENE::GS_STARTMENU:

		DrawText("Press SPACE to Start the Game", 200, 200, 20, WHITE);
		break;

	case GAMESCENE::GS_GAME:


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
			DrawText(std::to_string(m_playerScore).c_str(), 10, 10, 20, WHITE);
		}



		break;

	case GAMESCENE::GS_GAMEOVER:
		DrawText("Game Over!", 300, 200, 20, WHITE);
		DrawText("Press ENTER to Exit", 280, 240, 20, WHITE);
		DrawText("Press SPACE to Restart", 260, 280, 20, WHITE);

		break;
	default:
		break;
	}



	EndDrawing();
}

void GameManager::Update()
{

	switch (m_currentGameScene)
	{
	case GAMESCENE::GS_STARTMENU:
		if (IsKeyPressed(KEY_SPACE))
		{
			m_currentGameScene = GAMESCENE::GS_GAME;
		}
		break;
	case GAMESCENE::GS_GAME:

		if (m_balls.size() == 0)
		{
			m_currentGameScene = GAMESCENE::GS_GAMEOVER;
			break;
		}

		for (size_t i = 0; i < m_balls.size(); i++)
		{
			m_balls[i]->Update();
		}
		m_player->Update();
		break;

	case GAMESCENE::GS_GAMEOVER:
		if (IsKeyPressed(KEY_ENTER))
		{
			EndGame();
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			RestartGame();
		}

		break;
	default:
		break;
	}

}

void GameManager::EndGame()
{

	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i] != nullptr)delete m_gameObjects[i];
		m_gameObjects[i] = nullptr;
	}
	CloseWindow();
}

void GameManager::RestartGame()
{
	m_gameOver = false;
	m_playerScore = 0;
	m_currentGameScene = GAMESCENE::GS_STARTMENU;
	m_balls.clear();
	m_gameObjects.clear();
	InitGame();
}
