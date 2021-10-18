#include <iostream>

#include <iostream>
#include <math.h>
#include <vector>

#include "MergeSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"

#define iter vector<int>::iterator
#define vi vector<int>

#include "DynamicArray.hpp"
#include "LinkedList.hpp"

using namespace std;

template <typename T>
void print(vector<T> vec)
{
    for (auto it : vec)
        cout << it << endl;
    cout << endl << endl;
}

template <typename T>
void print(DynamicArray<T> arr)
{
    for (int i=0; i<arr.GetLen(); ++i)
        cout << arr[i] << endl;
    cout << endl << endl;
}

template <typename T>
void print(LinkedList<T> li)
{
    for (int i=0; i<li.GetLen(); ++i)
        cout << li[i] << endl;
    cout << endl << endl;
}


int main()
{
    if ((float(1)+1.0)/2 == 1)
        cout << "yes " << endl;

    UdGenerator<int> gen;

    vector<int> sample_10;

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()

    for (int i=0; i<10; ++i)
    {
        sample_10.push_back(gen(-100000, 100000, generator));
        cout << sample_10[i] << endl;
    }


    vi sorted;

    //vi vec{1,2,3,4,5,6,7};
    //vi vec{5,6,7,0,1};
    //vi vec{5,6,7,0,1};
    vi vec{0,789, 11, 85, 23, 0,0,0,7689, 57,56859,0, -789};
    //vi vec{5,4,3,2,1};
    //vi vec{1,0};
    //vi vec{0};
    //vi vec{};
    //vi vec{-7985, 5329, 67, 0, 1, 896, 62822, 777, 3341, 555, 279, 89, 12,2,2,0,0,0,0,0,0,678, 11, 5, 8, 8,8,83,3,1,1, 2980210, 2576, 229, 78, 0, 5,5,55,8, -976, 7};
    //vi vec{-7985, 5329, 67, 0, 1, 896, 62822, 777, 3341, 555, 279, 89, 12,2,2,0,0,0,0,0,0,678, 11, 5, 8, 8,8,83,3,1,1, 2980210, 2576, 229, 78, 0, 5,5,55,8};
    //vi vec{1,1};
    //vi vec{2,1,1,1, 1,2,1,1,1,0,0};
    //vi vec{1, 1, 3, 4};
    //vi vec{2, 1, 3, 2, 3};

    /*
    int len = vec.size();
    int half = floor(len/2);

    vi left(vec.begin(), vec.begin() + half);
    vi right(vec.begin() + half, vec.end() );
    */

    //print(left);
    //print(right);

    print(vec);

    list<int> LIST(vec.begin(), vec.end());
    DynamicArray<int> arr(vec);
    LinkedList<int> li(vec);

    list<int> sortedLIST;
    DynamicArray<int> sortedArr;
    LinkedList<int> sortedLi;

    cout << "BUBBLE SORT SECTION" << endl;
    BubbleSort<int> bSort;

    sorted = bSort(vec);
    sortedLIST = bSort(LIST);
    sortedArr = bSort(arr);
    sortedLi = bSort(li);

    cout << "Result: " << endl;
    print(sorted);

    //cout << "Result: " << endl;
    //print(sortedLIST);

    //cout << "Result: " << endl;
    //print(sortedArr);

    //cout << "Result: " << endl;
    //print(sortedLi);

    cout << "Insertion sort section" << endl;
    InsertionSort<int> iSort;

    sorted = iSort(vec);
    sortedLIST = iSort(LIST);
    sortedArr = iSort(arr);
    sortedLi = iSort(li);

    cout << "Result: " << endl;
    print(sorted);

    cout << "Selection sort section" << endl;
    SelectionSort<int> sSort;

    sorted = sSort(vec);
    sortedLIST = sSort(LIST);
    sortedArr = sSort(arr);
    sortedLi = sSort(li);

    cout << "Result: " << endl;
    print(sorted);

    cout << "Merge sort section" << endl;
    MergeSort<int> mSort;

    sorted = mSort(vec);
    sortedLIST = mSort(LIST);
    sortedArr = mSort(arr);
    sortedLi = mSort(li);

    cout << "Result: " << endl;
    print(sorted);

    cout << "Quick sort section" << endl << endl;
    QuickSort<int> qSort;

    sorted = qSort(vec, 0, vec.size()-1);
    sortedLIST = qSort(LIST, 0, LIST.size()-1);
    sortedArr = qSort(arr, 0, arr.GetLen()-1);
    sortedLi = qSort(li, 0, li.GetLen()-1);

    cout << "Result: " << endl;
    print(sorted);

    return 0;
}
