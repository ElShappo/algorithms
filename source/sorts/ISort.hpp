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
    virtual vector<T> & sort(vector<T> & var,  Ts ...) = 0;

    vector<T> & operator()(vector<T> & vec, Ts ... ts)
    {
        return sort(vec, ts ...);
    }

    list<T> & operator()(list<T> & li, Ts ... ts)
    {
        return LinkedList<T>::to_list(sort(LinkedList<T>::to_vector(li), ts ... ) );
    }

    DynamicArray<T> & operator()(DynamicArray<T> & arr, Ts ... ts)
    {
        return DynamicArray<T>::to_array(sort(arr.to_vector(), ts ...) );
    }

    LinkedList<T> & operator()(LinkedList<T> & li, Ts ... ts)
    {
        return LinkedList<T>::to_linked_list(sort(li.to_vector(), ts ...) );
    }


};

#endif // ISORT_HPP

