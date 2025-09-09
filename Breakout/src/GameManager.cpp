#include "GameManager.h"
#include "raylib.h"

void GameManager::InitGame()
{
	float screenWidth = (float)GetScreenWidth();
	Vector2 playerSize = { 50.0f, 50.0f };
	Vector2 brickSize = { GetScreenWidth() / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };

	m_player = new Player(playerSize);


	float ballPostionY = m_player->GetPostion().y - m_player->GetPostion().y / 2;
	m_ball = new Ball(Vector2{ m_player->GetPostion().x, ballPostionY });

	SetBricks(brickSize);
}

void GameManager::SetBricks(Vector2& brickSize)
{
	m_bricks = new Brick * [M_LINES_OF_BRICKS];

	for (int y = 0; y < M_LINES_OF_BRICKS; y++)
	{
		m_bricks[y] = new Brick[M_BRICKS_PER_LINE]{};
	}

	for (int x = 0; x < M_LINES_OF_BRICKS; x++)
	{
		for (int y = 0; y < M_BRICKS_PER_LINE; y++)
		{
			Vector2 brickPostion = { y * brickSize.x + brickSize.x / 2, y * brickSize.y + M_BRICK_SPACE };
			m_bricks[x][y].SetBrickPostionAndSize(brickPostion, brickSize);
			m_bricks[x][y].SetBrickState(true);
		}
	}
}

void GameManager::StartGame()
{
	InitGame();
	InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
	SetTargetFPS(M_TARGET_FPS);


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
		//Draw Player Rectangle
		DrawRectangle(m_player->GetPostion().x / 2, m_player->GetPostion().y / 2, m_player->GetPostion().x, m_player->GetPostion().y, WHITE);

		//Draw Ball
		DrawCircle(m_ball->GetBallPostion().x / 2, m_ball->GetBallPostion().y / 2, m_ball->GetBallRadius(), WHITE);

		//Draw Bricks
		for (int x = 0; x < M_LINES_OF_BRICKS; x++)
		{
			for (int y = 0; y < M_BRICKS_PER_LINE; y++)
			{
				Brick currentBrick = m_bricks[x][y];
				
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

}

void GameManager::EndGame()
{
	delete m_player;
	delete[] m_bricks;
}