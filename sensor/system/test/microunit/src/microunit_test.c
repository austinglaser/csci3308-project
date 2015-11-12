/**
 * @file    microunit_test.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Test Source
 *
 * @addtogroup MICROUNIT
 * @{
 *
 * @addtogroup MICROUNIT_TEST
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "microunit.h"

// Standard
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */

/**@brief   Maximum length of an assertion message */
#define MICROUNIT_TEST_MESSAGE_LEN          (128U)

/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */

/**@brief   Prints the test's name and result
 *
 * @note    For a failing test, reads @ref assertion_message
 *
 * @param[in] test:     The test
 * @param[in] result:   Whether the test passed
 */
static void microunit_print_test_result(microunit_test_t * test, bool result);

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */

/**@brief   Holds an assertion message if a failure occurs */
static const char * assertion_message;

/**@brief   Used to jump back to the test invocation on assertion failure */
static jmp_buf      assertion_env;

/**@brief   Whether @ref assertion_env has a valid jump location */
static bool         assertion_env_valid = false;

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

bool microunit_run_test(microunit_test_t * test)
{
    MICROUNIT_DBG_CHECK(test        != NULL);
    MICROUNIT_DBG_CHECK(test->body  != NULL);

    bool test_passed = false;

    if (setjmp(assertion_env) == 0) {
        assertion_env_valid = true;

        if (test->setup) test->setup();
        test->body();

        test_passed = true;

    }
    else {
        test_passed = false;
    }

    assertion_env_valid = false;

    if (test->teardown) test->teardown();

    microunit_print_test_result(test, test_passed);

    return test_passed;
}

void microunit_test_fail(const char * message)
{
    // Verify environment validity
    MICROUNIT_DBG_CHECK(assertion_env_valid);

    // Save assertion message
    assertion_message = message;

    // Jump to calling environment
    longjmp(assertion_env, -1);
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

static void microunit_print_test_result(microunit_test_t * test, bool result)
{
#if MICROUNIT_PRINT_SUCCESS != TRUE
    if (!result) {
#endif
        microunit_print_string(" - TEST: ");
        microunit_print_string(test->name);
        int32_t i;
        for (i = 0; i < 32 - (int32_t) strlen(test->name); i++) {
            microunit_print_string(" ");
        }
        if (result) {
            microunit_print_string(" PASS\r\n");
        }
        else {
            microunit_print_string(" FAIL: ");
            microunit_print_string(assertion_message);
            microunit_print_string("\r\n");
        }
#if MICROUNIT_PRINT_SUCCESS != TRUE
    }
#endif
}

/** @} addtogroup MICROUNIT_TEST */
/** @} addtogroup MICROUNIT */
