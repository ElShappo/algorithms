#ifndef ISORT_HPP
#define ISORT_HPP

#include <iostream>
#include <vector>
#include <list>
#include <variant>

#include "DynamicArray.hpp"
#include "LinkedList.hpp"

#define myVariant variant<vector<T>, list<T>, DynamicArray<T>, LinkedList<T>>

using namespace std;

template <typename T, typename ... Ts>
class ISort {

protected:

    myVariant* res_ = new myVariant();

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
    virtual vector<T> sort(vector<T> & var,  Ts ...) = 0;
    virtual myVariant & get() {return *res_;}


};

#endif // ISORT_HPP

