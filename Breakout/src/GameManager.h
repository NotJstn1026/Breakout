/*****************************************************************************
* Project: Breakout
* File : GameManager.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* The GameManager class is the main controller for a Breakout game, handling the entire game loop and state.
* It creates, manages, and updates all game objects like the player, balls, and bricks.
* The class uses a state machine to switch between the start menu, active gameplay, and game over scenes.
* It's also responsible for memory management, with dedicated methods to safely destroy objects and prevent memory leaks.
* Finally, it orchestrates all drawing and input handling, ensuring a smooth and responsive gameplay experience.
*
* History:
* 09.09.25 JM Created
* 09.09.25 JM Added Gamecycle methods
* 24.09.25 JM Added Draw methods with logic
* 25.09.25 JM Added DestroyBrick method to remove bricks
******************************************************************************/

#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Brick.h"
#include "Ball.h"
#include "GameObject.h"
#include "GAMESCENE.h"

class GameManager
{
public:
	void StartGameManager();
	void DestroyBrick(Brick* a_brickPtr);
	void AddBall();
	void DestroyBall(Ball* a_ballPtr);
	GameManager();
	~GameManager();

	inline int GetBrickCount() const { return m_brickCount; }

private:
	void InitGame();
	void SetBricks();
	void DrawGame();
	void Update();
	void EndGame();
	void RestartGame();

	const float M_WIDTH = 700;
	const float M_HEIGHT = 500;
	const float M_TARGET_FPS = 60;
	const char* M_GAME_NAME = "Breakout";
	const float M_ONE_AND_A_HALF = 1.5f;
	const float M_HALF = 0.5f;

	const int M_TEXT_SIZE = 20;

	const int M_STARTMENU_POS_X = 180;

	const int M_POINTS_POSITION_X = 10;
	const int M_POINTS_POSITION_Y = 10;
	const int M_GAME_OVER_POS_X = 280;
	const int M_GAME_OVER_POS_Y = 200;
	const int M_SCORE_LABEL_POS_X = M_GAME_OVER_POS_X + 130;
	const int M_SCORE_LABEL_POS_Y = 240;
	const int M_SCORE_VALUE_POS_Y = 240;
	const int M_EXIT_POS_X = 250;
	const int M_EXIT_POS_Y = 280;
	const int M_RESTART_POS_X = 250;
	const int M_RESTART_POS_Y = 320;

	//Bricks
	const int M_LINES_OF_BRICKS = 3;
	const int M_BRICKS_PER_LINE = 8;
	const int M_BRICK_HEIGHT = 20;
	const int M_BRICK_SPACE = 3;
	const int M_BRICK_POINTS = 100;
	const int M_START_HEIGTH_BRICKS = 60;

	const Color M_BRICK_COLOR[3] = {RED,GREEN,BLUE}; 

	GAMESCENE m_currentGameScene = GAMESCENE::GS_STARTMENU;

	bool m_gameOver = false;
	int m_playerScore = 0;
	int m_brickCount = {};


	std::vector<GameObject*> m_gameObjects{};
	std::vector<Ball*> m_balls = {};
	Player* m_player = nullptr;
};

