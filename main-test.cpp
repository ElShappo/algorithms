#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <iostream>
#include <math.h>
#include <vector>

#include "catch.hpp"
#include "BubbleSort.hpp"
#include "UdGenerator.hpp"

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

/*
int main()
{
    vi sorted;

    //vi vec{1,2,3,4,5,6,7};
    //vi vec{5,6,7,0,1};
    //vi vec{5,6,7,0,1};
    vi vec{789, 11, 85, 23, 0};
    //vi vec{5,4,3,2,1};
    //vi vec{1,0};
    //vi vec{0};
    //vi vec{};

    int len = vec.size();
    int half = floor(len/2);

    vi left(vec.begin(), vec.begin() + half);
    vi right(vec.begin() + half, vec.end() );

    //print(left);
    //print(right);

    print(vec);

    cout << "Initial array: " << endl;
    print(vec);

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
*/



