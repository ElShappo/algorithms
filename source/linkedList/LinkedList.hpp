#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedListException.hpp"
#include "DynamicArray.hpp"
#include <list>

template <class T>
class LinkedList
{
public:

    LinkedList() {}

    LinkedList(vector<T> & vec)
    {
        for (auto it : vec)
            this->PushBack(it);
    }

    LinkedList(list<T> & li)
    {
        for (auto it : li)
            this->PushBack(it);
    }

    LinkedList(T* items, int count)
    {
        if (count < 0)
            throw LinkedListException<T>("IndexOutOfRange");

        for (int i=0; i<count; ++i)
            PushBack(items[i]);
    }

    LinkedList(LinkedList<T> & list)
    {
        for (int i=0; i<list.GetLen(); ++i)
            PushBack(list.Get(i));
    }

    T & operator[](int index)
    {
        if (index < 0 || index >= len_)
            throw LinkedListException<T>("IndexOutOfRange");

        int count = 0;
        Node* buffer = head_;

        if (index == 0)
        {
            return buffer->data_;
        }
        else
        {
            while (count < index)
            {
                buffer = buffer->next_;
                ++count;
            }
            return buffer->data_;
        }
    }

    bool operator ==(const LinkedList<T> & list) const
    {
        if (list.GetLen() != GetLen() )
            return false;

        for (int i=0; i<list.GetLen(); ++i)
        {
            if (list.Get(i) != Get(i))
                return false;
        }
        return true;
    }

    bool operator !=(const LinkedList<T> list) const
    {
        if (list.GetLen() != GetLen() )
            return true;

        for (int i=0; i<list.GetLen(); ++i)
        {
            if (list.Get(i) == Get(i))
                return false;
        }
        return true;
    }

    static LinkedList<T> & to_linked_list(vector<T> vec)
    {
        LinkedList<T>* li = new LinkedList<T>();

        for (int i=0; i<vec.size(); ++i)
            li->PushBack(vec[i]);

        return *li;
    }

    static list<T> & to_list(vector<T> vec)
    {
        list<T>* li = new list<T>();

        for (int i=0; i<vec.size(); ++i)
            li->push_back(vec[i]);

        return *li;
    }

    vector<T> & to_vector()
    {
        vector<T>* vec = new vector<T>();

        for (int i=0; i<GetLen(); ++i)
            vec->push_back(Get(i));

        return *vec;
    }

    static vector<T> & to_vector(list<T> LIST)
    {
        LinkedList li(LIST);

        vector<T>* vec = new vector<T>();

        for (int i=0; i<li.GetLen(); ++i)
            vec->push_back(li[i]);

        return *vec;
    }

    void operator =(DynamicArray<T> & list)
    {
        while (!Empty() )
            PopBack();

        for (int i=0; i<list.GetLen(); ++i)
            PushBack(list[i]);
    }



    void Insert(T data, int index)
    {
        if (index < 0 || index > len_)
            throw LinkedListException<T>("IndexOutOfRange");

        ++len_;

        int count = 0;
        Node* buffer = head_;

        if (index == 0)
        {
            head_ = new Node(data, buffer);
        }
        else
        {
            while (count < index-1)
            {
                buffer = buffer->next_;
                ++count;
            }
            // now buffer holds either head_ or next_ of Node with number n-2 (either head_ or Node with number n-1)
            //cout << buffer->data_ << endl;

            Node* oldNext = buffer->next_;
            buffer->next_ = new Node(data, oldNext);
        }
    }

    void PushBack(T data) { Insert(data, len_); }
    void PushFront(T data) { Insert(data, 0); }

    T PopBack()
    {
        if (len_ == 0 || head_ == NULL)
            throw LinkedListException<T>("Can't pop empty list");

        int count = 0;
        Node* buffer = head_;

        while (count < len_-1)
        {
            buffer = buffer->next_;
            ++count;
        }

        T buff = buffer->data_;
        free(buffer->next_);
        buffer->next_ = NULL;
        --len_;

        return buff;
    }

    T Get(int index)
    {
        if (index < 0 || index >= len_)
            throw LinkedListException<T>("IndexOutOfRange");

        Node* buffer = head_;

        for (int i=0; i<index; ++i)
            buffer = buffer->next_;

        return buffer->data_;
    }

    void Set(T data, int index)
    {
        if (index < 0 || index >= len_)
            throw LinkedListException<T>("IndexOutOfRange");

        Node* buffer = head_;

        for (int i=0; i<index; ++i)
            buffer = buffer->next_;

        buffer->data_ = data;
    }

    class LinkedList<T>* GetSubList(int iStart, int iEnd)
    {
        if (iStart < 0 || iEnd < 0 || (iStart > iEnd))
            throw LinkedListException<T>("IndexOutOfRange");

        int size = iEnd-iStart+1;

        T items[size];

        for (int i=0; i<size; ++i)
            items[i] = Get(iStart+i);

        return new LinkedList(items, size);
    }

    void Append(LinkedList<T> buffer)
    {
        for (int i=0; i<buffer.GetLen(); ++i)
            PushBack(buffer.Get(i));
    }

    T GetFirst()
    {
        return Get(0);
    }

    T GetLast()
    {
        return Get(len_-1);
    }

    int GetLen()
    {
        return len_;
    }

    bool Empty() const noexcept
    {
        if (len_ == 0)
            return true;
        return false;
    }

private:
    class Node
    {
    public:
        Node(T data = T(), Node* next = nullptr)
        {
            data_ = data;
            next_ = next;
        }
        ~Node()
        {
            delete next;
        }

        Node* next_ = nullptr;
        T data_;
    };

    Node* head_ = nullptr;
    int len_ = 0;

};

/*
LinkedList(T* items, int count)
    {


    }

    LinkedList()
    {


    }

    LinkedList(LinkedList<T> & list const)
    {

    }

    T GetFirst()
    {

    }

    T GetLast()
    {

    }

    T Get(int index)
    {

    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {

    }

    int GetLength()
    {

    }

    void Append(T item)
    {

    }

    void Prepend(T item)
    {

    }

    void InsertAt(T item, int index)
    {

    }

    LinkedList<T*> Concat(LinkedList<T> *list)
    {

    }
*/

#endif // LINKED_LIST_H
