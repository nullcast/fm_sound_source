#pragma once
#include "box.hpp"

template<typename T>
class Distributor : public Box<T> {
  public:
    Distributor(shared_ptr<Stream<T>> input);
    void calc();
};
