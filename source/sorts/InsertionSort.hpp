#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class InsertionSort : public ISort<T> {

private:

    vector<T> sort(vector<T> & vec) override
    {
        T key;

        for (unsigned int j=1; j<vec.size(); ++j)
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

    InsertionSort(vector<T> vec)
    {
        *InsertionSort::res_ = sort(vec);
    }

    InsertionSort(list<T> vec)
    {
        this->res_ = sort(vector<T>(begin(vec), end(vec)));
    }

    InsertionSort(DynamicArray<T> vec)
    {
        this->res_ = sort(get<vector<T>>(vec.to_vector() ) );
    }

    InsertionSort(LinkedList<T> vec)
    {
        this->res_ = sort(get<list<T>>(vec.to_vector() ) );
    }
};

#endif // INSERTION_SORT_HPP

