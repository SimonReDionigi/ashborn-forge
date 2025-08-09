/*
 * File: ADS1118.H
 * Description: Header file for ADS1118 ADC driver
 * Author: Phoenix Volt
 * Created: 2025-08-04
 * Last Modified: 
 * - 2025-08-09: Updated to include optional DRDY pin
 * - 2025-08-04 Createde ADS1118.h
 */
#ifndef ADS1118_H
    #define ADS1118_H

    #include <Arduino.h>
    #include <SPI.h>

    class ADS1118 {
    public:
        ADS1118(uint8_t csPin, uint8_t drdyPin); // Optional DRDY pin
        void begin();
        int16_t readADC_SingleEnded(uint8_t channel);

    private:
        uint8_t _csPin;
        uint8_t _drdyPin
        uint16_t buildConfig(uint8_t mux);
        void writeConfig(uint16_t config);
        int16_t readData();
    };

#endif
