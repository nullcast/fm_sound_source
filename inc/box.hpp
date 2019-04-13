#pragma once

#include <cstddef>
#include <vector>
#include <memory>
#include "stream.hpp"

using namespace std;

template<typename T>
class Box {
  protected:
    vector<shared_ptr<Stream<T>>> inputs;
    vector<shared_ptr<Stream<T>>> outputs;
  
  public:
    Box(size_t input_size, size_t output_size);
    virtual void calc() = 0;
    vector<shared_ptr<Stream<T>>>& getOutStreams();
    vector<shared_ptr<Stream<T>>>& getInStreams();
    void setInStream(vector<shared_ptr<Stream<T>>>& inputs);
};
