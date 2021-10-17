#ifndef UD_GENERATOR_HPP
#define UD_GENERATOR_HPP

#include "RandomGenerator.hpp"
#include <type_traits>
#include <random>

template <typename T>
class UdGenerator : public RandomGenerator<T> {
public:
    T generate(T lower_bound, T upper_bound) override
    {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

        if (std::is_integral<T>::value)
        {
            std::uniform_int_distribution<> distrib(lower_bound, upper_bound);
            return distrib(gen);
        }
        else if (std::is_floating_point<T>::value)
        {
            std::uniform_real_distribution<> distrib(lower_bound, upper_bound);
            return distrib(gen);
        }
        //else
            // throw RandomGeneratorException
    }
};

#endif // UD_GENERATOR_HPP

