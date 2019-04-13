#include <climits>

#include "../inc/sin_wave_generator.hpp"
#include "../inc/quantization.hpp"

static constexpr double M_2PI = 2 * M_PI;

template<typename T>
SinWaveGenerator<T>::SinWaveGenerator(double sampling_frequency, double sonic_frequency):WaveGenerator<T>(sampling_frequency, sonic_frequency) {
}

template<typename T>
void SinWaveGenerator<T>::calc() {
  const double phase = M_2PI * this->counter / this->division_number + this->offset;

  if (this->counter >= LONG_MAX) {
    unique_ptr<double> _tmp = make_unique<double>(0);
    this->offset = modf(phase / M_2PI, _tmp.get()) * M_2PI;
    this->counter = 0;
    
    cout << this->counter << endl;
  }

  const T value = sinl(phase);
  this->outputs.at(0)->write(value);

  this->counter++;
}

template SinWaveGenerator<float>::SinWaveGenerator(double sampling_frequency, double sonic_frequency);

template SinWaveGenerator<double>::SinWaveGenerator(double sampling_frequency, double sonic_frequency);
