#pragma once
#include "box.hpp"

template<typename T>
class WaveGenerator : public Box<T> {
  protected:
    double division_number = 0;
    double offset = 0;
    unsigned long counter = 0;

  public:
    WaveGenerator(double sampling_frequency, double sonic_frequency);
    virtual void calc() = 0;
};
