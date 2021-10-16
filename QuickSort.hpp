#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class QuickSort : public ISort<T> {

private:

    int pivot(vector<T> vec) // get the index of the random pivot with the range of the size of the vector
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, vector.size()-1); // define the range

        for(int n=0; n<40; ++n)
            std::cout << distr(gen) << ' '; // generate numbers

    }

    vector<T> sort(vector<T> vec) override
    {
    }

public:

    QuickSort(vector<T> vec) {this->res_ = sort(vec);}
};

#endif // QUICK_SORT_HPP
