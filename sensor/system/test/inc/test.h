/**
 * @file    test.h
 * @author  Austin Glaser <austin.glaser@gmail.com>
 * @brief   Test Interface
 */

#ifndef TEST_H
#define TEST_H

/**@defgroup TEST Test
 * @{ 
 *
 * @brief   Runs a system self-test
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

/**
 * @brief   Tests the system
 *
 * Assumes subsystems have been initialized
 */
void test(void);

/** @} defgroup TEST */

#endif /* ifndef TEST_H */
