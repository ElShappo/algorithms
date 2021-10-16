#ifndef FLOAT_NUMBER_GENERATOR_HPP
#define FLOAT_NUMBER_GENERATOR_HPP

#include "NumberGenerator.hpp"

class IntNumberGenerator : public NumberGenerator<int> {
public:
    int generate(int min, int max) override
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(min, max); // define the range
        return distr(gen); // generate number
   }
};

#endif // FLOAT_NUMBER_GENERATOR_HPP
