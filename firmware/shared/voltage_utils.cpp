/*
 * File: voltage_utils.cpp
 * Description: Implementation of utility functions for cell voltage reading
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 2025-08-03 by Riccardo Canali
 * 
 * Changelog:
 * - 2025-08-03: Implemented getCellVoltage() with averaging
 */

#include "voltage_utils.h"

// Returns the averaged cell voltage using the external ADC
float getCellVoltage() {
    return readVoltageAveraged(ADC_CELL_VOLT, CELL_VOLTAGE_SAMPLES);
}
