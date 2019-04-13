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

template Box<float>::Box(size_t inputs_size, size_t output_size);
template vector<shared_ptr<Stream<float>>>& Box<float>::getOutStreams();
template vector<shared_ptr<Stream<float>>>& Box<float>::getInStreams();

template Box<double>::Box(size_t inputs_size, size_t output_size);
template vector<shared_ptr<Stream<double>>>& Box<double>::getOutStreams();
template vector<shared_ptr<Stream<double>>>& Box<double>::getInStreams();
