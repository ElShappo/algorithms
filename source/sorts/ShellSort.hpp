#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include "ISort.hpp"
#include "auxiliary.hpp"

using namespace std;

template <typename T>
class ShellSort : public ISort<T> {
public:
    ShellSort() {this->sortName_ = __func__;}

private:
    vector<T> & sort(vector<T> & vec) override
    {
        for (int s = vec.size()/2; s>0; s /= 2)
        {
            for (int j=s; j<vec.size(); ++j)
            {
                for (int k = j-s; k >= 0 && vec[k] > vec[k+s]; k -= s)
                    swap(vec[k], vec[k+s]);
            }
        }
        return vec;
    }
};

#endif // SHELL_SORT_HPP

