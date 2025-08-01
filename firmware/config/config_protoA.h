/*
 * File: config_protoA.h
 * Description: Hardware-specific configuration for prototype A
 * Author: Phoenix Volt
 * Created: 2025-08-01
 * Last Modified: 2025-08-01 by Riccardo Canali
 * 
 * Changelog:
 * - 2025-08-01: Created config_protoA.h and defined the pinout of the Arduino Board and HW settings
 */

#ifndef CONFIG_PROTOA_H //to avoid multiple inclusions
    #define CONFIG_PROTOA_H

    //proto identifier
    #define PROTOTYPE_NAME "PROTO_A"

    //pin mapping
    //SPI
    #define CLK 13
    #define MOSI 12
    #define MISO 11
    #define CS_VOLT 10 //chip select for voltage sensor adc
    #define CS_CURR_CHRG 9 //chip select for charging current adc
    #define CS_CURR_DISCH 8 //chip select for discharging current adc
    //Mosfet
    #define GATE_DISCH 6 //gate mosfet for discharge control
    #define GATE_CHRG 5 //gate mosfet for charge control
    #define GATE_FAN 4 //gate mosfet for fans control
    //Temeperature
    #define TEMP_CELL A0 //Cell temperature
    #define TEMP_CELL_CASE A4 //Cell case temperature
    #define TEMP_RES A2 //Resistor

    //HW pararameters
    //Resistors
    #define LOAD_RES 1 //load resistance of the discharge circuit
    #define GAIN_RES 10 //gain resistance for all mosfet
    #define GS_RES 10000 // gain-source resistance for all mosfet
    #define TEMP_RES 10000 //resistance of resistor in series on the voltage devider for NTC
    #define VSENS_FILT_RES 10000 //resistance of the voltage sensing filter
    #define ISENS_DISCH_FILT_RES 470 //resistance of the discharge current sensing filter
    #define ISENS_CHRG_FILT_RES 470 //resistance of the charge current sensing filter
    //Capacitors
    #define CAP_VSENSE_PRT "B32653A4105J000" //part number of the votlage filter capacitor
    #define CAP_ISENSE_DISCH_PRT "B32653A4105J000" //part number of the discharge current filter capacitor
    #define CAP_ISENSE_CHRG_PRT "B32653A4105J000" //part number of the charge current filter capacitor
    #define VSENS_FILT_CAP 1e-6 //capacitance of the votlage sensing filter
    #define ISENS_DISCH_FILT_CAP 1e-6 //capacitance of the discharge current sensing filter
    #define ISENS_CHRG_FILT_CAP 1e-6 //capacitance of the charge current sensing filer
    //Temperature sensor
    #define NTC_PRT "B57861S0103F045" //part number of the NTC
    #define NTC_NOM_RES 10000 //nominal resistance at 25°C of the NTC sensor
    #define NTC_B25_100 3988 //Beta constante of the NTC
    #define NTC_NOM_TEMP 25.0 //nominal NTC temperature in °C
    #define NTC_TOLL_RES 0.01 //tollerance of the NTC resistance
    #define NTC_TOLL_B 0.003 //tollerance of the NTC B value
    #define NTC_VREF 5 //reference voltage of the NTC voltage devider 
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
    #define ARDUINO_ADC_BIT 12 //number of bit for Arduino ADC
    #define ARDUINO_ADC_MAX_VAL 4095.0 //maximum value for arduino ADC



#endif
