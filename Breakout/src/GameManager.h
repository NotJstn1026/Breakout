/*****************************************************************************
* Project: Breakout
* File : GameManager.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
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

