#include "../inc/context.hpp"
#include "../inc/quantization.hpp"

template<typename T>
Context<T>::Context(vector<shared_ptr<Box<T>>>& boxes):Box<T>(0, 0), boxes(boxes.size()) {
  for(long unsigned int i = 0; i < this->boxes.size(); i++) {
    this->boxes.at(i) = boxes.at(i);
  }
}

template Context<float>::Context(vector<shared_ptr<Box<float>>>& boxes);

template Context<double>::Context(vector<shared_ptr<Box<double>>>& boxes);
