/**
 * @file    microunit_suite.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Test Suite  Interface
 */

#ifndef MICROUNIT_SUITE_H
#define MICROUNIT_SUITE_H

/**@addtogroup MICROUNIT
 * @{
 */

/**@defgroup MICROUNIT_SUITE MicroUnit Test Suites
 * @{ 
 *
 * @brief   Collections of tests known as 'suites'
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// Microunit submodules
#include "microunit_test.h"

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */

/**@brief   A suite of tests */
typedef struct {
    uint32_t            n_tests;    /**< Number of tests tests */
    microunit_test_t *  tests;      /**< Array of tests in the suite */
} microunint_suite_t;

/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief Declare a MicroUnit test suite
 *
 * @note    Ensure that @p tests was declared by the MicroUnit Test declaration
 *          macros
 *
 * @param[in] name:     The name of the declared object
 * @param[in] tests:    The suite's array of tests
 */
#define MICROUNIT_SUITE_DECL(name, tests)   static microunit_suite_t name = {                       \
                                                .n_tests        = MICROUNIT_ARRAY_ELEMS(tests - 1); \
                                                .tests          = tests;                            \
                                            }

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/** @} defgroup MICROUNIT_SUITE */
/** @} addtogroup MICROUNIT */

#endif /* ifndef MICROUNIT_SUITE_H */
