/*
 * File: adc_utils.cpp
 * Description: Implementation of ADC reading functions (internal Arduino ADC and external ADS1118)
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 2025-08-03 by Riccardo Canali
 */

#include "adc_utils.h"
#include <SPI.h>
#include <ADS1118.h>  // Replace with the actual library if using a specific one

// Create external ADC objects with the corresponding chip select pins
ADS1118 adc_cell(PIN_CS_VOLT);
ADS1118 adc_curr_chrg(PIN_CS_CURR_CHRG);
ADS1118 adc_curr_disch(PIN_CS_CURR_DISCH);

// Initialize SPI and external ADCs
void initExternalADCs() {
    SPI.begin();
    adc_cell.begin();
    adc_curr_chrg.begin();
    adc_curr_disch.begin();
}

// Read a single voltage value from the selected ADC
float readVoltageRaw(AdcType adc) {
    int16_t raw = 0;
    float voltage = 0.0;

    switch (adc) {
        // Internal Arduino ADCs
        case ADC_ARDUINO_CELL_TEMP:
            raw = analogRead(PIN_TEMP_CELL);
            voltage = ((float)raw / ARDUINO_ADC_MAX_VAL) * NTC_CELL_VREF;
            break;

        case ADC_ARDUINO_CELL_CASE_TEMP:
            raw = analogRead(PIN_TEMP_CELL_CASE);
            voltage = ((float)raw / ARDUINO_ADC_MAX_VAL) * NTC_CELL_CASE_VREF;
            break;

        case ADC_ARDUINO_RESISTORS_TEMP:
            raw = analogRead(PIN_TEMP_RESISTORS);
            voltage = ((float)raw / ARDUINO_ADC_MAX_VAL) * NTC_RESISTORS_VREF;
            break;

        // External ADS1118 ADCs
        case ADC_CELL_VOLT:
            raw = adc_cell.readADC_SingleEnded(0);
            voltage = ((float)raw / ADC_CELL_VOLT_MAX_VAL) * ADC_CELL_VOLT_VREF;
            break;

        case ADC_CURR_CHRG:
            raw = adc_curr_chrg.readADC_SingleEnded(0);
            voltage = ((float)raw / ADC_CURR_CHRG_MAX_VAL) * ADC_CURR_CHRG_VREF;
            break;

        case ADC_CURR_DISCH:
            raw = adc_curr_disch.readADC_SingleEnded(0);
            voltage = ((float)raw / ADC_CURR_DISCH_MAX_VAL) * ADC_CURR_DISCH_VREF;
            break;
    }

    return voltage;
}

// Read the average voltage over multiple samples from the selected ADC
float readVoltageAveraged(AdcType adc, uint8_t samples) {
    float sum = 0.0;
    for (uint8_t i = 0; i < samples; i++) {
        sum += readVoltageRaw(adc);
        delay(2);  // Small delay to stabilize readings
    }
    return sum / samples;
}
