/*****************************************************************************
* Project: Breakout
* File : GAMESCENE.h
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
