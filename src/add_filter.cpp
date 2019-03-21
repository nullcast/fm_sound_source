#include "includes/add_filter.hpp"
#include "includes/quantization.hpp"

template<typename T>
AddFilter<T>::AddFilter(vector<shared_ptr<Stream<T>>>& inputs):Filter<T>(inputs.size()) {
  for(int i=0; i<inputs.size(); i++) {
    this->inputs.at(i) = inputs.at(i);
  }
  this->outputs = make_shared<vector<shared_ptr<Stream<T>>>>(1);
  this->outputs->at(0) = make_shared<Stream<T>>(1UL);
}

template<typename T>
void AddFilter<T>::calc() {
  T ret = 0;
  for(int i=0; i<this->inputs.size(); i++) {
    ret += this->inputs.at(i)->read();
  }
  this->outputs->at(0)->write(ret);
}

template AddFilter<BIT_8>::AddFilter(vector<shared_ptr<Stream<BIT_8>>>& inputs);
template void AddFilter<BIT_8>::calc();
