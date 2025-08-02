/*
 * File: config_current.h
 * Description: Selects which prototype configuration is currently active.
 * Author: Phoenix Volt
 * Created: 2025-08-01
 * Last Modified: 2025-08-01 by Riccardo Canali
 *
 * Changelog:
 * - 2025-08-01: Included config_protoA.h as the active configuration.
 */

// Include the active configuration
#include "config_protoA.h"
// Ensure that a prototype configuration is defined
#ifndef PROTOTYPE_NAME
    #error "No prototype configuration selected! Check config_current.h."
#endif
