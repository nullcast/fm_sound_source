#include "../inc/sign_wave_generator.hpp"
#include "../inc/quantization.hpp"

template<typename T>
SignWaveGenerator<T>::SignWaveGenerator(double sampling_frequency, double sonic_frequency):WaveGenerator<T>(sampling_frequency, sonic_frequency) {
}

template<typename T>
void SignWaveGenerator<T>::calc() {
  unsigned long current = this->counter % this->division_number;
  this->counter = current + 1;
  T value = 127 * sinl(2 * M_PI / this->division_number * current);
  this->outputs.at(0)->write(value);
}

template SignWaveGenerator<BIT_8>::SignWaveGenerator(double sampling_frequency, double sonic_frequency);
