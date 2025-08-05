/*
 * File: firmware.ino
 * Description: Arduino firmware main file
 * Author: Phoenix Volt
 * Created: 2025-08-04
 * Last Modified: 2025-08-04 by Riccardo Canali
 * 
 * Changelog:
 * - 2025-08-04: Created firmware.ino and implemented basic ADC reading functionality
 */
#include "feather_hub.cpp"


void setup() {
    Serial.begin(115200);
    initExternalADCs(); // Initialize external ADCs
}

void loop() {
    // Read cell voltage using external ADC (ADS1118)
    float cell_voltage = getCellVoltage(); // Implemented in voltage_utils.h

    // Read temperatures using Arduino ADC channels
    float temp_cell = readTemperatureC(TEMP_CELL);         // read cell temperature
    float temp_cell_case = readTemperatureC(TEMP_CELL_CASE); // read cell case temperature
    float temp_resistors = readTemperatureC(TEMP_RESISTORS); // read resistors temperature

    // Print results
    Serial.print("Cell Voltage: ");
    Serial.print(cell_voltage, 3);
    Serial.println(" V");

    Serial.print("Cell Temp: ");
    Serial.print(temp_cell, 2);
    Serial.println(" C");

    Serial.print("Cell Case Temp: ");
    Serial.print(temp_cell_case, 2);
    Serial.println(" C");

    Serial.print("Resistors Temp: ");
    Serial.print(temp_resistors, 2);
    Serial.println(" C");

    Serial.println("----------------------");
    delay(1000);
}