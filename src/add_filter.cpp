#include "../inc/add_filter.hpp"
#include "../inc/quantization.hpp"

template<typename T>
AddFilter<T>::AddFilter(vector<shared_ptr<Stream<T>>>& inputs):Box<T>(0, 0) {
  for(long unsigned int i=0; i<inputs.size(); i++) {
    this->inputs.push_back(inputs.at(i));
  }
  this->outputs.push_back(make_shared<Stream<T>>(1UL));
}

template<typename T>
void AddFilter<T>::calc() {
  T ret = 0;
  for(long unsigned int i=0; i<this->inputs.size(); i++) {
    ret += this->inputs.at(i)->read();
  }
  this->outputs.at(0)->write(ret);
}

template AddFilter<BIT_8>::AddFilter(vector<shared_ptr<Stream<BIT_8>>>& inputs);
template void AddFilter<BIT_8>::calc();
