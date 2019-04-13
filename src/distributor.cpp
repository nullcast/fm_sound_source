#include "../inc/distributor.hpp"
#include "../inc/quantization.hpp"

template<typename T>
Distributor<T>::Distributor(shared_ptr<Stream<T>> input):Box<T>(1, 0) {
  this->inputs[0] = input;
  this->outputs.push_back(make_shared<Stream<T>>(1UL));
  this->outputs.push_back(make_shared<Stream<T>>(1UL));
}

template<typename T>
void Distributor<T>::calc() {
  T ret = this->inputs.at(0)->read();
  for(long unsigned int i=0; i<this->outputs.size(); i++) {
    this->outputs.at(i)->write(ret);
  }
}

template Distributor<float>::Distributor(shared_ptr<Stream<float>> input);
template void Distributor<float>::calc();

template Distributor<double>::Distributor(shared_ptr<Stream<double>> input);
template void Distributor<double>::calc();
