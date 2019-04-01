#pragma once

#include <vector>
#include <atomic>

using namespace std;

template<typename T>
class Stream {
  private:
    atomic_ulong p_first = 0;
    atomic_ulong p_end = 0;
    vector<T> buffer;

    unsigned long updatePtr(atomic_ulong& p);

  public:
    Stream(unsigned long size);
    T read();
    void write(T d);
};
