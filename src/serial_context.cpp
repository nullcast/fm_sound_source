#include "../inc/serial_context.hpp"
#include "../inc/quantization.hpp"

template<typename T>
SerialContext<T>::SerialContext(vector<shared_ptr<Box<T>>>& boxes):Context<T>(boxes) {
  shared_ptr<Box<T>> begin_box = boxes[0];
  for(long unsigned int i = 0; i < begin_box->getInStreams().size(); i++) {
    this->inputs.push_back(begin_box->getInStreams().at(i));
  }

  shared_ptr<Box<T>> end_box = boxes.at(boxes.size() - 1);
  for(long unsigned int i = 0; i < end_box->getOutStreams().size(); i++) {
    this->outputs.push_back(end_box->getOutStreams().at(i));
  }
}

template<typename T>
void SerialContext<T>::calc() {
  for(long unsigned int i=0; i<this->boxes.size(); i++) {
    this->boxes.at(i)->calc();
  }
}

template SerialContext<BIT_16>::SerialContext(vector<shared_ptr<Box<BIT_16>>>& boxes);
template void SerialContext<BIT_16>::calc();
