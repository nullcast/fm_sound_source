#include <iostream>
#include "../inc/quantization.hpp"
#include "../inc/sin_wave_generator.hpp"

using namespace std;

int main() {
  SinWaveGenerator<BIT_8> s(10.0, 1.0);

  for(int i=0; i<20; i++) {
    s.calc();
    cout << (int) s.getOutStreams()[0]->read() << endl;
  }

  return 0;
}
