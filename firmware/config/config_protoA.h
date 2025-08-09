/*
 * File: config_protoA.h
 * Description: Hardware-specific configuration for prototype A
 * Author: Phoenix Volt
 * Created: 2025-08-01
 * Last Modified: 2025-08-01 by Riccardo Canali
 * 
 * Changelog:
 * - 2025-08-09: Updated ADC configurations
 * - 2025-08-02: Added configuration for each NTC sensors and ADCs
 * - 2025-08-01: Created config_protoA.h and defined the pinout of the Arduino Board and HW settings
 */

#ifndef CONFIG_PROTOA_H //to avoid multiple inclusions
    #define CONFIG_PROTOA_H

    //proto identifier
    #define PROTOTYPE_NAME "PROTO_A"

    //pin mapping
    //SPI
    #define PIN_CLK 13
    #define PIN_MISO 12
    #define PIN_MOSI 11
    #define PIN_CS_VOLT 10 //chip select for voltage sensor adc
    #define PIN_CS_CURR_CHRG 9 //chip select for charging current adc
    #define PIN_CS_CURR_DISCH 8 //chip select for discharging current adc
    //Mosfet
    #define PIN_GATE_DISCH 6 //gate mosfet for discharge control
    #define PIN_GATE_CHRG 5 //gate mosfet for charge control
    #define PIN_GATE_FAN 4 //gate mosfet for fans control
    //Temperature
    #define PIN_TEMP_CELL A0 //Cell temperature
    #define PIN_TEMP_CELL_CASE A3 //Cell case temperature
    #define PIN_TEMP_RESISTORS A2 //resistors temperature

    //HW parameters
    //Resistors
    #define LOAD_RES 1 //load resistance of the discharge circuit
    #define GAIN_RES 10 //gain resistance for all mosfet
    #define GS_RES 10000 // gain-source resistance for all mosfet
    #define TEMP_RES 10000 //resistance of resistor in series on the voltage divider for NTC
    #define VSENS_FILT_RES 10000 //resistance of the voltage sensing filter
    #define ISENS_DISCH_FILT_RES 470 //resistance of the discharge current sensing filter
    #define ISENS_CHRG_FILT_RES 470 //resistance of the charge current sensing filter
    //Capacitors
    #define CAP_VSENSE_PRT "B32653A4105J000" //part number of the voltage filter capacitor
    #define CAP_ISENSE_DISCH_PRT "B32653A4105J000" //part number of the discharge current filter capacitor
    #define CAP_ISENSE_CHRG_PRT "B32653A4105J000" //part number of the charge current filter capacitor
    #define CAP_VSENS_FILT 1e-6 //capacitance of the voltage sensing filter
    #define CAP_ISENS_DISCH_FILT 1e-6 //capacitance of the discharge current sensing filter
    #define CAP_ISENS_CHRG_FILT 1e-6 //capacitance of the charge current sensing filter
    //Temperature sensor
    #define NTC_CELL_PRT         "B57861S0103F045" // Part number for cell temperature NTC
    #define NTC_CELL_CASE_PRT    "B57861S0103F045" // Part number for cell case temperature NTC
    #define NTC_RESISTORS_PRT    "B57861S0103F045" // Part number for resistors temperature NTC
    #define NTC_CELL_NOM_RES         10000 // Nominal resistance for cell temperature NTC
    #define NTC_CELL_CASE_NOM_RES    10000 // Nominal resistance for cell case temperature NTC
    #define NTC_RESISTORS_NOM_RES    10000 // Nominal resistance for resistors temperature NTC
    #define NTC_CELL_B25_100         3988 // Beta constant for cell temperature NTC
    #define NTC_CELL_CASE_B25_100    3988 // Beta constant for cell case temperature NTC
    #define NTC_RESISTORS_B25_100    3988 // Beta constant for resistors temperature NTC
    #define NTC_CELL_NOM_TEMP         25.0 // Nominal temperature for cell temperature NTC
    #define NTC_CELL_CASE_NOM_TEMP    25.0 // Nominal temperature for cell case temperature NTC
    #define NTC_RESISTORS_NOM_TEMP    25.0 // Nominal temperature for resistors temperature NTC
    #define NTC_CELL_TOLL_RES         0.01 // Resistance tolerance for cell temperature NTC
    #define NTC_CELL_CASE_TOLL_RES    0.01 // Resistance tolerance for cell case temperature NTC
    #define NTC_RESISTORS_TOLL_RES    0.01 // Resistance tolerance for resistors temperature NTC
    #define NTC_CELL_TOLL_B         0.003 // Beta tolerance for cell temperature NTC
    #define NTC_CELL_CASE_TOLL_B    0.003 // Beta tolerance for cell case temperature NTC
    #define NTC_RESISTORS_TOLL_B    0.003 // Beta tolerance for resistors temperature NTC
    #define NTC_CELL_VREF 5.0 //Voltage reference for cell temperature NTC
    #define NTC_CELL_CASE_VREF 5.0 //Voltage reference for cell case temperature NTC
    #define NTC_RESISTORS_VREF 5.0 //Voltage reference for resistors temperature NTC

    //Mosfet
    #define MOS_DISCH_PRT "IRF3205PBF" //Discharge Mosfet Part Number
    #define MOS_CHRG_PRT "IRF3205PBF" //Charge Mosfet Part Number
    #define MOS_FAN_PRT "IRF3205PBF" //Fans Mosfet Part Number
    #define MOS_ON_STATE HIGH //Mosfet ON state
    #define MOS_OFF_STATE LOW //Mosfet OFF state
    #define MOS_DISCH_RES 8e-3 //Discharge Mosfet internal resistance
    #define MOS_CHRG_RES 8e-3 //Charge Mosfet internal resistance
    #define MOS_FAN_RES 8e-3 //Fans Mosfet internal resistance
    #define MOS_DISCH_MAX_CUR 110 //Discharge Mosfet max current
    #define MOS_CHRG_MAX_CUR 110 //Charge Mosfet max current
    #define MOS_FAN_MAX_CUR 110 //Fans Mosfet max current
    //current sensor
    #define CUR_SENS_DISCH_PRT "AC7612-30A" //discharge current sensor part number
    #define CUR_SENS_CHRG_PRT "AC7612-30A" //Charge current sensor part number
    #define CUR_SENS_DISCH_SENSITIVITY 0.066 //Discharge current sensor sensitivity in V/A
    #define CUR_SENS_CHRG_SENSITIVITY 0.066 //Charge current sensor sensitivity in V/A
    #define CUR_SENS_DISCH_ZERO_CURR_VOLT 2.5 //Discharge current sensor voltage at zero current [V]
    #define CUR_SENS_CHRG_ZERO_CURR_VOLT 2.5 //Charge current sensor voltage at zero current [V]
    #define CUR_SENS_DISCH_VREF 5 //Discharge current sensor voltage reference
    #define CUR_SENS_CHRG_VREF 5 //Discharge current sensor voltage reference
    //adc
    #define ARDUINO_ADC_BIT 10 //number of bits for Arduino ADC
    #define ARDUINO_ADC_MAX_VAL 1023 //maximum value for arduino ADC
    #define ADC_CELL_VOLT_PRT      "ADS1118" // External ADC part number for cell voltage
    #define ADC_CURR_CHRG_PRT      "ADS1118" // External ADC part number for charge current
    #define ADC_CURR_DISCH_PRT     "ADS1118" // External ADC part number for discharge current
    #define ADC_CELL_VOLT_BIT      16 // Number of bits for cell voltage ADC
    #define ADC_CURR_CHRG_BIT      16 // Number of bits for charge current ADC
    #define ADC_CURR_DISCH_BIT     16 // Number of bits for discharge current ADC
    #define ADC_CELL_VOLT_MAX_VAL      32768 // Maximum value for cell voltage ADC
    #define ADC_CURR_CHRG_MAX_VAL      32768 // Maximum value for charge current ADC
    #define ADC_CURR_DISCH_MAX_VAL     32768 // Maximum value for discharge current ADC
    #define ADC_CELL_VOLT_VREF      6.144 // Reference voltage for cell voltage ADC
    #define ADC_CURR_CHRG_VREF      6.144 // Reference voltage for charge current ADC
    #define ADC_CURR_DISCH_VREF     6.144 // Reference voltage for discharge current ADC
    #define ADC_CELL_VOLT_GAIN      1 // Gain for cell voltage ADC
    #define ADC_CURR_CHRG_GAIN      1 // Gain for charge current ADC
    #define ADC_CURR_DISCH_GAIN     1 // Gain for discharge current ADC

#endif
