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

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void microunit_run_test(microunit_test_t * test)
{
}

void microunit_test_fail(const char * message)
{
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup MICROUNIT_TEST */
/** @} addtogroup MICROUNIT */
