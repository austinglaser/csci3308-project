/**
 * @file    microunit_port.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit System Port Source
 *
 * @addtogroup MICROUNIT_PORT
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// Microunit
#include "microunit.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// ChibiOS
#include "ch.h"
#include "hal.h"

// Application
#include "debug.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void microunit_internal_assertion_failure(const char * message)
{
    chSysHalt(message);
}

void microunit_print_string(const char * string)
{
    DEBUG_PRINTF("%s", string);
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup MICROUNIT_PORT */
