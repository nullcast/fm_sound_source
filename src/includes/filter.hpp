#include <cstddef>
#include <vector>
#include <memory>
#include "stream.hpp"

using namespace std;

template<typename T>
class Filter {
  protected:
    vector<shared_ptr<Stream<T>>> inputs;
    shared_ptr<Stream<T>> output;
  
  public:
    Filter(vector<shared_ptr<Stream<T>>>& inputs);
    virtual void calc() = 0;
    Stream<T>& getOutStream();
};
