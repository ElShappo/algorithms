#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch.hpp"
#include "SelectionSort.hpp"
#include "UdGenerator.hpp"

using namespace std;


template <typename T>
void print(vector<T> vec)
{
    for (auto it : vec)
        cout << it << endl;
    cout << endl << endl;
}

template <typename T>
vector<T> selectionSort(vector<T> vec)
{
    SelectionSort<T> sort;
    return sort(vec);
}

TEST_CASE("testing selectionSort [vector][int]", "[vector][int]")
{
    UdGenerator<int> gen;

    vector<int> sample_10;
    vector<int> sample_100;
    vector<int> sample_1000;
    vector<int> sample_10000;
    vector<int> sample_100000;
    vector<int> sample_1000000;
    vector<int> sample_10000000;

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()

    for (int i=0; i<10; ++i)
        sample_10.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<100; ++i)
        sample_100.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<1000; ++i)
        sample_1000.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<10000; ++i)
        sample_10000.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<100000; ++i)
        sample_100000.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<1000000; ++i)
        sample_1000000.push_back(gen(-100000, 100000, generator));


    CHECK_NOTHROW(selectionSort(sample_10));
    CHECK_NOTHROW(selectionSort(sample_100));
    CHECK_NOTHROW(selectionSort(sample_1000));
    CHECK_NOTHROW(selectionSort(sample_10000));
    CHECK_NOTHROW(selectionSort(sample_100000));
    CHECK_NOTHROW(selectionSort(sample_1000000));

    BENCHMARK("selectionSort[10]")
    {
        return selectionSort(sample_10);
    };
    BENCHMARK("selectionSort[100]")
    {
        return selectionSort(sample_100);
    };
    BENCHMARK("selectionSort[1000]")
    {
        return selectionSort(sample_1000);
    };
    BENCHMARK("selectionSort[10000]")
    {
        return selectionSort(sample_10000);
    };
    BENCHMARK("selectionSort[100000]")
    {
        return selectionSort(sample_100000);
    };
    BENCHMARK("selectionSort[100000]")
    {
        return selectionSort(sample_1000000);
    };
}

TEST_CASE("testing selectionSort [vector][float]", "[vector][float]")
{
    UdGenerator<float> gen;

    vector<float> sample_10;
    vector<float> sample_100;
    vector<float> sample_1000;
    vector<float> sample_10000;
    vector<float> sample_100000;
    vector<float> sample_1000000;
    vector<float> sample_10000000;

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()

    for (int i=0; i<10; ++i)
        sample_10.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<100; ++i)
        sample_100.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<1000; ++i)
        sample_1000.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<10000; ++i)
        sample_10000.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<100000; ++i)
        sample_100000.push_back(gen(-100000, 100000, generator));

    for (int i=0; i<1000000; ++i)
        sample_1000000.push_back(gen(-100000, 100000, generator));

    CHECK_NOTHROW(selectionSort(sample_10));
    CHECK_NOTHROW(selectionSort(sample_100));
    CHECK_NOTHROW(selectionSort(sample_1000));
    CHECK_NOTHROW(selectionSort(sample_10000));
    CHECK_NOTHROW(selectionSort(sample_100000));
    CHECK_NOTHROW(selectionSort(sample_1000000));

    BENCHMARK("selectionSort[10]")
    {
        return selectionSort(sample_10);
    };
    BENCHMARK("selectionSort[100]")
    {
        return selectionSort(sample_100);
    };
    BENCHMARK("selectionSort[1000]")
    {
        return selectionSort(sample_1000);
    };
    BENCHMARK("selectionSort[10000]")
    {
        return selectionSort(sample_10000);
    };
    BENCHMARK("selectionSort[100000]")
    {
        return selectionSort(sample_100000);
    };
    BENCHMARK("selectionSort[100000]")
    {
        return selectionSort(sample_1000000);
    };
}

