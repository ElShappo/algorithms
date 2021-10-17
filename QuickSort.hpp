#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "ISort.hpp"
#include "IntNumberGenerator.hpp"

using namespace std;

template <typename T>
class QuickSort : public ISort<T> {

private:

    T pivot(vector<T> vec) // get the index of the random pivot with the range of the size of the vector
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, vector.size()-1); // define the range

        for(int n=0; n<40; ++n)
            std::cout << distr(gen) << ' '; // generate numbers

        return pivot;
    }

    int partition(vector<T>* vec, T pivot)
    // to change the order of the elements in the vec so there are small elements on the left and large on the right
    {
        int i = 0;
        int j = vec.size()-1;

        T iptr;
        T jptr;

        int border; // all indexes >= border are the right part of vector (large elements)

        for (int i=0; i<vec->size(); ++i)
        {
            if (*vec[i] >= pivot)
            {
                while (j > i && *vec[j] >= pivot)
                    --j;

                if (*vec[j] < pivot)
                {
                    swap(*vec[j], *vec[i])
                    --j;
                }

                if (i == j)
                    break;
            }
        }
        return j;

    }

    vector<T> sort(vector<T> & vec) override
    {
        int border = partition(&vec, pivot(vec));

        sort(vector<T>(vec.begin(), vec.begin() + border) );
        sort(vector<T>(vec.begin() + border, vec.end() ) );

        return vec;
    }

public:

    QuickSort(vector<T> vec) {this->res_ = sort(vec);}
};

#endif // QUICK_SORT_HPP
