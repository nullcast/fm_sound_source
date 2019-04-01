#include "../inc/sin_wave_generator.hpp"
#include "../inc/quantization.hpp"

template<typename T>
SinWaveGenerator<T>::SinWaveGenerator(double sampling_frequency, double sonic_frequency):WaveGenerator<T>(sampling_frequency, sonic_frequency) {
}

template<typename T>
void SinWaveGenerator<T>::calc() {
  unsigned long current = this->counter;
  this->counter = current + 1;
  if (this->counter >= this->division_number) {
    this->offset = this->division_number - this->counter;
    this->counter = 0;
  }
  T value = 127 * sinl(2 * M_PI / this->division_number * (current + this->offset));
  this->outputs.at(0)->write(value);
}

template SinWaveGenerator<BIT_8>::SinWaveGenerator(double sampling_frequency, double sonic_frequency);
