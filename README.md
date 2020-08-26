# Build Instructions

On Arduino IDE on MacOS

## Install the library
- Go to the Arduino library directory, for example:

```
/Users/<username>/Documents/Arduino/libraries/
```

- Clone the uTensor C++ runtime:

```
# using ssh
git clone git@github.com:uTensor/uTensor.git
```
- Checkout the right banch
```
cd uTensor
git checkout f/arduino
```

## Building the example

- Clone the example

``` 
git clone git@github.com:uTensor/utensor-arduino-demo.git
```

- Open `DigitRecognition.ino` under `utensor-arduino-demo\DigitRecognition` with Arduino IDE.

- Click on `Verify`