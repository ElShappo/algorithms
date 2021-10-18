#include "catch.hpp"
#include "DynamicArray.hpp"
#include "UdGenerator.hpp"


template <typename T>
void print(DynamicArray<T> arr)
{
    for (int i=0; i<arr.GetLen(); ++i)
        cout << arr[i] << endl;
    cout << endl << endl;
}

template <typename T>
void print(vector<T> vec)
{
    for (auto it : vec)
        cout << it << endl;
    cout << endl << endl;
}

TEST_CASE("Testing GET-method")
{
    int size = 4;
    double buffer[size] = {1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    CHECK(test.GetLen() == 4);
    CHECK(test.GetCapacity() == 4);

    test.PushBack(56875);
    test.PushBack(3465311);
    test.PushBack(78);

    CHECK(test.Get(0) == 1);
    CHECK(test.Get(1) == 567);
    CHECK(test.Get(2) == 1114);
    CHECK(test.Get(3) == 7985);
    CHECK(test.Get(4) == 56875);
    CHECK(test.Get(5) == 3465311);
    CHECK(test.Get(6) == 78);

    CHECK(test.GetLen() == 7);
    CHECK(test.GetCapacity() == 7);

    CHECK_THROWS(test.Get(7));
    CHECK_THROWS(test.Get(5678));
}

TEST_CASE("Testing PushBack-method")
{
    int size = 4;
    double buffer[size] = {1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    for (int i=0; i<size; ++i)
        test.PopBack();

    CHECK(test.GetLen() == 0);
    CHECK(test.GetCapacity() == 4);

    CHECK_THROWS(test.PopBack());

    for (int i=0; i<7; ++i)
    {
        test.PushBack(i);
        CHECK(test.Get(i) == i);
    }

    CHECK_THROWS(test.Get(7));
    CHECK_THROWS(test.Get(5678));
}

TEST_CASE("Testing Insert-method (1)")
{
    int size = 4;
    double buffer[size] = {-1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    CHECK_THROWS(test.Insert(404, 5));

    test.Insert(404, 2);

    CHECK(test.Get(0) == -1);
    CHECK(test.Get(1) == 567);
    CHECK(test.Get(2) == 404);
    CHECK(test.Get(3) == 1114);
    CHECK(test.Get(4) == 7985);


}

TEST_CASE("Testing PushFront-method (1)")
{
    int size = 4;
    double buffer[size] = {-1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    for (int i=0; i<10; ++i)
        test.PushFront(i);

    CHECK(test.GetLen() == 14);
    CHECK(test.GetCapacity() == 14);

    for (int i=0; i<10; i++)
        CHECK(test.Get(i) == 9-i);

    CHECK(test.Get(10) == -1);
    CHECK(test.Get(11) == 567);
    CHECK(test.Get(12) == 1114);
    CHECK(test.Get(13) == 7985);

    CHECK_THROWS(test.Get(166) );
}

TEST_CASE("Testing PushFront-method (2)")
{
    DynamicArray<double> test;

    CHECK_THROWS(test.PopBack());

    for (int i=0; i<10; ++i)
    {
        test.PushFront(i);
        CHECK(test.Get(0) == i);
    }

    CHECK(test.GetLen() == 10);
    CHECK(test.GetCapacity() == 10);

    for (int i=0; i<10; ++i)
    {
        test.PopBack();

        CHECK(test.GetLen() == 9-i);
        CHECK(test.GetCapacity() == 10);
    }
}

TEST_CASE("Testing SET-method (2)")
{
    DynamicArray<double> test;

    for (int i=0; i<10; ++i)
    {
        test.Insert(i, i);
        CHECK (test.Get(i) == i);
    }

    CHECK_THROWS(test.Set(404, -1));
    CHECK_THROWS(test.Set(404, 10));

    test.Set(798, 7);

    CHECK(test.Get(7) == 798);
}

TEST_CASE("Testing SWAP-method")
{
    int size = 4;
    double buffer[size] = {1, 567, 1114, 7985};
    DynamicArray<double> test1(buffer, size);
    DynamicArray<double> test2(test1);

    test2.Swap(1,2);

    CHECK(test1.Get(0) == 1);
    CHECK(test1.Get(1) == 567);
    CHECK(test1.Get(2) == 1114);
    CHECK(test1.Get(3) == 7985);

    CHECK(test2.Get(0) == 1);
    CHECK(test2.Get(1) == 1114);
    CHECK(test2.Get(2) == 567);
    CHECK(test2.Get(3) == 7985);
}


TEST_CASE("Testing RESIZE-method")
{
    int size = 4;
    double buffer[size] = {1, 567, 1114, 7985};
    DynamicArray<double> test1(buffer, size);
    DynamicArray<double> test2(test1);

    test2.Swap(1,2);

    CHECK(test1.Get(0) == 1);
    CHECK(test1.Get(1) == 567);
    CHECK(test1.Get(2) == 1114);
    CHECK(test1.Get(3) == 7985);

    CHECK(test2.Get(0) == 1);
    CHECK(test2.Get(1) == 1114);
    CHECK(test2.Get(2) == 567);
    CHECK(test2.Get(3) == 7985);

    test2.Resize(2);

    CHECK(test2.Get(0) == 1);
    CHECK(test2.Get(1) == 1114);

    CHECK_THROWS(test2.Get(2));

    CHECK(test2.GetLen() == 2);
    CHECK(test2.GetCapacity() == test1.GetCapacity() );
    CHECK(test2.GetCapacity() == 4);
}

TEST_CASE("Testing resistance")
{
    DynamicArray<double> test;

    for (int i=0; i<10; ++i)
        CHECK_THROWS(test.PopBack());
}

TEST_CASE("Testing indexing operator")
{
    DynamicArray<double> test;
    int size = 15;

    for (int i=0; i<size; ++i)
        test.PushBack(i);

    test.PushBack(5687);
    test.PushBack(11567);

    test.PopBack();
    test.PushBack(11567);
    test.PopBack();

    for (int i=0; i<size; ++i)
        CHECK(test[i] == i);

    CHECK(test[size] == 5687);
    CHECK_THROWS(test[size+1]);

    CHECK(test.GetLen() == size+1);
    CHECK(test.GetCapacity() == size+2);
}

TEST_CASE("Testing \"==\" operator")
{
    DynamicArray<double> test;

    test.PushBack(678);
    test.PushBack(4564);
    test.PushBack(15226);
    test.PushBack(1);

    DynamicArray<double> cmp(5);

    CHECK(test.GetCapacity() == 5);
    CHECK(test.GetLen() == 0);

    for (int i=0; i<4; ++i)
    {
        cmp.PushBack(test[i]);
    }
    CHECK(test.GetCapacity() == 5);
    CHECK(test.GetLen() == 4);

    CHECK(test == cmp);
}

TEST_CASE("Testing \"!=\" operator")
{
    DynamicArray<double> test;

    test.PushBack(678);
    test.PushBack(4564);
    test.PushBack(15226);
    test.PushBack(1);

    DynamicArray<double> cmp(test);

    cmp.PopBack();
    cmp.PopBack();

    CHECK(test != cmp);
}

TEST_CASE("Testing copy ctor from vector and casting to vector [DynArr]")
{
    UdGenerator<int> gen;

    vector<int> sample_1000;

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()

    cout << "Generated values added to vector[int] later stored in DynamicArr" << endl;
    for (int i=0; i<100; ++i)
    {
        cout << gen(-100000, 100000, generator) << endl;
        sample_1000.push_back(gen(-100000, 100000, generator));
    }

    DynamicArray<int> arr(sample_1000);
    cout << "Values stored in DynamicArr: " << endl;

    print(arr);
    vector<int> vec(arr.to_vector());
    //print(vec)


    //LinkedList li(vec);
    //print(li);
}
