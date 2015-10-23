/**
 * @file    debug.c
 * @author  Austin Glaser <austin.glaser@gmail.com>
 * @brief   Debug Source
 *
 * @addtogroup DEBUG
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "debug.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// ChibiOS
#include "ch.h"
#include "hal.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void debug_init(void)
{
#if defined(DEBUG)
    // Configuration
    static const SerialConfig debug_serial_config = {
        .speed  = 115200,
        .cr1    = 0,
        .cr2    = 0,
        .cr3    = 0
    };

    sdStart(&SD1, &debug_serial_config);

    palSetPadMode(GPIOA,  9, PAL_MODE_ALTERNATE(7));
    palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7));

#endif
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup DEBUG */
