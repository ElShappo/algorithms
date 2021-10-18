#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "ISort.hpp"
#include "UdGenerator.hpp"
#include "WeakGenerator.hpp"
#include <unistd.h>

using namespace std;

template <typename T>
class QuickSort : public ISort<T, int, int> {

private:

    float pivot(vector<T> vec, int lower_bound, int upper_bound) // get the index of the random pivot with the range of the size of the vector
    {
        return (float(vec[lower_bound])+vec[upper_bound])/2;
    }

    int partition(vector<T> & vec, int lower_bound, int upper_bound)
    // sorts the vector so it now represents two halves left of which has elements < pivot and the other >= pivot
    // then returning the index of the pivot in the 'sorted' vector
    {
        int i = lower_bound;
        int j = upper_bound;

        // cout << vec[i] << ", " << vec[j] << endl;

        float pivot = this->pivot(vec, lower_bound, upper_bound);
        bool enter = false;

        for (i=lower_bound; i<upper_bound+1; ++i)
        {
            // cout << "vec[" << i << "] = " << vec[i] << endl;
            if (vec[i] >= pivot)
            {
                while (j > i && vec[j] >= pivot)
                {
                    // cout << "vec[" << j << "] = " << vec[j] << endl;
                    if (j == i+1)
                        enter = true;
                    --j;
                }

                if (vec[j] < pivot)
                {
                    swap(vec[j], vec[i]);
                    --j;
                }

                if (i == j)
                    break;

            }
            if (i >= j)
                break;
        }

        if (i == lower_bound && enter)
            ++i;

        cout << "Index of the border in the 'sorted' vector: " << i << endl;

        return i;

    }

    vector<T> sort(vector<T> & vec, int lower_bound, int upper_bound) override
    {
        // cout << "sort function entered " << endl;

        if (upper_bound > lower_bound && vec.size() > 1)
        {

            int border = partition(vec, lower_bound, upper_bound);
            cout << "Border: " << border << endl;
            cout << "Lower bound: " << lower_bound << endl;
            cout << "Upper bound: " << upper_bound << endl;


            cout << "Left part of vector: " << endl;
            this->print(vector<T>(vec.begin() + lower_bound, vec.begin() + border) ); // border is the first index which goes to second vector

            cout << "Right part of vector: " << endl;
            this->print(vector<T>(vec.begin() + border, vec.begin() + upper_bound + 1) );

            sort(vec, 0, border-1);
            sort(vec, border, upper_bound);

        }
        return vec;
    }

public:

    quicksort(vector<T> vec)
    {
        *QuickSort::res_ = sort(vec, 0, vec.size()-1);
    }

    quicksort(list<T> vec)
    {
        this->res_ = sort(vector<T>(begin(vec), end(vec)), 0, vec.size()-1);
    }

    quicksort(DynamicArray<T> vec)
    {
        this->res_ = sort(get<vector<T>>(vec.to_vector() ), 0, vec.size()-1 );
    }

    quicksort(LinkedList<T> vec)
    {
        this->res_ = sort(get<list<T>>(vec.to_vector() ), 0, vec.size()-1 );
    }
};

#endif // QUICK_SORT_HPP
