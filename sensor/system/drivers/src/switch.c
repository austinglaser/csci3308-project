/**
 * @file    switch.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Power Switch Driver Source
 *
 * @addtogroup SWITCH
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "switch.h"

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

void switch_init(void)
{
    palClearPad(GPIOC, 8);
    palSetPadMode(GPIOC,  8, PAL_MODE_OUTPUT_PUSHPULL);
}

void switch_set_state(bool state)
{
    palWritePad(GPIOC, 8, state);
}

bool switch_get_state(void)
{
    return palReadPad(GPIOC, 8);
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup SWITCH */
