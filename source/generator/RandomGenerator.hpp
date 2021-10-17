#ifndef RANDOM_GENERATOR_HPP
#define RANDOM_GENERATOR_HPP

template <typename T>
class RandomGenerator
{
public:
   virtual T generate(T lower_bound, T upper_bound) = 0;
};

#endif // RANDOM_GENERATOR_HPP
