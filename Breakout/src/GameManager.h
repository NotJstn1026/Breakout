#pragma once
#include <iostream>
#include "Player.h"
#include "Brick.h"
#include "Ball.h"
#include "GameObject.h"
#include <vector>

class GameManager
{
public:
	void StartGame();
	void DestroyBrick(Brick* a_brickPtr);
	GameManager();
	~GameManager();
private:
	void InitGame();
	void SetBricks(Vector2& a_brickSize);
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

	std::vector<GameObject*> m_gameObjects{};

	std::vector <Ball*> m_balls = {};

	Player* m_player = nullptr;

	int m_playerScore = 0;
};

