/*
 * File: discharge.h
 * Description: Functions related to battery discharge control
 * Author: Phoenix Volt
 * Created: 2025-08-03
 * Last Modified: 2025-08-03 by Riccardo Canali
 */

#ifndef DISCHARGE_H // Header guard to prevent multiple inclusions
    #define DISCHARGE_H

    #include "../Shared/adc_utils.h"
    #include "../Shared/debug_utils.h"
    #include "../Shared/voltage_utils.h"
    #include "../Config/config_protoA.h"

    // Initializes discharge process
    void initDischarge();

    // Manages the discharge loop (to be called in loop)
    void handleDischarge();

    // Returns the current flowing during discharge [A]
    float getDischargeCurrent();

#endif
