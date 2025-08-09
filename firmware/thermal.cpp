/*
 * File: thermal.cpp
 * Description: Implementation of NTC temperature reading and conversion
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified:
 * - 2025-08-09: Moved this file to main directory
 */

#include "thermal\thermal.h"

// Converts NTC voltage to temperature using the Beta formula
float convertNTCVoltageToTemp(float v_ntc, float v_ref, float beta, float r_fixed, float r_nominal, float t_nominal) {
    if (v_ntc <= 0 || v_ntc >= v_ref) {
        return -273.15; // Invalid voltage, return absolute zero as error
    }

    float r_ntc = (v_ntc * r_fixed) / (v_ref - v_ntc);
    float temp_k = 1.0 / ((1.0 / (t_nominal + 273.15)) + (1.0 / beta) * log(r_ntc / r_nominal));
    return temp_k - 273.15;
}

float readTemperatureC(TempSensorType sensor) {
    float v_ntc = 0;
    float v_ref = 5.0;
    float beta = 3988;
    float r_fixed = TEMP_RES;
    float r_nominal = 10000;
    float t_nominal = 25.0;

    switch (sensor) {
        case TEMP_CELL:
            v_ntc = readVoltageRaw(ADC_ARDUINO_CELL_TEMP);
            v_ref = NTC_CELL_VREF;
            beta = NTC_CELL_B25_100;
            r_nominal = NTC_CELL_NOM_RES;
            t_nominal = NTC_CELL_NOM_TEMP;
            break;

        case TEMP_CELL_CASE:
            v_ntc = readVoltageRaw(ADC_ARDUINO_CELL_CASE_TEMP);
            v_ref = NTC_CELL_CASE_VREF;
            beta = NTC_CELL_CASE_B25_100;
            r_nominal = NTC_CELL_CASE_NOM_RES;
            t_nominal = NTC_CELL_CASE_NOM_TEMP;
            break;

        case TEMP_RESISTORS:
            v_ntc = readVoltageRaw(ADC_ARDUINO_RESISTORS_TEMP);
            v_ref = NTC_RESISTORS_VREF;
            beta = NTC_RESISTORS_B25_100;
            r_nominal = NTC_RESISTORS_NOM_RES;
            t_nominal = NTC_RESISTORS_NOM_TEMP;
            break;

        default:
            return -273.15; // Invalid sensor
    }

    return convertNTCVoltageToTemp(v_ntc, v_ref, beta, r_fixed, r_nominal, t_nominal);
}

float readTemperatureCAveraged(TempSensorType sensor, uint8_t samples) {
    float total = 0;
    for (uint8_t i = 0; i < samples; i++) {
        total += readTemperatureC(sensor);
        delay(10); // small delay for stability
    }
    return total / samples;
}
