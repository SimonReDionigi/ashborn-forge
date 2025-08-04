/*
 * File: ADS1118.cpp
 * Description: Implementation of ADS1118 ADC driver
 * Author: Phoenix Volt
 * Created: 2025-08-04
 * Last Modified: 2025-08-04 by Riccardo Canali
 */

#include "ADS1118.h"

ADS1118::ADS1118(uint8_t csPin) {
    _csPin = csPin;
}

void ADS1118::begin() {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
}

uint16_t ADS1118::buildConfig(uint8_t mux) {
    uint16_t config = 0;

    config |= (1 << 15);               // Start single conversion
    config |= (mux & 0x07) << 12;      // Input multiplexer configuration
    config |= (0b001 << 9);            // PGA: ±4.096V
    config |= (1 << 8);                // Mode: Single-shot
    config |= (0b100 << 5);            // Data rate: 128 SPS
    config |= (0b00 << 2);             // Disable temperature sensor
    config |= 0b11;                    // Pull-up disable, no burnout current

    return config;
}

void ADS1118::writeConfig(uint16_t config) {
    digitalWrite(_csPin, LOW);
    SPI.transfer16(config);
    digitalWrite(_csPin, HIGH);
}

int16_t ADS1118::readData() {
    digitalWrite(_csPin, LOW);
    uint16_t result = SPI.transfer16(0x0000);  // Dummy write to receive data
    digitalWrite(_csPin, HIGH);
    return static_cast<int16_t>(result);
}

int16_t ADS1118::readADC_SingleEnded(uint8_t channel) {
    if (channel > 3) return 0;  // Only 4 channels: AIN0–AIN3

    uint8_t mux = 0;
    switch (channel) {
        case 0: mux = 0b100; break; // AIN0-GND
        case 1: mux = 0b101; break; // AIN1-GND
        case 2: mux = 0b110; break; // AIN2-GND
        case 3: mux = 0b111; break; // AIN3-GND
    }

    uint16_t config = buildConfig(mux);
    writeConfig(config);
    delay(10);  // Wait for conversion to complete
    return readData();
}
