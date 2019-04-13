#define SAMPLINGRATE 44100

#include <iostream>
#include "../inc/quantization.hpp"
#include "../inc/sin_wave_generator.hpp"
#include "../inc/clock.hpp"
#include "../inc/device.hpp"
#include "../inc/add_filter.hpp"
#include "../inc/serial_context.hpp"

using namespace std;

int main() {
  //波形生成モジュール作成
  shared_ptr<SinWaveGenerator<BIT_16>> s1 = make_shared<SinWaveGenerator<BIT_16>>(SAMPLINGRATE, 440);
  shared_ptr<SinWaveGenerator<BIT_16>> s2 = make_shared<SinWaveGenerator<BIT_16>>(SAMPLINGRATE, 850);

  //信号加算フィルタ
  vector<shared_ptr<Stream<BIT_16>>> ins(2);
  ins[0] = s1->getOutStreams()[0];
  ins[1] = s2->getOutStreams()[0];
  shared_ptr<AddFilter<BIT_16>> f = make_shared<AddFilter<BIT_16>>(ins);

  //コンテキストの定義
  vector<shared_ptr<Box<BIT_16>>> boxes(3);
  boxes[0] = s1;
  boxes[1] = s2;
  boxes[2] = f;
  SerialContext<BIT_16> context(boxes);

  //バッファの作成と初期化
  shared_ptr<Stream<BIT_16>> buffer = make_shared<Stream<BIT_16>>(SAMPLINGRATE * 5);
  for(int i = 0; i < SAMPLINGRATE * 5; i++) {
    context.calc();
    buffer->write(context.getOutStreams()[0]->read());
  }

  //デバイスの定義
  Device d(SAMPLINGRATE, buffer, AL_FORMAT_MONO16);

  //クロックの定義（サンプリングレートでコールされる）
  Clock c((unsigned long)SAMPLINGRATE, [&]() {
    context.calc();
    buffer->write(context.getOutStreams()[0]->read());
  });

  //クロックのスタートとデバイスの再生
  c.start();
  d.play();
  
  while(true);

  return 0;
}
