#include "includes/add_filter.hpp"
#include "includes/quantization.hpp"
#include "includes/context.hpp"

using namespace std;

int main() {
  vector<shared_ptr<Stream<BIT_8>>> ins(2);
  ins[0] = make_shared<Stream<BIT_8>>(2UL);
  ins[1] = make_shared<Stream<BIT_8>>(2UL);
  shared_ptr<AddFilter<BIT_8>> f = make_shared<AddFilter<BIT_8>>(ins);

  vector<shared_ptr<Stream<BIT_8>>> ins2(2);
  ins2[0] = make_shared<Stream<BIT_8>>(2UL);
  ins2[1] = make_shared<Stream<BIT_8>>(2UL);
  shared_ptr<AddFilter<BIT_8>> f2 = make_shared<AddFilter<BIT_8>>(ins2);

  vector<shared_ptr<Stream<BIT_8>>> ins3(2);
  ins3[0] = f->getOutStream();
  ins3[1] = f2->getOutStream();
  shared_ptr<AddFilter<BIT_8>> f3 = make_shared<AddFilter<BIT_8>>(ins3);

  vector<shared_ptr<Filter<BIT_8>>> fs(3);
  fs[0] = f;
  fs[1] = f2;
  fs[2] = f3;

  Context<BIT_8> c(fs);

  shared_ptr<Stream<BIT_8>> out = c.getOutStream();
  
  ins[0]->write(2);
  ins[1]->write(1);
  ins2[0]->write(2);
  ins2[1]->write(1);
  c.calc();

  cout << (int) out->read() << endl;

  ins[0]->write(4);
  ins[1]->write(3);
  ins2[0]->write(4);
  ins2[1]->write(3);

  ins[0]->write(7);
  ins[1]->write(9);
  ins2[0]->write(7);
  ins2[1]->write(9);

  c.calc();
  cout << (int) out->read() << endl;

  c.calc();
  cout << (int) out->read() << endl;

  return 0;
