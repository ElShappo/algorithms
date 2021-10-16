#ifndef NUMBER_GENERATOR_HPP
#define NUMBER_GENERATOR_HPP

#include "Generator.hpp"

template <template<typename=void> typename T>
class NumberGenerator : public Generator<T> {
public:
   virtual T<> generate(T<> var) = 0; // inside the <> we omit writing void (as it is set as the default)
};


#endif // NUMBER_GENERATOR_HPP
