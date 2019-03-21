#pragma once

#include <cstddef>
#include <vector>
#include <memory>
#include "stream.hpp"

using namespace std;

template<typename T>
class Filter {
  protected:
    vector<shared_ptr<Stream<T>>> inputs;
    shared_ptr<vector<shared_ptr<Stream<T>>>> outputs;
  
  public:
    Filter(size_t input_size);
    virtual void calc() = 0;
    shared_ptr<vector<shared_ptr<Stream<T>>>> getOutStreams();
    vector<shared_ptr<Stream<T>>>& getInStreams();
};
