/*
 * File: feather_hub.cpp
 * Description: Main file for the Feather Hub project, integrating various components
 * Author: Phoenix Volt
 * Created: 2025-08-04
 * Last Modified: 
 * - 2025-08-09: Removed config_protoA.h, is already included in config_current.h
 * - 2025-08-05: Commented .cpp files to avoid compilation errors
 */

// Config
#include "config/config_current.h"

// Shared
#include "shared/adc_utils.h"
#include "shared/ADS1118.h"
#include "shared/logger.h"
#include "shared/voltage_utils.h"

// Charge
#include "charge/charge.h"

// Discharge
#include "discharge/discharge.h"

// Thermal
#include "thermal/thermal.h"