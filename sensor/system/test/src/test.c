/**
 * @file    test.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Test  Source
 *
 * @addtogroup TEST
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "test.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// Test framework
#include "microunit.h"

// Test suites
#include "switch_test.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void run_tests(void)
{
    microunit_run_suite(switch_test());
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup TEST */
