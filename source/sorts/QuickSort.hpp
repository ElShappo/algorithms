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
        int pivot = vec[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (vec[j] < pivot)
            {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[high]);
        return (i + 1);
    }
    void quickSort(vector<T> & vec, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(vec, low, high);

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
