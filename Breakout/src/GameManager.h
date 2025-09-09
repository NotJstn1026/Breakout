#pragma once
#include <iostream>
#include "Player.h"
#include "Brick.h"
#include "Ball.h"

class GameManager
{
public:
	void StartGame();

	void DrawGame();

private:
	void EndGame();
	void InitGame();
	void SetBricks(Vector2& brickSize);
	void Update();
	
	const int M_WIDTH = 300;
	const int M_HEIGHT = 300;
	const int M_TARGET_FPS = 60;
	const char* M_GAME_NAME = "Breakout";

	//Bricks
	const int M_LINES_OF_BRICKS = 2;
	const int M_BRICKS_PER_LINE = 10;
	const int M_BRICK_HEIGHT = 40;
	const int M_BRICK_SPACE = M_BRICK_HEIGHT + 10;

	bool m_gameOver = false;

	Player* m_player = {};
	Brick** m_bricks = {};
	Ball* m_ball = {};

	int m_playerScore = 0;

};

