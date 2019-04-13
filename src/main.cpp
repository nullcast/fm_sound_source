#define SAMPLINGRATE 44100

#include <iostream>
#include "../inc/quantization.hpp"
#include "../inc/sin_wave_generator.hpp"
#include "../inc/clock.hpp"
#include "../inc/device.hpp"
#include "../inc/add_filter.hpp"
#include "../inc/multiplier_filter.hpp"
#include "../inc/serial_context.hpp"

using namespace std;

int main() {
  //波形生成モジュール作成
  auto s1 = make_shared<SinWaveGenerator<float>>(SAMPLINGRATE, 440);
  auto s2 = make_shared<SinWaveGenerator<float>>(SAMPLINGRATE, 220);

  //信号加算フィルタ
  vector<shared_ptr<Stream<float>>> ins(2);
  ins[0] = s1->getOutStreams()[0];
  ins[1] = s2->getOutStreams()[0];
  auto f1 = make_shared<AddFilter<float>>(ins);

  //掛け算フィルタ
  auto f2 = make_shared<MultiplierFilter<float>>(f1->getOutStreams()[0], 10000);

  //コンテキストの定義
  vector<shared_ptr<Box<float>>> boxes(4);
  boxes[0] = s1;
  boxes[1] = s2;
  boxes[2] = f1;
  boxes[3] = f2;
  SerialContext<float> context(boxes);

  //バッファの作成と初期化
  auto buffer = make_shared<Stream<BIT_16>>(SAMPLINGRATE * 5);
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
