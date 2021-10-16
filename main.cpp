#include <iostream>
#include <math.h>
#include <vector>

#include "MergeSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "IntNumberGenerator.hpp"

using namespace std;

#define iter vector<int>::iterator
#define vi vector<int>

void print(vector<int> vec)
{
    for (auto it : vec)
        cout << it << endl;
    cout << endl;
}


int main()
{
    vi sorted;

    //vi vec{1,2,3,4,5,6,7};
    //vi vec{5,6,7,0,1};
    //vi vec{5,6,7,0,1};
    //vi vec{789, 11, 85, 23, 0};
    vi vec{5,4,3,2,1};
    //vi vec{1,0};

    int len = vec.size();
    int half = floor(len/2);

    vi left(vec.begin(), vec.begin() + half);
    vi right(vec.begin() + half, vec.end() );

    //print(left);
    //print(right);

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


    return 0;
}
