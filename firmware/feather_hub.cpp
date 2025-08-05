/*
 * File: feather_hub.cpp
 * Description: Main file for the Feather Hub project, integrating various components
 * Author: Phoenix Volt
 * Created: 2025-08-04
 * Last Modified: 
 * - 2025-08-05 by Riccardo Canali - Commented .cpp files to avoid compilation errors
 */

// Config
#include "config/config_current.h"
#include "config/config_protoA.h"

// Shared
#include "shared/adc_utils.h"
//#include "shared/adc_utils.cpp"
#include "shared/ADS1118.h"
//#include "shared/ADS1118.cpp"
#include "shared/logger.h"
#include "shared/voltage_utils.h"
//#include "shared/voltage_utils.cpp"

// Charge
#include "charge/charge.h"
//#include "charge/charge.cpp"

// Discharge
#include "discharge/discharge.h"
//#include "discharge/discharge.cpp"

// Thermal
#include "thermal/thermal.h"
//#include "thermal/thermal.cpp"