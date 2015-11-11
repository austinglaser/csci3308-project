/**
 * @file    switch_test.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Power Switch Driver Test Interface
 */

#ifndef SWITCH_TEST_H
#define SWITCH_TEST_H

/**@addtogroup TEST
 * @{
 */

/**@defgroup SWITCH_TEST Power Switch Driver Test
 * @{ 
 *
 * @brief   Tests the software side of the power-switch driver
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// Test framework
#include "microunit.h"

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Get the switch test suite
 *
 * @return      A reference to the test suite
 */
microunit_suite_t * switch_test(void);

/** @} defgroup SWITCH_TEST */
/** @} addtogrooup TEST */

#endif /* ifndef SWITCH_TEST_H */
