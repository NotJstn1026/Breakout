#include <iostream>
#include <string>
#include "GameManager.h"
#include "raylib.h"
#include "MOVEMENTDIRECTION.h"


void GameManager::InitGame()
{
	if (!IsWindowReady())
	{
		InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
		SetTargetFPS(M_TARGET_FPS);
	}

	m_player = new Player(ShapeType::Rectangle);

	m_gameObjects.push_back(m_player);

	SetBricks();

	AddBall();
}

void GameManager::SetBricks()
{
	float totalHorizontalSpace = (M_BRICKS_PER_LINE + 1) * M_BRICK_SPACE;
	Vector2 brickSize = { (M_WIDTH - totalHorizontalSpace) / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };

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

			brickPtr->SetBrickPostionAndSize(brickPostion, brickSize);

			m_gameObjects.push_back(brickPtr);

			currentWidth += brickSize.x + M_BRICK_SPACE;

			m_brickCount++;
		}
		currentHeight += brickSize.y + M_BRICK_SPACE;
	}
}

void GameManager::AddBall()
{
	float ballPostionY = m_player->GetPostion().y - m_player->GetPostion().y / M_ONE_AND_A_HALF;
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
	while (WindowShouldClose() == false || m_gameOver)
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
			m_brickCount--;
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

		DrawText("Press SPACE to Start the Game", M_STARTMENU_POS_X, M_HEIGHT * M_HALF, M_TEXT_SIZE, WHITE);
		break;

	case GAMESCENE::GS_GAME:

		if (!m_gameOver)
		{
			for (size_t i = 0; i < m_gameObjects.size(); i++)
			{
				if (m_gameObjects[i] != nullptr)
				{
					m_gameObjects[i]->Draw();
				}
			}

			DrawText(std::to_string(m_playerScore).c_str(), M_POINTS_POSITION_X, M_POINTS_POSITION_Y, M_TEXT_SIZE, WHITE);
		}

		break;

	case GAMESCENE::GS_GAMEOVER:
		DrawText("Game Over!", M_GAME_OVER_POS_X, M_GAME_OVER_POS_Y, M_TEXT_SIZE, WHITE);
		DrawText("Your score: ", M_GAME_OVER_POS_X, M_SCORE_LABEL_POS_Y, M_TEXT_SIZE, WHITE);
		DrawText(std::to_string(m_playerScore).c_str(), M_SCORE_LABEL_POS_X, M_SCORE_VALUE_POS_Y, M_TEXT_SIZE, WHITE);
		DrawText("Press ESC to Exit", M_EXIT_POS_X, M_EXIT_POS_Y, M_TEXT_SIZE, WHITE);
		DrawText("Press SPACE to Restart", M_RESTART_POS_X, M_RESTART_POS_Y, M_TEXT_SIZE, WHITE);

		break;
	default:
		m_currentGameScene = GAMESCENE::GS_STARTMENU;
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

		if (m_brickCount == 0)
		{
			SetBricks();
		}

		break;

	case GAMESCENE::GS_GAMEOVER:
		if (IsKeyPressed(KEY_ESCAPE))
		{
			EndGame();
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			RestartGame();
		}

		break;
	default:
		m_currentGameScene = GAMESCENE::GS_STARTMENU;
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
	m_gameOver = true;
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
