#include <stdio.h>

#include <cmath>

#include "input_image.h"  //contains the first sample taken from the MNIST test set
#include "src/models/my_model/my_model.hpp"  //gernerated model file"
#include "uTensor.h"

using namespace uTensor;

int argmax(const Tensor &logits) {
  uint32_t num_elems = logits->num_elems();
  float max_value = static_cast<float>(logits(0));
  int max_index = 0;
  for (int i = 1; i < num_elems; ++i) {
    float value = static_cast<float>(logits(i));
    if (value >= max_value) {
      max_value = value;
      max_index = i;
    }
  }
  return max_index;
}

static My_model model;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Simple MNIST end-to-end uTensor cli example (device)");

  // create the input/output tensor
  Tensor input_image = new RomTensor({1, 28, 28, 1}, flt, arr_input_image);
  Tensor logits = new RamTensor({1, 10}, flt);

  model.set_inputs({{My_model::input_0, input_image}})
      .set_outputs({{My_model::output_0, logits}})
      .eval();

  int max_index = argmax(logits);
  input_image.free();
  logits.free();

  Serial.printf("pred label: %d\r\n", max_index);

  
}

void loop() {
  
}
