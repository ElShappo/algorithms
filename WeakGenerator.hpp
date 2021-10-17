#ifndef WEAK_GENERATOR_HPP
#define WEAK_GENERATOR_HPP

#include "RandomGenerator.hpp"
#include <type_traits>

template <typename T>
class WeakGenerator : public RandomGenerator<T> {
public:
    T generate(T lower_bound, T upper_bound) override
    {
        if (is_integral<T>::value)
        {
            T delta = upper_bound - lower_bound;
            return rand() % delta;
        }
    }
}

#endif // WEAK_GENERATOR_HPP
