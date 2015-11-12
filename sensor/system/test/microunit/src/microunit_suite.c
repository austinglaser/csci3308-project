/**
 * @file    microunit_suite.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Test Suite Source
 *
 * @addtogroup MICROUNIT_SUITE
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "microunit.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void microunit_run_suite(microunit_suite_t * suite)
{
    uint32_t n_failed = 0;

    microunit_print_string("SUITE: ");
    microunit_print_string(suite->name);
    microunit_print_string("\r\n");

    uint32_t i;
    for (i = 0; i < suite->n_tests; i++) {
        if (!microunit_run_test(&suite->tests[i])) n_failed++;
    }

    if (n_failed > 0) {
        microunit_print_string("FAIL (");
        microunit_print_n(n_failed);
        microunit_print_string(" tests)\r\n");
    }
    else {
        microunit_print_string("PASS\r\n");
    }
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup MICROUNIT_SUITE */
