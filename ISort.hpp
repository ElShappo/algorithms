#ifndef ISORT_HPP
#define ISORT_HPP

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class ISort {

protected:

    vector<T> res_;

    enum class Order
    {
        ASC,
        DESC
    };

    virtual void print(vector<T> vec)
    {
        for (auto it : vec)
            cout << it << endl;
        cout << endl;
    }

public:
    virtual vector<T> sort(vector<T> var) = 0;
    virtual vector<T> get() {return this->res_;}

};

#endif // ISORT_HPP

