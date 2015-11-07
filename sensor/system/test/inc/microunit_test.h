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

// Microunit
#include "microunit.h"

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
    const char *        name;       /**< The test's name */
    test_setup_f_t      setup;      /**< Set up the test case. Can be NULL if no setup is needed */
    test_body_f_t       body;       /**< Execute the test case */
    test_teardown_f_t   teardown;   /**< Tear down the test case. Can be NULL if no teardown is needed */
} microunit_test_t;

/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief   Declare an array of tests
 *
 * The array will be terminated by a value which can be detected by @ref MICROUNIT_TEST_IS_ARRAY_TERM()
 *
 * @param[in] name:     The name of the declared array
 */
#define MICROUNIT_TEST_ARRAY_START(name)        static microunit_test_t name[] = {

/**@brief   Add a test to an array of tests
 *
 * Uses the test body function as a name to identify the test
 *
 * @param[in] setup:    The test's setup function
 * @param[in] body:     The test's body function
 * @param[in] teardown: The test's teardown function
 */
#define MICROUNIT_TEST(setup, body, teardown)       {                          \
                                                        .name = #body,         \
                                                        .setup = (setup),      \
                                                        .body = (body),        \
                                                        .teardown = (teardown) \
                                                    },

/**@brief   Close out an array of tests */
#define MICROUNIT_TEST_ARRAY_END()                  {                    \
                                                        .name = NULL,    \
                                                        .setup = NULL,   \
                                                        .body = NULL,    \
                                                        .teardown = NULL \
                                                    }                    \
                                                }

/**@brief   Determine whether an element in a test array is the array terminator
 * 
 * @param[in] test:     The test structure to check
 */
#define MICROUNIT_TEST_IS_ARRAY_TERM(test)      (((test).setup == NULL)     && \
                                                 ((test).body == NULL)      && \
                                                 ((test).teardown == NULL))

/**@brief   Assert @condition evaluates to logical true
 *
 * @param[in] condition:    The condition to be verified
 */
#define microunit_assert(condition)                         do {                                                       \
                                                                if (!(condition)) {                                    \
                                                                    microunit_test_fail(MICROUNIT_AT ": " #condition); \
                                                                }                                                      \
                                                            } while (0)

/**@brief   Assert @condition evaluates to logical true
 *
 * @param[in] condition:    The condition to be verified
 * @param[in] message:      Message describing the failure
 */
#define microunit_assert_msg(condition, message)            do {                                                     \
                                                                if (!(condition)) {                                  \
                                                                    microunit_test_fail(MICROUNIT_AT ": "  message); \
                                                                }                                                    \
                                                            } while (0)

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Run @p test and report the results
 *
 * @param[in] test:     The test to run
 */
void microunit_run_test(microunit_test_t * test);

/**@brief   Causes a test to fail with @p message
 *
 * Must ONLY be called from within a running microunit test
 *
 * Does not need to be called from the test's top level (i.e. can be called
 * within nested functions)
 *
 * @param[in] message:  The message describing the failure
 */
void microunit_test_fail(const char * message);

/** @} defgroup MICROUNIT_TEST */
/** @} addtogroup MICROUNIT */

#endif /* ifndef MICROUNIT_TEST_H */
