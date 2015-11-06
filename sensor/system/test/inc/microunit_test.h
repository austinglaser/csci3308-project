/**
 * @file    microunit_test.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Test  Interface
 */

#ifndef MICROUNIT_TEST_H
#define MICROUNIT_TEST_H

/**@addtogroup MICROUNIT
 * @{
 */

/**@defgroup MICROUNIT_TEST MicroUnit Tests
 * @{ 
 *
 * @brief
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */

/**@brief Signature of a test setup function
 *
 * The tests's setup function is generally used to do repeated initialization
 * tasks which are identical across many tests
 */
typedef void (*test_setup_f_t)(void);

/**@brief Signature of a test body function
 *
 * The test body function is generally where the bulk of the actual testing is
 * done
 */
typedef void (*test_body_f_t)(void);

/**@brief   Signature of a test teardown function
 *
 * The teardown function can clean up anything left after the test. It
 * generally does nothing unless dynamic memory is allocated which needs to be
 * freed.
 */
typedef void (*test_teardown_f_t)(void);

/**@brief   A single test case */
typedef struct {
    test_setup_f_t      setup;      /**< Set up the test case. Can be NULL if no setup is needed */
    test_body_f_t       body;       /**< Execute the test case */
    test_teardown_f_t   teardown;   /**< Tear down the test case. Can be NULL if no teardown is needed */
} microunit_test_t;

/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief Declare an array of tests
 *
 * The array will be terminated by a value which can be detected by @ref MICROUNIT_TEST_IS_ARRAY_TERM()
 */
#define MICROUNIT_TEST_ARRAY_DECLR_START(name)  static microunit_test_t name[] = {

#define MICROUNIT_TEST_IS_ARRAY_TERM(test)      (((test).setup == NULL)     && \
                                                 ((test).body == NULL)      && \
                                                 ((test).teardown == NULL)     \
                                                )

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/** @} defgroup MICROUNIT_TEST */
/** @} addtogroup MICROUNIT */

#endif /* ifndef MICROUNIT_TEST_H */
