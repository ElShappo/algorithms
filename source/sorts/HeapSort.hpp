#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "ISort.hpp"

using namespace std;

template <typename T>
class HeapSort : public ISort<T> {
public:
    HeapSort() {this->sortName_ = __func__;}

private:

    vector<T> & sort(vector<T> & vec) override
    {
        for (int i=0; i<vec.size(); ++i)
        {
            //cout << "start of " << i << " iteration" << endl;

            heapify(vec, floor((vec.size()-i)/2)-1, vec.size()-i, true);
            swap(vec[0], vec[vec.size()-i-1]);

            //cout << "end of " << i << " iteration" << endl;
        }
        return vec;
    }

    void heapify(vector<T> & vec, int end, int size, bool iterations = false)
    {
        //int end = floor(vec.size()/2)-1; // the index of the rightmost node with at least one child

        for (end; end>=0; --end)
        {
            bool isRightChild = true;

            if (2*end+1 >= size)
                break;

            T& currentNode = vec[end];
            T& leftChild = vec[2*end+1];

            if (2*end+2 >= size)
                isRightChild = false;

            T MAX;

            if (isRightChild)
                MAX = max({currentNode, leftChild, vec[2*end+2]}); // vec[2*end+2] is the rightChild
            else
                MAX = max(currentNode, leftChild);

            if (currentNode != MAX)
            {
                //cout << "CurrentNode: " << "vec[" << end << "] = " << currentNode << endl;
                //cout << "LeftChild: " << "vec[" << 2*end+1 << "] = " << leftChild << endl;

                //if (isRightChild)
                    //cout << "RightChild: " << "vec[" << 2*end+2 << "] = " << vec[2*end+2] << endl;
                //else
                //cout << "LeftChild: " << "absents" << endl;


                if (leftChild == MAX)
                {
                    //cout << "Before heapifying, leftChild = " << leftChild << endl; print(vec);
                    swap(currentNode, leftChild);
                    heapify(vec, 2*end+1, size); // 2*end+1 - index of the left child
                    //cout << "After heapifying, leftChild = " << leftChild << endl; print(vec);
                }
                else
                {
                    //cout << "Before heapifying, rightChild = " << vec[2*end+2] << endl; print(vec);
                    swap(currentNode, vec[2*end+2]); // vec[2*end+2] is the rightChild
                    heapify(vec, 2*end+2, size); // 2*end+1 - index of the left child
                    //cout << "After heapifying, rightChild = " << vec[2*end+2] << endl; print(vec);
                }
            }
            if (!iterations)
                break;
        }
    }
};

#endif // INSERTION_SORT_HPP


