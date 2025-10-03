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