/*****************************************************************************
* Project: Breakout
* File : RandomNumberGenerator.h
* Date : 06.10.2025
* Author : Justin Martin (JM)
*
* The RandomNumberGenerator class is a template-based utility for generating random numbers of various types (e.g., int, float).
* It uses the C++ <random> library to provide uniformly distributed random values within a specified range.
*
* History:
* 09.09.25 JM Created
******************************************************************************/

#pragma once
#include <random>
#include <iostream>

template<typename T>
class RandomNumberGenerator
{
public:
    RandomNumberGenerator()
        : m_engine(m_seeder()) {
    }

    T GenerateRandomNumber(T min, T max)
    {
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<T> distrib(min, max);
            return distrib(m_engine);
        }
        else if constexpr (std::is_floating_point_v<T>) {
            std::uniform_real_distribution<T> distrib(min, max);
            return distrib(m_engine);
        }
        else {
            // Throws a exception when unsupported data type
            static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "Unsupported data type for random number generation.");
            return T{};
        }
    }

private:
    std::random_device m_seeder;
    std::mt19937 m_engine;
};