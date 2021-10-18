#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class BubbleSort : public ISort<T> {

private:

    vector<T> & sort(vector<T> & vec) override
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

    vector<T> & operator()(vector<T> & vec)
    {
        return sort(vec);
    }

    list<T> & operator()(list<T> & li)
    {
        return LinkedList<T>::to_list(sort(LinkedList<T>::to_vector(li) ) );
    }

    DynamicArray<T> & operator()(DynamicArray<T> & arr)
    {
        return DynamicArray<T>::to_array(sort(arr.to_vector() ) );
    }

    LinkedList<T> & operator()(LinkedList<T> & li)
    {
        return LinkedList<T>::to_linked_list(sort(li.to_vector() ) );
    }
};

#endif // BUBBLE_SORT_HPP
