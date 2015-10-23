/**
 * @file    main.c
 * @author  Austin Glaser <austin.glaser@gmail.com>
 * @brief   Application Entry Point
 *
 * @defgroup MAIN Main
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// Chibios
#include "ch.h"
#include "hal.h"

// Application
#include "debug.h"

#if defined(TEST)
#include "test.h"
#endif

/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**
 * @brief   Application entry point
 */
int main(void) {

    // Chibios init
    halInit();
    chSysInit();

    // Application init
    debug_init();

#if defined(TEST)
    // Self-test
    test();
#endif

    while (true) chThdSleep(TIME_INFINITE);
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} defgroup MAIN */
