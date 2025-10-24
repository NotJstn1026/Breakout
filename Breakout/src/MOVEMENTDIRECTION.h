/*****************************************************************************
* Project: Breakout
* File : MOVEMENTDIRECTION.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* Is a enum class to define different movement directions for the player.
*
* History:
* 09.09.25 JM Created
******************************************************************************/

#pragma once
#include <cstdint>
enum class MOVEMENTDIRECTION : std::uint8_t
{
	DM_LEFT = 0,
	DM_RIGHT = 1
};
