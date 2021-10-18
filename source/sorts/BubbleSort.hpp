#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class BubbleSort : public ISort<T> {

private:

    vector<T> sort(vector<T> & vec) override
    {
        bool sorted = true;

        int len = vec.size();

        for (int i=0; i<len-1; ++i)
        {
            for (int j=0; j<len-1-i; ++j)
            {
                if (vec[j] > vec[j+1])
                {
                    swap(vec[j], vec[j+1]);
                    sorted = false;
                }
            }
            if (sorted)
                break;
        }
        return vec;
    }

public:

    BubbleSort(vector<T> vec)
    {
        *BubbleSort::res_ = sort(vec);
    }

    BubbleSort(list<T> vec)
    {
        this->res_ = sort(vector<T>(begin(vec), end(vec)));
    }

    BubbleSort(DynamicArray<T> vec)
    {
        this->res_ = sort(get<vector<T>>(vec.to_vector() ) );
    }

    BubbleSort(LinkedList<T> vec)
    {
        this->res_ = sort(get<list<T>>(vec.to_vector() ) );
    }
};

#endif // BUBBLE_SORT_HPP
