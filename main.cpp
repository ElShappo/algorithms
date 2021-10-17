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

using namespace std;

template <typename T>
void print(vector<T> vec)
{
    for (auto it : vec)
        cout << it << endl;
    cout << endl << endl;
}

template <typename T>
vector<T> bubbleSort(vector<T> vec)
{
    //print(vec);
    BubbleSort<T> sort(vec);
    vector<T> res = sort.get();
    //print(res);
    return res;
}

int main()
{
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
    //vi vec{789, 11, 85, 23, 0};
    //vi vec{5,4,3,2,1};
    //vi vec{1,0};
    //vi vec{0};
    //vi vec{};
    vi vec{-7985, 5329, 67, 0, 1, 896, 62822, 777, 3341, 555, 279, 89, 12};

    /*
    int len = vec.size();
    int half = floor(len/2);

    vi left(vec.begin(), vec.begin() + half);
    vi right(vec.begin() + half, vec.end() );
    */

    //print(left);
    //print(right);

    print(vec);

    cout << "Merge sort section" << endl;

    MergeSort mSort(vec);
    sorted = mSort.get();

    cout << "Result: " << endl;
    print(sorted);

    cout << "Bubble sort section" << endl;

    BubbleSort bSort(vec);
    sorted = bSort.get();

    cout << "Result: " << endl;
    print(sorted);



    cout << "Insertion sort section" << endl;

    InsertionSort iSort(vec);
    sorted = iSort.get();

    cout << "Result: " << endl;
    print(sorted);




    cout << "Selection sort section" << endl;

    SelectionSort sSort(vec);
    sorted = sSort.get();

    cout << "Result: " << endl;
    print(sorted);


    cout << "Quick sort section" << endl << endl;

    QuickSort qSort(vec);
    sorted = qSort.get();

    cout << "Result: " << endl;
    print(sorted);


    return 0;
}
