#pragma once
#include "RandomNumberGenerator.h"
template <typename T>
struct MinMaxValue
{
	T MinValue = {};
	T MaxValue = {};

	MinMaxValue(T min, T max) : MinValue(min), MaxValue(max) {};

	T GetRandomValue();
};

template<typename T>
inline T MinMaxValue<T>::GetRandomValue()
{
	RandomNumberGenerator<float> randomGenerator{};
	randomGenerator.GenerateRandomNumber(MinValue, MaxValue);
	return T();
}
