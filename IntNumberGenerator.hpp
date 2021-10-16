#ifndef INT_NUMBER_GENERATOR_HPP
#define INT_NUMBER_GENERATOR_HPP

#include "NumberGenerator.hpp"
#include <random>

using namespace std;

template <template<class> class T = ::int>
class IntNumberGenerator : public NumberGenerator<T> {
public:
    int generate(int min, int max) override
    {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator
        uniform_int_distribution<> distr(min, max); // define the range
        return distr(gen); // generate number
   }
};

#endif // INT_NUMBER_GENERATOR_HPP
