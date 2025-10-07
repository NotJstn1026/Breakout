/*****************************************************************************
* Project: Breakout
* File : RandomNumberGenerator.h
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