#include "includes/context.hpp"

template<typename T>
Context<T>::Context(vector<shared_ptr<Filter<T>>>& filters):inputs(inputs.size()), filters(filters.size()) {
  for(int i=0; i<filters.size(); i++) {
    this->filters[i] = filters[i];
  }

  init();
  
  shared_ptr<Stream<T>> begin_filter = filters[0];
  for(int i=0; i<inputs.size(); i++) {
    begin_filter->inputs[i] = inputs[i];
  }

  shared_ptr<Stream<T>> end_filter = filters[filters.size() - 1];
  output = end_filter.output;
}

template<typename T>
void Context<T>::calc() {
  for(int i=0; i<filters.size(); i++) {
    filters[i]->calc();
  }
}
