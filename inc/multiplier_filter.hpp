#pragma once
#include "box.hpp"

template<typename T>
class MultiplierFilter : public Box<T> {
  protected:
    T multiplied;
  
  public:
    MultiplierFilter(shared_ptr<Stream<T>> input, T multiplied);
    void calc();
};
