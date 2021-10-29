#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "ISort.hpp"
#include "UdGenerator.hpp"
#include "WeakGenerator.hpp"
#include <unistd.h>

using namespace std;

template <typename T>
class QuickSort : public ISort<T, int, int> {
public:
    QuickSort() {this->sortName_ = __func__;}

private:

    int partition (vector<T> & vec, int low, int high)
    {
        int pivot = vec[high]; // pivot
        int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (vec[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[high]);
        return (i + 1);
    }

    /* The main function that implements QuickSort
    vec[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index */
    void quickSort(vector<T> & vec, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, vec[p] is now
            at right place */
            int pi = partition(vec, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(vec, low, pi - 1);
            quickSort(vec, pi + 1, high);
        }
    }

    vector<T> & sort(vector<T> & vec, int lower_bound, int upper_bound) override
    {
        quickSort(vec, 0, vec.size()-1);
        return vec;
    }
};

#endif // QUICK_SORT_HPP
