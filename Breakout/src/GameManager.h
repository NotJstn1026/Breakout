#pragma once
#include <iostream>
#include "Player.h"
#include "Brick.h"
#include "Ball.h"
#include "IDrawable.h"
#include <vector>

class GameManager
{
public:
	void StartGame();
	GameManager();
	~GameManager();
private:
	void InitGame();
	void SetBricks(Vector2& brickSize);
	void AddBall();
	void DrawGame();
	void Update();
	void EndGame();

	const float M_WIDTH = 700;
	const float M_HEIGHT = 500;
	const float M_TARGET_FPS = 60;
	const char* M_GAME_NAME = "Breakout";

	//Bricks
	const int M_LINES_OF_BRICKS = 3;
	const int M_BRICKS_PER_LINE = 8;
	const int M_BRICK_HEIGHT = 20;
	const int M_BRICK_SPACE = 6;

	bool m_gameOver = false;

	std::vector<IDrawable*> m_drawableObjects{};

	Ball* m_ball = nullptr;

	Player* m_player = nullptr;

	int m_playerScore = 0;
};

