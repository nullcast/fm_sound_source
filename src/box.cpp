#include "../inc/box.hpp"
#include "../inc/quantization.hpp"

template<typename T>
Box<T>::Box(size_t inputs_size, size_t output_size):inputs(inputs_size), outputs(output_size) {}

template<typename T>
vector<shared_ptr<Stream<T>>>& Box<T>::getOutStreams() {
  return this->outputs;
}

template<typename T>
vector<shared_ptr<Stream<T>>>& Box<T>::getInStreams() {
  return this->inputs;
}

template Box<BIT_16>::Box(size_t inputs_size, size_t output_size);
template vector<shared_ptr<Stream<BIT_16>>>& Box<BIT_16>::getOutStreams();
template vector<shared_ptr<Stream<BIT_16>>>& Box<BIT_16>::getInStreams();
