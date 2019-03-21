#include "includes/filter.hpp"
#include "includes/quantization.hpp"

template<typename T>
Filter<T>::Filter(size_t inputs_size):inputs(inputs_size) {}

template<typename T>
shared_ptr<vector<shared_ptr<Stream<T>>>> Filter<T>::getOutStreams() {
  return this->outputs;
}

template<typename T>
vector<shared_ptr<Stream<T>>>& Filter<T>::getInStreams() {
  return this->inputs;
}

template Filter<BIT_8>::Filter(size_t inputs_size);
template shared_ptr<vector<shared_ptr<Stream<BIT_8>>>> Filter<BIT_8>::getOutStreams();
template vector<shared_ptr<Stream<BIT_8>>>& Filter<BIT_8>::getInStreams();
