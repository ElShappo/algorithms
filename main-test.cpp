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
#include "CountingSort.hpp"
#include "ShellSort.hpp"

#include "DynamicArray.hpp"
#include "LinkedList.hpp"

#include "auxiliary.hpp"

#include "bprinter/table_printer.h"
#define _USE_MATH_DEFINES

#if defined(USE_BOOST_KARMA)
#include <boost/spirit/include/karma.hpp>
namespace karma = boost::spirit::karma;
#endif

#include <sciplot/sciplot.hpp>
using namespace std;
using namespace std::chrono;
using bprinter::TablePrinter;
using namespace sciplot;

template<typename T, Sorts sorts>
class Test
{
public:
    auto operator() (int amount, T low, T high, EnablePrint isPrint = EnablePrint::enabled)
    {
        int buff1 = min(low, high);
        int buff2 = max(low, high);

        low = buff1; high = buff2;

        UdGenerator<int> gen;

        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()
        vector<T> random;

         for (int i=0; i<amount; ++i)
            random.push_back(gen(low, high, generator));

        // defining auxiliary

        BubbleSort<int> bSort;
        InsertionSort<int> iSort;
        MergeSort<int> mSort;
        QuickSort<int> qSort;
        SelectionSort<int> sSort;
        CountingSort cSort;
        ShellSort<int> shSort;

        DynamicArray<int> arr(random);
        LinkedList<int> li(random);

        DynamicArray<T> sortedArr;
        LinkedList<T> sortedLi;

        // end of defining

        TablePrinter tp(&std::cout);
        tp.AddColumn("Index", 5);
        tp.AddColumn("Unsorted", 10);
        tp.AddColumn("SortedArr", 10);
        tp.AddColumn("SortedLi", 10);

        auto start1 = high_resolution_clock::now();

        if (sorts == Sorts::BubbleSort)
            sortedArr = bSort(arr);
        else if (sorts == Sorts::InsertionSort)
            sortedArr = iSort(arr);
        else if (sorts == Sorts::MergeSort)
            sortedArr = mSort(arr);
        else if (sorts == Sorts::QuickSort)
            sortedArr = qSort(arr, 0, arr.GetLen()-1);
        else if (sorts == Sorts::SelectionSort)
            sortedArr = sSort(arr);
        else if (sorts == Sorts::CountingSort)
            sortedArr = cSort(arr);
        else if (sorts == Sorts::ShellSort)
            sortedArr = shSort(arr);

        auto stop1 = high_resolution_clock::now();
        auto start2 = high_resolution_clock::now();

        if (sorts == Sorts::BubbleSort)
            sortedLi = bSort(li);
        else if (sorts == Sorts::InsertionSort)
            sortedLi = iSort(li);
        else if (sorts == Sorts::MergeSort)
            sortedLi = mSort(li);
        else if (sorts == Sorts::QuickSort)
            sortedLi = qSort(li, 0, li.GetLen()-1);
        else if (sorts == Sorts::SelectionSort)
            sortedLi = sSort(li);
        else if (sorts == Sorts::CountingSort)
            sortedLi = cSort(li);
        else if (sorts == Sorts::ShellSort)
            sortedLi = shSort(li);

        auto stop2 = high_resolution_clock::now();

        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        if (isPrint == EnablePrint::enabled)
        {
            TablePrinter tp(&std::cout);
            tp.AddColumn("Index", 5);
            tp.AddColumn("Unsorted", 10);
            tp.AddColumn("SortedArr", 10);
            tp.AddColumn("SortedLi", 10);

            tp.PrintHeader();

            for (unsigned int i=0; i<random.size(); ++i)
                tp << i << random[i] << sortedArr[i] << sortedLi[i];

            tp.PrintFooter();
        }

        if (isPrint == EnablePrint::onlyDuration || isPrint == EnablePrint::enabled)
        {
            TablePrinter tp(&std::cout);
            tp.AddColumn("Time", 15);
            tp.AddColumn("DynamicArray", 15);
            tp.AddColumn("LinkedList", 15);

            tp.PrintHeader();
            tp << "Microseconds" << duration1.count() << duration2.count();
            tp.PrintFooter();
        }

        return make_pair(duration1.count(), duration2.count());
    }
};

template<int low = -1000000, int high = 1000000>
class PreparedConsole
// test for 10, 100, 1000, 10000, 20000 and 40000 elements respectively
{
private:
    vector<int> bArrDurations; // list of durations collected from BubbleSort for DynamicArray
    vector<int> bLiDurations; // list of durations collected from BubbleSort for LinkedList

    vector<int> iArrDurations; // list of durations collected from InsertionSort for DynamicArray
    vector<int> iLiDurations; // list of durations collected from InsertionSort for LinkedList

    vector<int> mArrDurations; // list of durations collected from MergeSort for DynamicArray
    vector<int> mLiDurations; // list of durations collected from MergeSort for LinkedList

    vector<int> qArrDurations; // list of durations collected from QuickSort for DynamicArray
    vector<int> qLiDurations; // list of durations collected from QuickSort for LinkedList

    vector<int> sArrDurations; // list of durations collected from SelectionSort for DynamicArray
    vector<int> sLiDurations; // list of durations collected from SelectionSort for LinkedList

    vector<int> cArrDurations; // list of durations collected from SelectionSort for DynamicArray
    vector<int> cLiDurations; // list of durations collected from SelectionSort for LinkedList

    vector<int> shArrDurations; // list of durations collected from SelectionSort for DynamicArray
    vector<int> shLiDurations; // list of durations collected from SelectionSort for LinkedList

public:

    auto getBArrDurations() {return bArrDurations;}
    auto getIArrDurations() {return iArrDurations;}
    auto getMArrDurations() {return mArrDurations;}
    auto getQArrDurations() {return qArrDurations;}
    auto getSArrDurations() {return sArrDurations;}
    auto getCArrDurations() {return cArrDurations;}
    auto getSHArrDurations() {return shArrDurations;}

    auto getBLiDurations() {return bLiDurations;}
    auto getILiDurations() {return iLiDurations;}
    auto getMLiDurations() {return mLiDurations;}
    auto getQLiDurations() {return qLiDurations;}
    auto getSLiDurations() {return sLiDurations;}
    auto getCLiDurations() {return cLiDurations;}
    auto getSHLiDurations() {return shLiDurations;}

    PreparedConsole()
    {
        int amount_10 = 10;
        int amount_100 = 100;
        int amount_1000 = 1000;
        int amount_10000 = 10000;
        int amount_20000 = 20000;
        int amount_40000 = 40000;

        const Sorts bSort = Sorts::BubbleSort;
        Test<int, bSort> bTest;
        pair<int, int> buffer;

        cout << "BubbleSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = bTest(amount_10, low, high);
        bArrDurations.push_back(buffer.first);
        bLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "BubbleSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = bTest(amount_100, low, high);
        bArrDurations.push_back(buffer.first);
        bLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "BubbleSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = bTest(amount_1000, low, high);
        bArrDurations.push_back(buffer.first);
        bLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "BubbleSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = bTest(amount_10000, low, high, EnablePrint::onlyDuration);
        bArrDurations.push_back(buffer.first);
        bLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "BubbleSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = bTest(amount_20000, low, high, EnablePrint::onlyDuration);
        bArrDurations.push_back(buffer.first);
        bLiDurations.push_back(buffer.second);
        cout << endl;


        /*
        cout << "BubbleSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = bTest(amount_40000, low, high, EnablePrint::onlyDuration);
        bArrDurations.push_back(buffer.first);
        bLiDurations.push_back(buffer.second);
        cout << endl;
        */



        // -------------------------------------------------------------------------------------------------------------



        const Sorts iSort = Sorts::InsertionSort;
        Test<int, iSort> iTest;

        cout << "InsertionSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = iTest(amount_10, low, high);
        iArrDurations.push_back(buffer.first);
        iLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "InsertionSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = iTest(amount_100, low, high);
        iArrDurations.push_back(buffer.first);
        iLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "InsertionSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = iTest(amount_1000, low, high);
        iArrDurations.push_back(buffer.first);
        iLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "InsertionSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = iTest(amount_10000, low, high, EnablePrint::onlyDuration);
        iArrDurations.push_back(buffer.first);
        iLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "InsertionSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = iTest(amount_20000, low, high, EnablePrint::onlyDuration);
        iArrDurations.push_back(buffer.first);
        iLiDurations.push_back(buffer.second);
        cout << endl;

        /*
        cout << "InsertionSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = iTest(amount_40000, low, high, EnablePrint::onlyDuration);
        iArrDurations.push_back(buffer.first);
        iLiDurations.push_back(buffer.second);
        cout << endl;
        */



        // -------------------------------------------------------------------------------------------------------------



        const Sorts mSort = Sorts::MergeSort;
        Test<int, mSort> mTest;

        cout << "MergeSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = mTest(amount_10, low, high);
        mArrDurations.push_back(buffer.first);
        mLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "MergeSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = mTest(amount_100, low, high);
        mArrDurations.push_back(buffer.first);
        mLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "MergeSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = mTest(amount_1000, low, high);
        mArrDurations.push_back(buffer.first);
        mLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "MergeSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = mTest(amount_10000, low, high, EnablePrint::onlyDuration);
        mArrDurations.push_back(buffer.first);
        mLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "MergeSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = mTest(amount_20000, low, high, EnablePrint::onlyDuration);
        mArrDurations.push_back(buffer.first);
        mLiDurations.push_back(buffer.second);
        cout << endl;

        /*
        cout << "MergeSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = mTest(amount_40000, low, high, EnablePrint::onlyDuration);
        mArrDurations.push_back(buffer.first);
        mLiDurations.push_back(buffer.second);
        cout << endl;
        */



        // -------------------------------------------------------------------------------------------------------------



        const Sorts qSort = Sorts::QuickSort;
        Test<int, qSort> qTest;

        cout << "QuickSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = qTest(amount_10, low, high);
        qArrDurations.push_back(buffer.first);
        qLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "QuickSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = qTest(amount_100, low, high);
        qArrDurations.push_back(buffer.first);
        qLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "QuickSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = qTest(amount_1000, low, high);
        qArrDurations.push_back(buffer.first);
        qLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "QuickSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = qTest(amount_10000, low, high, EnablePrint::onlyDuration);
        qArrDurations.push_back(buffer.first);
        qLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "QuickSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = qTest(amount_20000, low, high, EnablePrint::onlyDuration);
        qArrDurations.push_back(buffer.first);
        qLiDurations.push_back(buffer.second);
        cout << endl;

        /*
        cout << "QuickSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = qTest(amount_40000, low, high, EnablePrint::onlyDuration);
        qArrDurations.push_back(buffer.first);
        qLiDurations.push_back(buffer.second);
        cout << endl;
        */



        // -------------------------------------------------------------------------------------------------------------



        const Sorts sSort = Sorts::SelectionSort;
        Test<int, sSort> sTest;

        cout << "SelectionSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = sTest(amount_10, low, high);
        sArrDurations.push_back(buffer.first);
        sLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "SelectionSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = sTest(amount_100, low, high);
        sArrDurations.push_back(buffer.first);
        sLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "SelectionSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = sTest(amount_1000, low, high);
        sArrDurations.push_back(buffer.first);
        sLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "SelectionSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = sTest(amount_10000, low, high, EnablePrint::onlyDuration);
        sArrDurations.push_back(buffer.first);
        sLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "SelectionSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = sTest(amount_20000, low, high, EnablePrint::onlyDuration);
        sArrDurations.push_back(buffer.first);
        sLiDurations.push_back(buffer.second);
        cout << endl;


        /*
        cout << "SelectionSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = sTest(amount_40000, low, high, EnablePrint::onlyDuration);
        sArrDurations.push_back(buffer.first);
        sLiDurations.push_back(buffer.second);
        cout << endl;
        */



        // -------------------------------------------------------------------------------------------------------------



        const Sorts cSort = Sorts::CountingSort;
        Test<int, cSort> cTest;

        cout << "CountingSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = cTest(amount_10, low, high);
        cArrDurations.push_back(buffer.first);
        cLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "CountingSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = cTest(amount_100, low, high);
        cArrDurations.push_back(buffer.first);
        cLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "CountingSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = cTest(amount_1000, low, high);
        cArrDurations.push_back(buffer.first);
        cLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "CountingSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = cTest(amount_10000, low, high, EnablePrint::onlyDuration);
        cArrDurations.push_back(buffer.first);
        cLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "CountingSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = cTest(amount_20000, low, high, EnablePrint::onlyDuration);
        cArrDurations.push_back(buffer.first);
        cLiDurations.push_back(buffer.second);
        cout << endl;

        /*

        cout << "CountingSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = cTest(amount_40000, low, high, EnablePrint::onlyDuration);
        cArrDurations.push_back(buffer.first);
        cLiDurations.push_back(buffer.second);
        cout << endl;

        */


        // -------------------------------------------------------------------------------------------------------------



        const Sorts shSort = Sorts::ShellSort;
        Test<int, shSort> shTest;

        cout << "ShellSort, " << amount_10 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = shTest(amount_10, low, high);
        shArrDurations.push_back(buffer.first);
        shLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "ShellSort, " << amount_100 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = shTest(amount_100, low, high);
        shArrDurations.push_back(buffer.first);
        shLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "ShellSort, " << amount_1000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = shTest(amount_1000, low, high);
        shArrDurations.push_back(buffer.first);
        shLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "ShellSort, " << amount_10000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = shTest(amount_10000, low, high, EnablePrint::onlyDuration);
        shArrDurations.push_back(buffer.first);
        shLiDurations.push_back(buffer.second);
        cout << endl;

        cout << "ShellSort, " << amount_20000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = shTest(amount_20000, low, high, EnablePrint::onlyDuration);
        shArrDurations.push_back(buffer.first);
        shLiDurations.push_back(buffer.second);
        cout << endl;

        /*

        cout << "ShellSort, " << amount_40000 << " elements; " << "range [" << low << "; " << high << "]" << endl;
        buffer = shTest(amount_40000, low, high, EnablePrint::onlyDuration);
        shArrDurations.push_back(buffer.first);
        shLiDurations.push_back(buffer.second);
        cout << endl;

        */
    }
};

int main()
{
    PreparedConsole<-100, 100> console;

    auto bArrDurations = console.getBArrDurations();
    auto iArrDurations = console.getIArrDurations();
    auto mArrDurations = console.getMArrDurations();
    auto qArrDurations = console.getQArrDurations();
    auto sArrDurations = console.getSArrDurations();
    auto cArrDurations = console.getCArrDurations();
    auto shArrDurations = console.getSHArrDurations();

    auto bLiDurations = console.getBLiDurations();
    auto iLiDurations = console.getILiDurations();
    auto mLiDurations = console.getMLiDurations();
    auto qLiDurations = console.getQLiDurations();
    auto sLiDurations = console.getSLiDurations();
    auto cLiDurations = console.getCLiDurations();
    auto shLiDurations = console.getSHLiDurations();

    TablePrinter tp(&std::cout);
    tp.AddColumn("elements", 15);
    tp.AddColumn("BubbleSort", 15);
    tp.AddColumn("InsertionSort", 15);
    tp.AddColumn("MergeSort", 15);
    tp.AddColumn("QuickSort", 15);
    tp.AddColumn("SelectionSort", 15);
    tp.AddColumn("CountingSort", 15);
    tp.AddColumn("ShellSort", 15);

    vector<int> elements = {10, 100, 1000, 10000, 20000, 40000};

    cout << "Sorts execution time (microseconds) for DynamicArray" << endl;
    tp.PrintHeader();
    for (int i=0; i<6; ++i)
        tp << elements[i] << bArrDurations[i] << iArrDurations[i] << mArrDurations[i] << qArrDurations[i] << sArrDurations[i] << cArrDurations[i] << shArrDurations[i];
    tp.PrintFooter();

    cout << endl;

    cout << "Sorts execution time (microseconds) for LinkedList" << endl;
    tp.PrintHeader();
    for (int i=0; i<6; ++i)
        tp << elements[i] << bLiDurations[i] << iLiDurations[i] << mLiDurations[i] << qLiDurations[i] << sLiDurations[i] << cLiDurations[i] << shLiDurations[i];
    tp.PrintFooter();

    vector<int> x = {10, 100, 1000, 10000, 20000, 40000};

    Plot arrPlot;

    arrPlot.xlabel("amount of elements");
    arrPlot.ylabel("time (microseconds)");

    // Set the legend to be on the bottom along the horizontal
    arrPlot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    arrPlot.drawCurve(x, bArrDurations).label("BubbleSort [DynamicArr]");
    arrPlot.drawCurve(x, iArrDurations).label("InsertionSort [DynamicArr]");
    arrPlot.drawCurve(x, mArrDurations).label("MergeSort [DynamicArr]");
    arrPlot.drawCurve(x, qArrDurations).label("QuickSort [DynamicArr]");
    arrPlot.drawCurve(x, sArrDurations).label("SelectionSort [DynamicArr]");
    arrPlot.drawCurve(x, cArrDurations).label("CountingSort [DynamicArr]");
    arrPlot.drawCurve(x, shArrDurations).label("ShellSort [DynamicArr]");


    // -------------------------------------------------------------------------------------------------------------


    Plot liPlot;

    liPlot.xlabel("amount of elements");
    liPlot.ylabel("time (microseconds)");

    // Set the legend to be on the bottom along the horizontal
    liPlot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    liPlot.drawCurve(x, bLiDurations).label("BubbleSort [LinkedList]");
    liPlot.drawCurve(x, iLiDurations).label("InsertionSort [LinkedList]");
    liPlot.drawCurve(x, mLiDurations).label("MergeSort [LinkedList]");
    liPlot.drawCurve(x, qLiDurations).label("QuickSort [LinkedList]");
    liPlot.drawCurve(x, sLiDurations).label("SelectionSort [LinkedList]");
    liPlot.drawCurve(x, cLiDurations).label("CountingSort [LinkedList]");
    liPlot.drawCurve(x, shLiDurations).label("ShellSort [LinkedList]");


    // -------------------------------------------------------------------------------------------------------------


    Figure fig = {{arrPlot, liPlot}};

    fig.title("Sorts");
    fig.palette("dark2");

    arrPlot.show();
    liPlot.show();

    arrPlot.save("example-arrPlot.pdf");
    liPlot.save("example-liPlot.pdf");

    return 0;
}
