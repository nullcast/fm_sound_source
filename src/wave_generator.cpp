#include "../inc/wave_generator.hpp"
#include "../inc/quantization.hpp"

template<typename T>
WaveGenerator<T>::WaveGenerator(double sampling_frequency, double sonic_frequency):Box<T>(0, 0) {
  this->division_number = sampling_frequency / sonic_frequency;
  this->outputs.push_back(make_shared<Stream<T>>(1UL));
}

template WaveGenerator<BIT_16>::WaveGenerator(double sampling_frequency, double sonic_frequency);
