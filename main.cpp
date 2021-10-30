#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <chrono>
#include <regex>
#include <optional>

#include "MergeSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include "CountingSort.hpp"
#include "ShellSort.hpp"
#include "HeapSort.hpp"

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

vector<int> restrictedVectorCin(optional<int> repetitions = optional<int>(), bool requirePositive = false, vector<int> permittedValues = vector<int>())
{
    vector<int> res;
    string buffer;
    char ch;

    while (true)
    {
        while ((ch = getchar() ) != '\n')
            buffer.push_back(ch);

        cin.clear();

        regex reg("^(-*[0-9])+( -*[0-9]+)*$");

        if (!regex_match(buffer, reg) )
        {
            cout << "Invalid input. Please, retype" << endl << endl;
            buffer.erase(buffer.begin(), buffer.end());
            res.erase(res.begin(), res.end());
            continue;
        }

        for (int i=0; i<buffer.size(); ++i)
        {
            string buff;
            while (buffer[i] != ' ')
            {
                buff.push_back(buffer[i]);
                ++i;
            }
            res.push_back(stoi(buff));
        }
        if (repetitions.has_value())
        {
            if (res.size() != repetitions.value())
            {
                cout << "Invalid input. Please, retype" << endl << endl;
                buffer.erase(buffer.begin(), buffer.end());
                res.erase(res.begin(), res.end());
                continue;
            }
        }

        bool isNested = false;

        for (auto it1 : res)
        {
            bool match = false;

            if (permittedValues.empty())
                match = true;

            for (auto it2 : permittedValues)
            {
                if (it1 == it2)
                    match = true;
            }
            if (!match || (it1 < 0 && requirePositive) )
            {
                isNested = true;
                cout << "Invalid input. Please, retype" << endl << endl;
                buffer.erase(buffer.begin(), buffer.end());
                res.erase(res.begin(), res.end());
                break;
            }
        }

        if (isNested)
            continue;

        break;
    }
    return res;
}

class Console
{
public:
    enum Type
    {
        linkedList=1,
        dynamicArray=2,
    };

    enum Input
    {
        Manual=1,
        Random=2,

    };

    Console()
    {
        UdGenerator<int> gen;

        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()

        int type; // DynamicArr or LinkedList
        int sort; // One of 5 sorts
        int inputType; // Manual or Random
        vector<int> toSort;

        int amount;
        vector<int> minMax;

        DynamicArray<int> sortedArr;
        LinkedList<int> sortedLi;

        BubbleSort<int> bSort;
        InsertionSort<int> iSort;
        MergeSort<int> mSort;
        QuickSort<int> qSort;
        SelectionSort<int> sSort;
        CountingSort cSort;
        ShellSort<int> shSort;
        HeapSort<int> hSort;

        while (true)
        {
            toSort.erase(toSort.begin(), toSort.end());
            minMax.erase(minMax.begin(), minMax.end());

            cout << "Choose the desired datatype: " << endl << endl;
            cout << "1. LinkedList" << endl;
            cout << "2. DynamicArray" << endl << endl;
            cout << "Enter: ";

            type = restrictedVectorCin(1, true, {1,2})[0];
            cout << endl;

            cout << "Choose the desired sort: " << endl << endl;
            cout << "1. BubbleSort" << endl;
            cout << "2. InsertionSort" << endl;
            cout << "3. MergeSort" << endl;
            cout << "4. QuickSort" << endl;
            cout << "5. SelectionSort" << endl;
            cout << "6. CountingSort" << endl;
            cout << "7. ShellSort" << endl;
            cout << "8. HeapSort" << endl << endl;
            cout << "Enter: ";

            sort = restrictedVectorCin(1, true, {1,2,3,4,5,6,7,8})[0];
            cout << endl;

            cout << "Choose how to enter data: " << endl << endl;
            cout << "1. Manually" << endl;
            cout << "2. Randomly" << endl << endl;
            cout << "Enter: ";

            inputType = restrictedVectorCin(1, true, {1,2})[0];
            cout << endl;

            switch (inputType)
            {
                case Input::Manual:

                    cout << "Enter the numbers through whitespaces: " << endl;
                    toSort = restrictedVectorCin();
                    break;

                case Input::Random:

                    cout << "Amount of numbers: ";
                    amount = restrictedVectorCin(1, true)[0];
                    cout << endl;
                    cout << "Range (from min to max through whitespace): ";

                    minMax = restrictedVectorCin(2);

                    int MIN, MAX;

                    MIN = min(minMax[0], minMax[1]);
                    MAX = max(minMax[0], minMax[1]);

                    for (int i=0; i<amount; ++i)
                        toSort.push_back(gen(MIN, MAX, generator));

                    break;
            }

            DynamicArray<int> arr(toSort);
            LinkedList<int> li(toSort);

            if (amount <= 1000)
                print(arr);

            auto start = high_resolution_clock::now();
            switch (type)
            {
                case Type::linkedList:

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

                        case 6:
                            sortedLi = cSort(li);
                            break;

                        case 7:
                            sortedLi = shSort(li);
                            break;

                        case 8:
                            sortedLi = hSort(li);
                            break;
                    }

                case Type::dynamicArray:

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

                        case 6:
                            sortedArr = cSort(arr);
                            break;

                        case 7:
                            sortedArr = shSort(arr);
                            break;

                        case 8:
                            sortedArr = hSort(arr);
                            break;
                    }
            }

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;

            if (amount <= 1000)
            {
                TablePrinter tp(&std::cout);
                tp.AddColumn("Index", 5);
                tp.AddColumn("Unsorted", 10);
                tp.AddColumn("Sorted", 10);

                if (type == Type::linkedList)
                {
                    tp.PrintHeader();

                    for (unsigned int i=0; i<toSort.size(); ++i)
                        tp << i << toSort[i] << sortedLi[i];

                    tp.PrintFooter();
                }
                else if (type == Type::dynamicArray)
                {
                    tp.PrintHeader();

                    for (unsigned int i=0; i<toSort.size(); ++i)
                        tp << i << toSort[i] << sortedArr[i];

                    tp.PrintFooter();
                }
            }
        }
    }
};

int main()
{
    Console console;
    return 0;
}
