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

template<typename T>
void Box<T>::setInStream(vector<shared_ptr<Stream<T>>>& inputs) {
  for(long unsigned int i=0; i<this->inputs.size(); i++) {
    this->inputs[i] = inputs.at(i);
  }
}

template Box<float>::Box(size_t inputs_size, size_t output_size);
template vector<shared_ptr<Stream<float>>>& Box<float>::getOutStreams();
template vector<shared_ptr<Stream<float>>>& Box<float>::getInStreams();
template void Box<float>::setInStream(vector<shared_ptr<Stream<float>>>& inputs);

template Box<double>::Box(size_t inputs_size, size_t output_size);
template vector<shared_ptr<Stream<double>>>& Box<double>::getOutStreams();
template vector<shared_ptr<Stream<double>>>& Box<double>::getInStreams();
template void Box<double>::setInStream(vector<shared_ptr<Stream<double>>>& inputs);
