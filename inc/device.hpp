#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <functional>
#include <vector>
#include <thread>
#include <memory>
#include <iostream>

#include "stream.hpp"
#include "quantization.hpp"

using namespace std;

typedef ALenum AudioEnum;

#define AUDIO_FORMAT_MONO8     AL_FORMAT_MONO8
#define AUDIO_FORMAT_MONO16    AL_FORMAT_MONO16
#define AUDIO_FORMAT_STEREO8   AL_FORMAT_STEREO8
#define AUDIO_FORMAT_STEREO16  AL_FORMAT_STEREO16

template<typename T>
class Device {
  private:
    size_t buffer_size;
    AudioEnum format;
    ALCdevice *device;
    ALCcontext *context = nullptr;
    vector<ALuint> buffers;
    vector<ALshort> store;
    ALuint source;
    shared_ptr<Stream<T>> stream;
    bool is_started;
    unique_ptr<thread> th;
    int buffer_selector = 0;

  public:
    Device(size_t buffer_size, shared_ptr<Stream<T>> stream, AudioEnum format);
    void rewrite();
    void play();
    void stop();
    ~Device();
};
