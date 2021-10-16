#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class MergeSort : public ISort<T> {

private:

    class Partition {

        private:

            vector<T> left_;
            vector<T> right_;

        public:

            Partition(vector<T> vec)
            {
                int len = vec.size();
                int half = floor(len/2);

                left_ = vector<T>(vec.begin(), vec.begin() + half);
                right_ = vector<T>(vec.begin() + half, vec.end() );
            }

            vector<T> left() {return left_;}
            vector<T> right() {return right_;}
    };





    vector<T> merge(vector<T> vec1, vector<T> vec2)
    {
        cout << "MERGE CALLED" << endl;
        cout << "Left array inside merge: " << endl;
        this->print(vec1);

        cout << "Right array inside merge: " << endl;
        this->print(vec2);

        unsigned int i = 0;
        unsigned int j = 0;

        T iptr = vec1[0];
        T jptr = vec2[0];

        vector<T> res;

        while (true)
        {
            T MIN = min(iptr, jptr);
            cout << "MIN = " << MIN << endl;
            res.push_back(MIN);
            cout << "State of res: " << endl;
            this->print(res);

            if (iptr < jptr)
            {
                if (i == vec1.size()-1)
                // that means that there are only (bigger) numbers in the second vector which are left
                {
                    res.insert(res.end(), vec2.begin()+j, vec2.end());
                    return res;

                }
                ++i;
                iptr = vec1[i];
            }
            else
            {
                if (j == vec2.size()-1)
                // that means that there are only (bigger) numbers in the first vector which are left
                {
                    res.insert(res.end(), vec1.begin()+i, vec1.end());
                    return res;

                }
                ++j;
                jptr = vec2[j];
            }
        }

    }


    vector<T> sort(vector<T> vec) override
    {
        cout << "SORT CALLED" << endl;
        Partition parts(vec);

        vector<T> left = parts.left();
        vector<T> right = parts.right();

        if (vec.size() > 1)
        {
            left = sort(left);
            right = sort(right);

            cout << "Sorted left part: " << endl;
            this->print(left);
            cout << "Sorted right part: " << endl;
            this->print(right);

            return merge(left, right);
        }
        else
            return vec;

    }


public:

    MergeSort(vector<T> vec) {this->res_ = sort(vec);}
};

#endif // MERGE_SORT_HPP
