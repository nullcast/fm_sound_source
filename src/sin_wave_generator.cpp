#include "../inc/sin_wave_generator.hpp"
#include "../inc/quantization.hpp"

template<typename T>
SinWaveGenerator<T>::SinWaveGenerator(double sampling_frequency, double sonic_frequency):WaveGenerator<T>(sampling_frequency, sonic_frequency) {
}

template<typename T>
void SinWaveGenerator<T>::calc() {
  unsigned long current = this->counter;
  this->counter = current + 1;
  /*
  if (this->counter >= this->division_number) {
    this->offset = this->offset + this->counter - this->division_number;
    cout << this->offset << endl;
    this->counter = 0;
  }*/
  //T value = 32767 * sinl(2 * M_PI * current / this->division_number + this->offset);
  T value = 10000 * sinl(2 * M_PI * current / this->division_number + this->offset);
  this->outputs.at(0)->write(value);
}

template SinWaveGenerator<BIT_16>::SinWaveGenerator(double sampling_frequency, double sonic_frequency);
