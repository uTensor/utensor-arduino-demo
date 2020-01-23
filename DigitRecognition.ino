#include <uTensor.h>

#include "deep_mlp.hpp"  //gernerated model file
#include "input_data.h"  //contains the first sample taken from the MNIST test set

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Simple MNIST end-to-end uTensor cli example (device)");

  Context ctx;  //creating the context class, the stage where inferences take place
  //wrapping the input data in a tensor class
  Tensor* input_x = new WrappedRamTensor<float>({1, 784}, (float*) input_data);

  get_deep_mlp_ctx(ctx, input_x);  // pass the tensor to the context
  S_TENSOR pred_tensor = ctx.get("y_pred:0");  // getting a reference to the output tensor
  ctx.eval(); //trigger the inference

  int pred_label = *(pred_tensor->read<int>(0, 0));  //getting the result back
  Serial.print("Predicted label: ");
  Serial.println(pred_label);
}

void loop() {

}
