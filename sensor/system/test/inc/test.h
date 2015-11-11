/**
 * @file    test.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Test Interface
 */

#ifndef TEST_H
#define TEST_H

/**@defgroup TEST Test
 * @{ 
 *
 * @brief   Runs all unit tests
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

/**@brief   Run all the unit test suites */
void run_tests(void);

/** @} defgroup TEST */

#endif /* ifndef TEST_H */
