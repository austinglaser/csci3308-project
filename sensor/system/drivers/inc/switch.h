/**
 * @file    switch.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Power Switch Driver Interface
 */

#ifndef SWITCH_H
#define SWITCH_H

/**@defgroup SWITCH Power Switch Driver
 * @{ 
 *
 * @brief   Controls the attached power switch
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Initializes the switch driver */
void switch_init(void);

/**@brief   Control the switch's state
 *
 * @param[in] state:    The state to set. true turns on, false turns off
 */
void switch_set_state(bool state);

/**@briedf  Toggle the switch's state */
void switch_toggle(void);

/**@brief   Get the switch's current state
 *
 * @return              true if the switch is on, false if it's off
 */
bool switch_get_state(void);

/** @} defgroup SWITCH */

#endif /* ifndef SWITCH_H */
