#pragma once
#include "box.hpp"

template<typename T>
class AddFilter : public Box<T> {
  public:
    AddFilter(vector<shared_ptr<Stream<T>>>& inputs);
    void calc();
};
