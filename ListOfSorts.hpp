#ifndef LIST_OF_SORTS_HPP
#define LIST_OF_SORTS_HPP

#include <functional>
#include <map>
#include <string>
#include <utility>

#include "ISort.hpp"

/*
template<typename T, typename ... Ts>
class ListOfSorts
{
private:
    map<string, function<ISort<T, Ts ... ts>*()> listOfSorts_;

    ListOfSorts() {}
    static ListOfSorts* singleton_ = nullptr;

    class Factory
    {
    public:
        Foo* Build(std::string const& key) const
        {
            auto it = listOfSorts_.find(key);
            if (it == listOfSorts_.end()) { return 0; } // no such key
                return (it->second)();
        }
    };

public:

    // disabling ctors
    Singleton(ListOfSorts &other) = delete;
    void operator=(const ListOfSorts &) = delete;

    static ListOfSorts *GetInstance()
    {
        if(singleton_ == nullptr)
        {
            singleton_ = new ListOfSorts();
        }
        return singleton_;
    }

    bool add(string const& key, function<ISort*()> const& type) {
        return listOfSorts_.insert(std::make_pair(key, type)).second;

    map<string, function<ISort*()> getList() {return listOfSorts_}
};
*/
#endif // LIST_OF_SORTS_HPP
