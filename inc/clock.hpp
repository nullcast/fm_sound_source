#include <functional>
#include <thread>
#include <memory>

using namespace std;

class Clock {
  private:
    unsigned long frequency;
    bool is_started;
    function<void()> runnable;
    unique_ptr<thread> th;

  public:
    Clock(unsigned long frequency, function<void()> runnable);
    void start();
    void stop();
    bool getStatus();
    unsigned long getFrequency();
};
