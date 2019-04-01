#include "../inc/stream.hpp"
#include "../inc/quantization.hpp"

template<typename T>
Stream<T>::Stream(unsigned long size):buffer(size) {
}

template<typename T>
unsigned long Stream<T>::updatePtr(atomic_ulong& p) {
  unsigned long current = p.load();
  unsigned long desired;
  do {
    desired = current % buffer.size();
  } while(!p.compare_exchange_weak(current, desired));

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

template Stream<BIT_8>::Stream(unsigned long size);
template unsigned long Stream<BIT_8>::updatePtr(atomic_ulong& p);
template BIT_8 Stream<BIT_8>::read();
template void Stream<BIT_8>::write(BIT_8 d);
