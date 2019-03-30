#include "../inc/context.hpp"
#include "../inc/quantization.hpp"

template<typename T>
Context<T>::Context(vector<shared_ptr<Box<T>>>& boxes):Box<T>(0, 0), boxes(boxes.size()) {
  for(int i = 0; i < this->boxes.size(); i++) {
    this->boxes.at(i) = boxes.at(i);
  }
}

template Context<BIT_8>::Context(vector<shared_ptr<Box<BIT_8>>>& boxes);
