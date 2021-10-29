#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <chrono>

#include "MergeSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"

#include "DynamicArray.hpp"
#include "LinkedList.hpp"

#include "auxiliary.hpp"

#include "bprinter/table_printer.h"
#define _USE_MATH_DEFINES

#if defined(USE_BOOST_KARMA)
#include <boost/spirit/include/karma.hpp>
namespace karma = boost::spirit::karma;
#endif

using namespace std;
using namespace std::chrono;
using bprinter::TablePrinter;

class UserConsole
{
public:
    UserConsole()
    {
        UdGenerator<int> gen;

        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()

        int datatype = -1;
        int sort = -1;
        int mode = -1;
        string buffer;
        vector<int> converted;
        int amount = 1;


        DynamicArray<int> sortedArr;
        LinkedList<int> sortedLi;

        BubbleSort<int> bSort;
        InsertionSort<int> iSort;
        MergeSort<int> mSort;
        QuickSort<int> qSort;
        SelectionSort<int> sSort;

        while (true)
        {
            cout << "Choose the desired datatype: " << endl << endl;
            cout << "1. LinkedList" << endl;
            cout << "2. DynamicArray" << endl << endl;
            cout << "Enter: ";

            cin >> datatype;
            std::cin.ignore(32767, '\n');

            cout << endl;

            cout << "Choose the desired sort: " << endl << endl;
            cout << "1. BubbleSort" << endl;
            cout << "2. InsertionSort" << endl;
            cout << "3. MergeSort" << endl;
            cout << "4. QuickSort" << endl;
            cout << "5. SelectionSort" << endl << endl;
            cout << "Enter: ";

            cin >> sort;
            std::cin.ignore(32767, '\n');

            cout << endl;

            cout << "Choose how to enter data: " << endl << endl;
            cout << "1. Manually" << endl;
            cout << "2. Randomly" << endl << endl;
            cout << "Enter: ";

            cin >> mode;
            std::cin.ignore(32767, '\n');

            cout << endl;

            switch (mode)
            {
                case 1:

                    getline(cin, buffer);
                    converted = parse(buffer);
                    break;

                case 2:

                    cout << "Amount of numbers: ";
                    cin >> amount;
                    std::cin.ignore(32767, '\n');
                    cout << endl << endl;
                    cout << "Range [min max]: ";

                    getline(cin, buffer);
                    converted = parse(buffer);

                    int MIN, MAX;

                    MIN = min(converted[0], converted[1]);
                    MAX = max(converted[0], converted[1]);

                    converted.clear();

                    for (int i=0; i<amount; ++i)
                        converted.push_back(gen(MIN, MAX, generator));

                    break;

                default:
                    break;
            }

            DynamicArray<int> arr(converted);
            LinkedList<int> li(converted);

            auto start = high_resolution_clock::now();
            switch (datatype)
            {
                case 1:

                    switch (sort)
                    {
                        case 1:
                            sortedLi = bSort(li);
                            break;

                        case 2:
                            sortedLi = iSort(li);
                            break;

                        case 3:
                            sortedLi = mSort(li);
                            break;

                        case 4:
                            sortedLi = qSort(li, 0, li.GetLen()-1);
                            break;

                        case 5:
                            sortedLi = sSort(li);
                            break;

                        default:
                            break;
                    }

                case 2:

                    switch (sort)
                    {
                        case 1:
                            sortedArr = bSort(arr);
                            break;

                        case 2:
                            sortedArr = iSort(arr);
                            break;

                        case 3:
                            sortedArr = mSort(arr);
                            break;

                        case 4:
                            sortedArr = qSort(arr, 0, arr.GetLen()-1);
                            break;

                        case 5:
                            sortedArr = sSort(arr);
                            break;

                        default:
                            break;
                    }

                default:
                    break;

            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;

            if (amount <= 5000)
            {
                TablePrinter tp(&std::cout);
                tp.AddColumn("Index", 5);
                tp.AddColumn("Unsorted", 10);
                tp.AddColumn("Sorted", 10);

                if (datatype == 1)
                {
                    tp.PrintHeader();

                    for (unsigned int i=0; i<converted.size(); ++i)
                        tp << i << converted[i] << sortedLi[i];

                    tp.PrintFooter();
                }
                else if (datatype == 2)
                {
                    tp.PrintHeader();

                    for (unsigned int i=0; i<converted.size(); ++i)
                        tp << i << converted[i] << sortedArr[i];

                    tp.PrintFooter();
                }
            }
        }
    }
};

int main()
{
    UserConsole console;
    return 0;
}
