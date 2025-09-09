#include "GameManager.h"
#include "raylib.h"

void GameManager::InitGame()
{
	float screenWidth = (float)GetScreenWidth();
	Vector2 playerSize = { 50.0f, 50.0f };
	Vector2 brickSize = { GetScreenWidth() / M_BRICKS_PER_LINE, M_BRICK_HEIGHT };

	m_player = new Player(playerSize);

	m_ball = new Ball(m_player->GetPostion());

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
			m_bricks[x][y].SetBrickPosition(brickPostion);
		}
	}
	
}

void GameManager::StartGame()
{
	InitWindow(M_WIDTH, M_HEIGHT, M_GAME_NAME);
	SetTargetFPS(M_TARGET_FPS);

	while (WindowShouldClose() == false)
	{

		//ClearBackground(BLACK);



		//BeginDrawing();
		//EndDrawing();
	}

	CloseWindow();
}

void GameManager::EndGame() 
{
	delete m_player;
	delete[] m_bricks;
}