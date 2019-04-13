#include "../inc/add_filter.hpp"
#include "../inc/quantization.hpp"
#include "../inc/parallel_context.hpp"
#include "../inc/serial_context.hpp"

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

  vector<shared_ptr<Box<BIT_8>>> boxes(2);
  boxes[0] = f;
  boxes[1] = f2;

  shared_ptr<ParallelContext<BIT_8>> p = make_shared<ParallelContext<BIT_8>>(boxes);

  shared_ptr<AddFilter<BIT_8>> f3 = make_shared<AddFilter<BIT_8>>(p->getOutStreams());

  vector<shared_ptr<Box<BIT_8>>> boxes2(2);
  boxes2[0] = p;
  boxes2[1] = f3;

  SerialContext<BIT_8> s(boxes2);

  shared_ptr<Stream<BIT_8>> out = s.getOutStreams().at(0);
  
  ins[0]->write(2);
  ins[1]->write(1);

  s.calc();

  cout << (int) out->read() << endl;

  ins[0]->write(4);
  ins[1]->write(3);
  ins2[0]->write(4);
  ins2[1]->write(3);

  ins[0]->write(7);
  ins[1]->write(9);
  ins2[0]->write(7);
  ins2[1]->write(9);

  s.calc();
  cout << (int) out->read() << endl;

  s.calc();
  cout << (int) out->read() << endl;

  return 0;
}
