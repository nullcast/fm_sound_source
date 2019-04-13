#include "../inc/add_filter.hpp"
#include "../inc/quantization.hpp"

int main() {
  vector<shared_ptr<Stream<BIT_8>>> ins(2);
  ins[0] = make_shared<Stream<BIT_8>>(2UL);
  ins[1] = make_shared<Stream<BIT_8>>(2UL);
  AddFilter<BIT_8> f(ins);

  Stream<BIT_8>& out = f.getOutStream();
  
  ins[0]->write(2);
  ins[1]->write(1);
  f.calc();
  cout << (int) out.read() << endl;

  ins[0]->write(4);
  ins[1]->write(3);

  ins[0]->write(7);
  ins[1]->write(9);
  f.calc();
  cout << (int) out.read() << endl;

  f.calc();
  cout << (int) out.read() << endl;

  return 0;
}
