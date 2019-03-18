#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Stream {
  private:
    unsigned long size = 0;
    unsigned long p_first = 0;
    unsigned long p_end = 0;
    vector<T> buffer;

    unsigned long updatePtr(unsigned long& p);

  public:
    Stream(unsigned long size);
    T read();
    void write(T d);
    void print();
};
