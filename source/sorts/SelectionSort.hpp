#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class SelectionSort : public ISort<T> {

private:

    class IndexedElement {

        private:

            T value_;
            int index_;

        public:

            IndexedElement(T value, int index)
            {
                value_ = value;
                index_ = index;
            }

            T getValue() {return value_;}
            int getIndex() {return index_;}
    };

    IndexedElement min(vector<T> vec)
    // returns the pack containing the value and it's index
    {
        //if (vec.empty())
            //throw ISortException("can't find min in the empty vector");

        T smallest = vec[0];
        int index = 0;

        for (unsigned int i=0; i<vec.size(); ++i)
        {
            if (smallest > vec[i])
            {
                smallest = vec[i];
                index = i;
            }
        }
        return SelectionSort::IndexedElement(smallest, index);
    }

    vector<T> sort(vector<T> & vec) override
    {
        if (vec.empty()) // no need to sort anything in this case
            return vec;

        T smallest;
        int index;

        for (unsigned int i=0; i<vec.size(); ++i)
        {
            //this->print(vector<T>(vec.begin()+i, vec.end() ));
            IndexedElement pack(min(vector<T>(vec.begin()+i, vec.end() ) ) );

            smallest = pack.getValue();
            index = pack.getIndex();

            //cout << "Found min: " << smallest << endl;
            //cout << "Found it's index: " << index << endl << endl;

            if (vec[index+i] != vec[i]) // we have to write [index+i] because the index containing inside of the pack is for the PART of the main vector
                swap(vec[index+i], vec[i]);
        }
        return vec;
    }

public:

    SelectionSort(vector<T> vec)
    {
        *SelectionSort::res_ = sort(vec);
    }

    SelectionSort(list<T> vec)
    {
        this->res_ = sort(vector<T>(begin(vec), end(vec)));
    }

    SelectionSort(DynamicArray<T> vec)
    {
        this->res_ = sort(get<vector<T>>(vec.to_vector() ) );
    }

    SelectionSort(LinkedList<T> vec)
    {
        this->res_ = sort(get<list<T>>(vec.to_vector() ) );
    }
};

#endif // SELECTION_SORT_HPP
