#include "device.hpp"

const size_t BUFFER_NUM = 2;
const size_t SOURCE_NUM = 1;

template<typename T>
Device<T>::Device(size_t buffer_size, shared_ptr<Stream<T>> stream, AudioEnum format): 
    buffer_size(buffer_size),
    format(format),
    device(alcOpenDevice(NULL)),
    buffers(BUFFER_NUM),
    store(buffer_size),
    stream(stream) {
  this->context = alcCreateContext(this->device, NULL);
  alcMakeContextCurrent(this->context);

  ALuint *data = this->buffers.data();
  alGenBuffers(BUFFER_NUM, data);
  alGenSources(SOURCE_NUM, &(this->source));
}

template<typename T>
void Device<T>::play() {
  this->is_started = true;
  this->th = make_unique<thread>([this](){
    ALshort *data = this->store.data();
    
    this->rewrite();
    
    alBufferData(this->buffers[this->buffer_selector], this->format, data, this->store.size() * sizeof(ALshort), this->buffer_size);
    alSourceQueueBuffers(this->source, 1, &(this->buffers[this->buffer_selector]));
    alSourcePlay(this->source);

    this->rewrite();
    alBufferData(this->buffers[this->buffer_selector ^ 1], this->format, data, this->store.size() * sizeof(ALshort), this->buffer_size);
    alSourceQueueBuffers(this->source, 1, &(this->buffers[this->buffer_selector ^ 1]));

    ALint state;
    while(this->is_started) {
      alGetSourcei(this->source, AL_BUFFERS_PROCESSED, &state);
      if (state == 1) {
        alSourceUnqueueBuffers(this->source, 1, &(this->buffers[this->buffer_selector]));

        this->rewrite();
        data = this->store.data();
        alBufferData(this->buffers[this->buffer_selector], this->format, data, this->store.size() * sizeof(ALshort), this->buffer_size);
        alSourceQueueBuffers(this->source, 1, &(this->buffers[this->buffer_selector]));
        this->buffer_selector = this->buffer_selector ^ 1;
      }
    }
  });
}

template<typename T>
void Device<T>::stop() {
  this->is_started = false;
  this->th->join();
  this->th.reset();
}

template<typename T>
void Device<T>::rewrite() {
  for (unsigned long int i = 0; i < this->buffer_size; i++) {
    this->store[i] = this->stream->read();
  }
}

template<typename T>
Device<T>::~Device() {
	alDeleteBuffers(BUFFER_NUM, &(this->buffers[0]));
	alDeleteSources(SOURCE_NUM, &(this->source));

	alcMakeContextCurrent(NULL);
	alcDestroyContext(this->context);
  
	alcCloseDevice(this->device);
}

template Device<BIT_16>::Device(size_t buffer_size, shared_ptr<Stream<BIT_16>> stream, AudioEnum format);
template void Device<BIT_16>::play();
template void Device<BIT_16>::stop();
template void Device<BIT_16>::rewrite();
template Device<BIT_16>::~Device();
