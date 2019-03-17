#include "includes/buffer.hpp"

template<typename T>
Buffer<T>::Buffer(unsigned long size):ptr(new T[size]) {
  this->size = size;
}

template<typename T>
unsigned long Buffer<T>::updatePtr(unsigned long& p) {
  unsigned long current = p % size;
  p = current + 1;
  return current;
}

template<typename T>
T Buffer<T>::read() {
  return ptr[updatePtr(p_first)];
}

template<typename T>
void Buffer<T>::write(T d) {
  ptr[updatePtr(p_end)] = d;
}

template<typename T>
void Buffer<T>::print() {
  for(int i=0; i<size; i++) {
    cout << (int)ptr[i] << endl;
  }
}

template Buffer<BIT_8>::Buffer(unsigned long size);
template unsigned long Buffer<BIT_8>::updatePtr(unsigned long& p);
template BIT_8 Buffer<BIT_8>::read();
template void Buffer<BIT_8>::write(BIT_8 d);
template void Buffer<BIT_8>::print();

