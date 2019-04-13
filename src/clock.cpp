#include "clock.hpp"

Clock::Clock(unsigned long frequency, function<void()> runnable) : runnable(runnable) {
  this->frequency = frequency;
}

void Clock::start() {
  this->is_started = true;
  this->th = make_unique<thread>([this](){
    while(this->is_started) {
      this->runnable();
      this_thread::sleep_for(chrono::nanoseconds((int64_t) (1.0 / this->getFrequency() * 1000000000)));
    }
  });
}

void Clock::stop() {
  this->is_started = false;
  this->th->join();
  this->th.reset();
}

bool Clock::getStatus() {
  return this->is_started;
}

unsigned long Clock::getFrequency() {
  return this->frequency;
}


