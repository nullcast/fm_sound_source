#pragma once
#include "filter.hpp"

template<typename T>
class AddFilter : public Filter<T> {
  public:
    AddFilter(vector<shared_ptr<Stream<T>>>& inputs);
    void calc();
};
