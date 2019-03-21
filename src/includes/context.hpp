#include "filter.hpp"

template<typename T>
class Context : public Filter<T> {
  protected:
    vector<shared_ptr<Filter<T>>> filters;

  public:
    Context(vector<shared_ptr<Stream<T>>>& inputs) = delete;
    Context(vector<shared_ptr<Filter<T>>>& filters);
    void calc();
}
