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
    desired = (current + 1) % buffer.size();
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

template Stream<BIT_16>::Stream(unsigned long size);
template unsigned long Stream<BIT_16>::updatePtr(atomic_ulong& p);
template BIT_16 Stream<BIT_16>::read();
template void Stream<BIT_16>::write(BIT_16 d);

template Stream<float>::Stream(unsigned long size);
template unsigned long Stream<float>::updatePtr(atomic_ulong& p);
template float Stream<float>::read();
template void Stream<float>::write(float d);

template Stream<double>::Stream(unsigned long size);
template unsigned long Stream<double>::updatePtr(atomic_ulong& p);
template double Stream<double>::read();
template void Stream<double>::write(double d);
