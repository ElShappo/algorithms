#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include "ISort.hpp"

using namespace std;

class CountingSort : public ISort<int> {
public:
    CountingSort() {this->sortName_ = __func__;}

private:

    vector<int> & sort(vector<int> & vec) override
    {
        vector<int> positive; // including zero
        vector<int> negative;
        vector<int>* res = new vector<int>;

        int low = *min_element(vec.begin(), vec.end());
        int high = *max_element(vec.begin(), vec.end());

        for (int i=0; i<=high; ++i)
            positive.push_back(0);

        if (low < 0)
        {
            for (int i=0; i<=abs(low); ++i)
                negative.push_back(0);
        }
        for (auto it : vec)
        {
            if (it < 0)
                ++negative[abs(it)];
            else
                ++positive[it];
        }
        for (int i=negative.size()-1; i>0; --i)
        {
            for (int j=0; j<negative[i]; ++j)
                res->push_back(-i);
        }
        for (int i=0; i<positive.size(); ++i)
        {
            for (int j=0; j<positive[i]; ++j)
                res->push_back(i);
        }
        return *res;
    }
};

#endif // COUNTING_SORT_HPP


