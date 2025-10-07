/*****************************************************************************
* Project: Breakout
* File : MinMaxValue.h
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
* 03.10.25 JM Created
* 03.10.25 JM Added GetRandomValue method
******************************************************************************/

#pragma once
#include "RandomNumberGenerator.h"
template <typename T> //Need to specify the classes can put in
struct MinMaxValue
{
	T MinValue = {};
	T MaxValue = {};

	MinMaxValue(T min, T max) : MinValue(min), MaxValue(max) {};

	T GetRandomValue() const
	{
		RandomNumberGenerator<T> randomGenerator{};
		return randomGenerator.GenerateRandomNumber(MinValue, MaxValue);
	}
};