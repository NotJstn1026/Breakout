#pragma once
#include <iostream>
#include <memory>
#include "Player.h"
#include "Brick.h"
#include "Ball.h"
#include "IDrawable.h"
#include <vector>

class GameManager
{
public:
	void StartGame();

private:
	void InitGame();
	void SetBricks(Vector2& brickSize);
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

	std::vector<std::shared_ptr<IDrawable>> m_drawableObjects {};

	std::vector<Brick> m_bricks {};

	std::shared_ptr<Player> m_player = nullptr;

	Ball* m_ball = nullptr;

	int m_playerScore = 0;
};

