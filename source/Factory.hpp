#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "ISort.hpp"

#include <function>
#include <map>

#include "../ListOfSorts.hpp"

class SortFactory
{
public:
  typedef std::function<ISort*()> Builder;


  SortFactory(ListOfSorts const & sorts)
  {
      std::map<std::string, Builder> _map = sorts.getList();
  }

  bool Register(std::string const& key, Builder const& builder) {
    return map.insert(std::make_pair(key, builder)).second;
  }

  Foo* Build(std::string const& key) const {
    auto it = _map.find(key);
    if (it == _map.end()) { return 0; } // no such key
    return (it->second)();
  }

private:
  std::map<std::string, Builder> _map;
};

#endif // FACTORY_HPP
