#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class InsertionSort : public ISort<T> {

private:

    vector<T> sort(vector<T> vec) override
    {
        T key;

        for (int j=1; j<vec.size(); ++j)
        {
            key = vec[j];

            int i = j;

            while (key < vec[i-1] && i>0)
            {
                swap(vec[i], vec[i-1]);
                --i;
            }

        }

        return vec;
    }

public:

    InsertionSort(vector<T> vec) {this->res_ = sort(vec);}
};

#endif // INSERTION_SORT_HPP

