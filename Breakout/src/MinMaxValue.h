/*****************************************************************************
* Project: Breakout
* File : MinMaxValue.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* The MinMaxValue struct is a generic template that holds a minimum and maximum value of any specified type T.
* It provides a constructor for easy initialization and a method GetRandomValue() to generate a random value within the defined range.
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