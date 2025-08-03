/*
 * File: adc_utils.h
 * Description: ADC utility functions
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 2025-08-03 by Riccardo Canali
 * 
 * Changelog:
 * - 2025-08-03: Created adc_utils.h and defined utility functions for ADC operations
 */
#ifndef ADC_UTILS_H //to avoid multiple inclusions
    #define ADC_UTILS_H
    #include <Arduino.h> 
    #include <SPI.h> 
    #include "C:\ashborn-forge\firmware\config\config_current.h"
    
    // Enum to define ADC types
    // This enum is used to identify different ADC channels for reading various sensor values.
    enum AdcType {
    // Arduino Internal ADC
    ADC_ARDUINO_CELL_TEMP,         // reading on PIN_TEMP_CELL
    ADC_ARDUINO_CELL_VOLT,         // reading on PIN_VOLT_CELL
    ADC_ARDUINO_CELL_CASE_TEMP,    // reading on PIN_TEMP_CASE
    ADC_ARDUINO_RESISTORS_TEMP,    // reading on PIN_TEMP_RESISTORS

    // External ADC ADS1118
    ADC_CELL_VOLT,                 //reading on PIN_VOLT_CELL 
    ADC_CURR_CHRG,                 // reading on PIN_CURR_CHRG
    ADC_CURR_DISCH                 // reading on PIN_CURR_DISCH
    };
    // Function to initialize external ADCs
    void initExternalADCs();

    //reads the raw value from an ADC channel
    float readVoltageRaw(AdcType adc);

    //reads the voltage from an ADC channel, averaging over a specified number of samples
    float readVoltageAveraged(AdcType adc, uint8_t samples = 10);
#endif