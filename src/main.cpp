#include "../inc/quantization.hpp"
#include "../inc/sign_wave_generator.hpp"

using namespace std;

int main() {
  SignWaveGenerator<BIT_8> s(10.0, 1.0);

  for(int i=0; i<20; i++) {
    s.calc();
    cout << (int) s.getOutStreams()[0]->read() << endl;
  }

  return 0;
}
