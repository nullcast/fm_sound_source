#pragma once
#include "filter.hpp"

template<typename T>
class Vertical : public Filter<T> {
  protected:
    vector<shared_ptr<Filter<T>>> filters;

  public:
    Vertical(vector<shared_ptr<Stream<T>>>& inputs) = delete;
    Vertical(size_t inputs_size, vector<shared_ptr<Filter<T>>>& filters);
    void calc();
};
