
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch.hpp"
#include "QuickSort.hpp"
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
vector<T> quickSort(vector<T> vec)
{
    //print(vec);
    QuickSort<T> sort(vec);
    vector<T> res = sort.get();
    //print(res);
    return res;
}

TEST_CASE("testing quickSort [vector][int]", "[vector][int]")
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


    CHECK_NOTHROW(quickSort(sample_10));
    CHECK_NOTHROW(quickSort(sample_100));
    CHECK_NOTHROW(quickSort(sample_1000));
    CHECK_NOTHROW(quickSort(sample_10000));
    CHECK_NOTHROW(quickSort(sample_100000));
    CHECK_NOTHROW(quickSort(sample_1000000));

    BENCHMARK("quickSort[10]")
    {
        return quickSort(sample_10);
    };
    BENCHMARK("quickSort[100]")
    {
        return quickSort(sample_100);
    };
    BENCHMARK("quickSort[1000]")
    {
        return quickSort(sample_1000);
    };
    BENCHMARK("quickSort[10000]")
    {
        return quickSort(sample_10000);
    };
    BENCHMARK("quickSort[100000]")
    {
        return quickSort(sample_100000);
    };
    BENCHMARK("quickSort[100000]")
    {
        return quickSort(sample_1000000);
    };
}

TEST_CASE("testing quickSort [vector][float]", "[vector][float]")
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

    CHECK_NOTHROW(quickSort(sample_10));
    CHECK_NOTHROW(quickSort(sample_100));
    CHECK_NOTHROW(quickSort(sample_1000));
    CHECK_NOTHROW(quickSort(sample_10000));
    CHECK_NOTHROW(quickSort(sample_100000));
    CHECK_NOTHROW(quickSort(sample_1000000));

    BENCHMARK("quickSort[10]")
    {
        return quickSort(sample_10);
    };
    BENCHMARK("quickSort[100]")
    {
        return quickSort(sample_100);
    };
    BENCHMARK("quickSort[1000]")
    {
        return quickSort(sample_1000);
    };
    BENCHMARK("quickSort[10000]")
    {
        return quickSort(sample_10000);
    };
    BENCHMARK("quickSort[100000]")
    {
        return quickSort(sample_100000);
    };
    BENCHMARK("quickSort[100000]")
    {
        return quickSort(sample_1000000);
    };
}

