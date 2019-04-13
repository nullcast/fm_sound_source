#include "../inc/multiplier_filter.hpp"
#include "../inc/quantization.hpp"

template<typename T>
MultiplierFilter<T>::MultiplierFilter(shared_ptr<Stream<T>> input, T multiplied):
    Box<T>(0, 0),
    multiplied(multiplied) {
  this->inputs.push_back(input);
  this->outputs.push_back(make_shared<Stream<T>>(1UL));
}

template<typename T>
void MultiplierFilter<T>::calc() {
  T ret = this->multiplied * this->inputs.at(0)->read();
  this->outputs.at(0)->write(ret);
}

template MultiplierFilter<float>::MultiplierFilter(shared_ptr<Stream<float>> input, float multiplied);
template void MultiplierFilter<float>::calc();

template MultiplierFilter<double>::MultiplierFilter(shared_ptr<Stream<double>> input, double multiplied);
template void MultiplierFilter<double>::calc();
