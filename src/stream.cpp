#include "../inc/stream.hpp"
#include "../inc/quantization.hpp"

template<typename T>
Stream<T>::Stream(unsigned long size):buffer(size) {
  this->size = size;
}

template<typename T>
unsigned long Stream<T>::updatePtr(unsigned long& p) {
  unsigned long current = p % size;
  p = current + 1;
  return current;
}

template<typename T>
T Stream<T>::read() {
  return buffer[updatePtr(p_first)];
}

template<typename T>
void Stream<T>::write(T d) {
  buffer[updatePtr(p_end)] = d;
}

template<typename T>
void Stream<T>::print() {
  for(unsigned long i=0; i<size; i++) {
    cout << (int)buffer[i] << endl;
  }
}

template Stream<BIT_8>::Stream(unsigned long size);
template unsigned long Stream<BIT_8>::updatePtr(unsigned long& p);
template BIT_8 Stream<BIT_8>::read();
template void Stream<BIT_8>::write(BIT_8 d);
template void Stream<BIT_8>::print();

