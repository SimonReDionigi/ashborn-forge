/*
 * File: thermal.h
 * Description: Utilities for temperature acquisition and conversion using NTC thermistors
 * Author: Phoenix Volt
 * Created: 2025-08-03
 */

#ifndef THERMAL_H // Include guard to prevent multiple inclusions
    #define THERMAL_H

    #include <Arduino.h>
    #include "C:\ashborn-forge\firmware\config\config_current.h"
    #include "C:\ashborn-forge\firmware\shared/adc_utils.h"

    // Enum for identifying different NTC sensors
    typedef enum {
        TEMP_CELL,
        TEMP_CELL_CASE,
        TEMP_RESISTORS
    } TempSensorType;

    // Returns temperature in °C from the specified NTC sensor
    float readTemperatureC(TempSensorType sensor);

    // Returns the averaged temperature over N samples
    float readTemperatureCAveraged(TempSensorType sensor, uint8_t samples = 5);

#endif  
