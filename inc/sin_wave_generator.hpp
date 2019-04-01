#pragma once
#include <cmath>
#include "wave_generator.hpp"

using namespace std;

template<typename T>
class SinWaveGenerator : public WaveGenerator<T> {
  public:
    SinWaveGenerator(double sampling_frequency, double sonic_frequency);
    void calc();
};
