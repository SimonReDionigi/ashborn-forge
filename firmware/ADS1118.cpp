/*
 * File: ADS1118.cpp
 * Description: Implementation of ADS1118 ADC driver
 * Author: Phoenix Volt
 * Created: 2025-08-04
 * Last Modified: 
 * - 20225-08-09: Added support for SPI transactions and improved error handling and moved this file to main directory
 * - 2025-08-04: Created ADS1118.cpp
 */

#include "shared/ADS1118.h"
#include <SPI.h>

ADS1118::ADS1118(uint8_t csPin, uint8_t drdyPin)
  : _csPin(csPin), _drdyPin(drdyPin)
{}

void ADS1118::begin() {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);      // CS inactive
    if (_drdyPin != 255) {
      pinMode(_drdyPin, INPUT);      // DRDY/DOUT (optional)
    }
    SPI.begin();
}

uint16_t ADS1118::buildConfig(uint8_t mux) {
    uint16_t config = 0;
    config |= (1 << 15);            // OS = 1 → start single-shot
    config |= (uint16_t(mux & 0x07) << 12);  // MUX: AINx vs GND
    config |= (0b000 << 9);         // PGA = ±6.144 V
    config |= (1 << 8);             // MODE = 1 → single-shot
    config |= (0b100 << 5);         // DR = 128 SPS
    config |= (0 << 4);             // TS_MODE = 0 → ADC input
    config |= (1 << 3);             // PULL_UP_EN = 1
    config |= (0b01 << 1);          // Bits 2:1 = 01 → valid
    config |= 1;                    // Bit 0 = 1 (reserved)
    return config;
}

int16_t ADS1118::readADC_SingleEnded(uint8_t channel) {
    if (channel > 3) return 0;

    //Select MUX for AINx–GND
    // 100,101,110,111
    uint8_t mux = 0b100 | channel; 
    uint16_t config = buildConfig(mux);
    
    SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE1));

    //Dummy conversion (clear pipeline) ———
    digitalWrite(_csPin, LOW);
      SPI.transfer16(config);
    digitalWrite(_csPin, HIGH);
    // Wait for dummy conversion
    if (_drdyPin != 255) {
      while (digitalRead(_drdyPin) == HIGH);
    } else {
      delayMicroseconds(8000);
    }
    digitalWrite(_csPin, LOW);
      SPI.transfer16(0x0000);  // dummy‐read and ignore
    digitalWrite(_csPin, HIGH);
    // ————— dummy end —————

    // Real Conversion ———
    digitalWrite(_csPin, LOW);
      SPI.transfer16(config);
    digitalWrite(_csPin, HIGH);
    // Wait for conversion to complete
    if (_drdyPin != 255) {
      while (digitalRead(_drdyPin) == HIGH);
    } else {
      delayMicroseconds(8000);
    }

    // 16 bit pilot reading: single transfer16 for 16 bits
    digitalWrite(_csPin, LOW);
      uint16_t raw = SPI.transfer16(0x0000);
    digitalWrite(_csPin, HIGH);

    SPI.endTransaction();
    return static_cast<int16_t>(raw);
}
