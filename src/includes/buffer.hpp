#include <memory>
#include <iostream>

using namespace std;

using BIT_8 = char;
using BIT_16 = short;
using BIT_32 = long;

template<typename T>
class Buffer {
  private:
    unsigned long size = 0;
    unsigned long p_first = 0;
    unsigned long p_end = 0;
    unique_ptr<T[]> ptr;

    unsigned long updatePtr(unsigned long& p);

  public:
    Buffer(unsigned long size);
    T read();
    void write(T d);
    void print();
};
