#include "includes/context.hpp"
#include "includes/quantization.hpp"

template<typename T>
Context<T>::Context(size_t inputs_size, vector<shared_ptr<Filter<T>>>& filters):Filter<T>(inputs_size), filters(filters.size()) {
  for(int i = 0; i < this->filters.size(); i++) {
    this->filters.at(i) = filters.at(i);
  }

  shared_ptr<Filter<T>> begin_filter = filters[0];
  for(int i = 0; i < this->inputs.size(); i++) {
    begin_filter->getInStreams().at(i) = this->inputs.at(i);
  }

  shared_ptr<Filter<T>> end_filter = filters.at(filters.size() - 1);
  this->outputs = end_filter->getOutStreams();
}

template<typename T>
void Context<T>::calc() {
  for(int i=0; i<filters.size(); i++) {
    filters.at(i)->calc();
  }
}

template Context<BIT_8>::Context(size_t inputs_size, vector<shared_ptr<Filter<BIT_8>>>& filters);
template void Context<BIT_8>::calc();
