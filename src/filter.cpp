#include "includes/filter.hpp"
#include "includes/quantization.hpp"

template<typename T>
Filter<T>::Filter(vector<shared_ptr<Stream<T>>>& inputs):inputs(inputs.size()), output(new Stream<T>(1UL)) {
  for(int i=0; i<inputs.size(); i++) {
    this->inputs[i] = inputs[i];
  }
}

template<typename T>
Stream<T>& Filter<T>::getOutStream() {
  return *(this->output);
}

template Filter<BIT_8>::Filter(vector<shared_ptr<Stream<BIT_8>>>& inputs);
template Stream<BIT_8>& Filter<BIT_8>::getOutStream();
