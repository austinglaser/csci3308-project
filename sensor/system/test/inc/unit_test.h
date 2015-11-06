/**
 * @file    unit_test.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Unit Test Object Interface
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

/**@defgroup UNIT_TEST Unit Test Framework
 * @{ 
 *
 * @brief
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Test framework components
#include <test.h>
#include <stdbool.h>

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */

/**@brief   Signature of a test function */
typedef void (* test_body_f_t)(void);

/**@brief   Signature of a function to set up a test */
typedef void (* test_setup_f_t)(void);

/**@brief   Signature of a function to tear down a test */
typedef void (* test_teardown_f_t)(void);

/**@brief   A test
 *
 * @note    Always declare with the declaration macros
 */
typedef struct {
    const char *        name;           /**< The test's name */
    test_body_f_t       body;           /**< The body of the test */
    test_setup_f_t      setup;          /**< Test setup */
    test_teardown_f_t   teardown;       /**< Test teardown */
} test_t;

/* --- PUBLIC MACROS -------------------------------------------------------- */

#define UNIT_TEST_DECLARATION(name, body, setup, teardown)  static const test_t name

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/** @} defgroup UNIT_TEST */

#endif /* ifndef UNIT_TEST_H */
