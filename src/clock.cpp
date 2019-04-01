#include "clock.hpp"

Clock::Clock(unsigned long frequency, function<void()> runnable) : runnable(runnable) {
  this->frequency = frequency;
}

void Clock::start() {
  isStarted = true;
  th = make_unique<thread>([=](){
    while(isStarted) {
      runnable();
      this_thread::sleep_for(chrono::nanoseconds((int64_t) (1.0 / getFrequency() * 1000000000)));
    }
  });
}

void Clock::stop() {
  isStarted = false;
  th->join();
  th.reset();
}

bool Clock::getStatus() {
  return isStarted;
}

unsigned long Clock::getFrequency() {
  return frequency;
}


