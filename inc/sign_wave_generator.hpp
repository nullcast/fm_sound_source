#pragma once
#include <cmath>
#include "wave_generator.hpp"

using namespace std;

template<typename T>
class SignWaveGenerator : public WaveGenerator<T> {
  public:
    SignWaveGenerator(double sampling_frequency, double sonic_frequency);
    void calc();
};
