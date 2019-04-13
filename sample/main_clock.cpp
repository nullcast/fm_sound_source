#include <iostream>
#include "../inc/quantization.hpp"
#include "../inc/sin_wave_generator.hpp"
#include "../inc/clock.hpp"

using namespace std;

int main() {
  SinWaveGenerator<BIT_8> s(5.0, 3.0);
  Clock c((unsigned long)5, [&]() {
    s.calc();
    cout << (int) s.getOutStreams()[0]->read() << endl;
  });

  c.start();
  
  while(true);

  return 0;
}
