#include <iostream>
#include <string>
#include <vector>

#include "DynamicArray.hpp"
#include "LinkedList.hpp"

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

vector<int> parse(string str)
{
    vector<int> res;

    for (unsigned int i=0; i<str.size(); ++i)
    {
        string buffer;
        while (str[i] != ' ' && i != str.size()-1)
        {
            buffer.push_back(str[i]);
            ++i;
        }
        if (!buffer.empty())
            res.push_back(stoi(buffer));
    }
    return res;
}

enum class Sorts
{
    BubbleSort,
    InsertionSort,
    MergeSort,
    QuickSort,
    SelectionSort,
    CountingSort,
};

enum class EnablePrint
{
    disabled,
    onlyDuration,
    enabled,
};
