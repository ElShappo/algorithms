#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class BubbleSort : public ISort<T> {
public:
    BubbleSort() {this->sortName_ = __func__;}

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
};

#endif // BUBBLE_SORT_HPP
