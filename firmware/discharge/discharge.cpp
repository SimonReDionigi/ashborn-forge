/*
 * File: discharge.cpp
 * Description: Implementation of discharge control logic
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 2025-08-03 by Riccardo Canali
 */

#include "discharge.h"
#include "C:\ashborn-forge\firmware\shared\adc_utils.h"
#include "C:\ashborn-forge\firmware\shared\voltage_utils.h"
#include "C:\ashborn-forge\firmware\config\config_current.h"

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
