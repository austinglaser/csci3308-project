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

// Standard
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <setjmp.h>

// MicroUnit
#include "microunit.h"
#include "microunit_test.h"
#include "microunit_util.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */

/**@brief   Holds an assertion message if a failure occurs */
static const char * assertion_message;

/**@brief   Used to jump back to the test invocation on assertion failure */
static jmp_buf      assertion_env;

/**@brief   Whether @ref assertion_env has a valid jump location */
static bool         assertion_env_valid = false;

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void microunit_run_test(microunit_test_t * test)
{
    MICROUNIT_DBG_CHECK(test != NULL);

    if (setjmp(assertion_env) == 0) {
        assertion_env_valid = true;
    }
    else {
        microunit_print_string(test->name);
        microunit_print_string(" failed: ");
        microunit_print_string(assertion_message);
        microunit_print_string("\r\n");
    }

    assertion_env_valid = false;
}

void microunit_test_fail(const char * message)
{
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup MICROUNIT_TEST */
/** @} addtogroup MICROUNIT */
