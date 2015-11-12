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
    palSetPadMode(GPIOE, GPIOE_LED4_BLUE,  PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 8,                PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOE,   GPIOE_LED4_BLUE);
    palClearPad(GPIOC,   8);
}

void switch_set_state(bool state)
{
    palWritePad(GPIOE, GPIOE_LED4_BLUE, state ? PAL_HIGH : PAL_LOW);
    palWritePad(GPIOC, 8,               state ? PAL_HIGH : PAL_LOW);
}

void switch_toggle(void)
{
    palTogglePad(GPIOE, GPIOE_LED4_BLUE);
    palTogglePad(GPIOC, 8);
}

bool switch_get_state(void)
{
    return palReadPad(GPIOE, GPIOE_LED4_BLUE) == PAL_HIGH ? true : false;
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup SWITCH */
