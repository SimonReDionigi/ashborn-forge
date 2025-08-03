/*
 * File: voltage_utils.h
 * Description: Utility functions for reading and processing cell voltage
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 2025-08-03 by Riccardo Canali
 * 
 * Changelog:
 * - 2025-08-03: Created initial version with getCellVoltage() function
 */

#ifndef VOLTAGE_UTILS_H // Include guard to prevent multiple inclusions
    #define VOLTAGE_UTILS_H

    #include "C:\ashborn-forge\firmware\config\config_current.h"
    #include "C:\ashborn-forge\firmware\shared\adc_utils.h"

    // Number of samples to average for voltage reading
    #define CELL_VOLTAGE_SAMPLES 10

    // Reads the cell voltage in volts using the external ADC
    float getCellVoltage();

#endif
