#ifndef GENERATOR_HPP
#define GENERATOR_HPP

template <template<class=void> class C, class ... Ts>
class Generator {

public:
    virtual C<Ts...> generate(C<Ts...> var) = 0;

};

#endif // GENERATOR_HPP
