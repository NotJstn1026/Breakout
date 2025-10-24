/*****************************************************************************
* Project: Breakout
* File : GAMESCENE.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* Is a enum class to define different game scenes.
*
* History:
* 07.10.25 JM Created
******************************************************************************/

#pragma once
#include <cstdint>
enum class GAMESCENE : std::uint8_t
{
	GS_STARTMENU = 0,
	GS_GAME = 1,
	GS_GAMEOVER = 2
};
