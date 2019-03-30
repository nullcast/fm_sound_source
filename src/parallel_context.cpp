#include "../inc/parallel_context.hpp"
#include "../inc/quantization.hpp"

template<typename T>
ParallelContext<T>::ParallelContext(vector<shared_ptr<Box<T>>>& boxes):Context<T>(boxes) {
  for(long unsigned int i = 0; i < this->boxes.size(); i++) {
    shared_ptr<Box<T>> c_f = boxes.at(i);
    vector<shared_ptr<Stream<T>>> i_streams = c_f->getInStreams();
    for(long unsigned int j = 0; j < i_streams.size(); j++) {
      this->inputs.push_back(i_streams.at(j));
    }
    vector<shared_ptr<Stream<T>>> o_streams = c_f->getOutStreams();
    for(long unsigned int j = 0; j < o_streams.size(); j++) {
      this->outputs.push_back(o_streams.at(j));
    }
  }
}

template<typename T>
void ParallelContext<T>::calc() {
  for(long unsigned int i=0; i<this->boxes.size(); i++) {
    this->boxes.at(i)->calc();
  }
}

template ParallelContext<BIT_8>::ParallelContext(vector<shared_ptr<Box<BIT_8>>>& boxes);
template void ParallelContext<BIT_8>::calc();
