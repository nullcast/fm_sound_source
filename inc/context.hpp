#pragma once
#include "box.hpp"

template<typename T>
class Context : public Box<T> {
  protected:
    vector<shared_ptr<Box<T>>> boxes;

  public:
    Context(vector<shared_ptr<Box<T>>>& boxes);
    virtual void calc() = 0;
};
