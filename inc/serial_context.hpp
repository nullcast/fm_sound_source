#pragma once
#include "context.hpp"

template<typename T>
class SerialContext : public Context<T> {
  public:
    SerialContext(vector<shared_ptr<Box<T>>>& boxes);
    void calc();
};
