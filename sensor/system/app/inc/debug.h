/**
 * @file    debug.h
 * @author  Austin Glaser <austin.glaser@gmail.com>
 * @brief   Debug Interface
 */

#ifndef DEBUG_H
#define DEBUG_H

/**@defgroup DEBUG Debug Console
 * @{ 
 *
 * @brief
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// ChibiOS
#include "ch.h"
#include "hal.h"
#include "chprintf.h"

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */

#if defined(DEBUG) || defined(__DOXYGEN__)

    /**
     * @brief   Print a formatted message to the debug port
     *
     * Syntax a subset of printf.
     *
     * @see chprintf
     */
    #define DEBUG_PRINTF(format, ...)   chprintf((BaseSequentialStream*) &SD1, format, ##__VA_ARGS__)

#else

    #define DEBUG_PRINTF(...)           ((void) 0)

#endif

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**
 * @brief   Initializes the debug port
 */
void debug_init(void);

/** @} defgroup DEBUG */

#endif /* ifndef DEBUG_H */
