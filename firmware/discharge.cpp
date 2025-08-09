/*
 * File: discharge.cpp
 * Description: Implementation of discharge control logic
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 
 * - 2025-08-09: Moved discharge.cpp to main directory
 * - 2025-08-03: Created discharge.cpp file
 */

#include "discharge\discharge.h"
#include "shared\adc_utils.h"
#include "shared\voltage_utils.h"
#include "config\config_current.h"

void initDischarge() {
    pinMode(PIN_GATE_DISCH, OUTPUT);
    digitalWrite(PIN_GATE_DISCH, MOS_OFF_STATE); // Ensure MOSFET is off at startup
}

void handleDischarge() {
}

float getDischargeCurrent() {
    float voltage = readVoltageAveraged(ADC_CURR_DISCH, 10); // Average reading
    float current = (voltage - CUR_SENS_DISCH_ZERO_CURR_VOLT) / CUR_SENS_DISCH_SENSITIVITY;
    return current;
}
