# A Mongoose OS firmware for C/C++ interface of CCS811 sensor and BME280 sensor

## Overview

This App serves to read data of CCS811 gas sensor and BME280 temperature sensor on TTGO T-CALL using Mongoose OS and runs to display both values using I2C Protocol. The I2C pins are defined here as GPIO 21 - SDA and GPIO 22 - SCL of TTGO T-Call board.
https://github.com/Xinyuan-LilyGO/TTGO-T-Call

There is an demo app, serves as a skeleton for building Mongoose OS
apps from scratch in C/C++. It implements the same functionality
as [demo-js](https://github.com/mongoose-os-apps/demo-js) does, but
uses C/C++ instead of JavaScript.

See [Mongoose OS C/C++ quickstart](https://mongoose-os.com/docs/mongoose-os/quickstart/develop-in-c.md) for
the C/C++ development introduction.
