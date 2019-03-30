#pragma once
#include "context.hpp"

template<typename T>
class ParallelContext : public Context<T> {
  public:
    ParallelContext(vector<shared_ptr<Box<T>>>& boxes);
    void calc();
};
