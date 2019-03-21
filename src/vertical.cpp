#include "includes/vertical.hpp"
#include "includes/quantization.hpp"

template<typename T>
Vertical<T>::Vertical(size_t inputs_size, vector<shared_ptr<Filter<T>>>& filters):Filter<T>(inputs_size), filters(filters.size()) {

  this->outputs = make_shared<vector<shared_ptr<Stream<T>>>>();
  for(int i = 0; i < this->filters.size(); i++) {
    shared_ptr<Filter<T>> c_f = filters.at(i);
    this->filters.at(i) = c_f;
    vector<shared_ptr<Stream<T>>> i_streams = c_f->getInStreams();
    for(int j = 0; j < i_streams.size(); j++) {
      i_streams.at(j) = this->inputs.at(i+j);
    }
    shared_ptr<vector<shared_ptr<Stream<T>>>> o_streams = c_f->getOutStreams();
    for(int j = 0; j < o_streams->size(); j++) {
      this->outputs->push_back(o_streams->at(j));
    }
  }
}

template<typename T>
void Vertical<T>::calc() {
  for(int i=0; i<filters.size(); i++) {
    filters.at(i)->calc();
  }
}

template Vertical<BIT_8>::Vertical(size_t inputs_size, vector<shared_ptr<Filter<BIT_8>>>& filters);
template void Vertical<BIT_8>::calc();
