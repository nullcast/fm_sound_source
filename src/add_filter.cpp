#include "includes/add_filter.hpp"
#include "includes/quantization.hpp"

template<typename T>
AddFilter<T>::AddFilter(vector<shared_ptr<Stream<T>>>& inputs):Filter<T>(inputs) {}

template<typename T>
void AddFilter<T>::calc() {
  T ret = 0;
  for(int i=0; i<this->inputs.size(); i++) {
    ret += this->inputs[i]->read();
  }
  this->output->write(ret);
}

template AddFilter<BIT_8>::AddFilter(vector<shared_ptr<Stream<BIT_8>>>& inputs);
template void AddFilter<BIT_8>::calc();
