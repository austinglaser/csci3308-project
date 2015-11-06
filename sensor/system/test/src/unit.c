/**
 * @file    unit.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Unit Source
 *
 * @addtogroup UNIT
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "unit.h"

// Standard
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

// Unit submodules
#include "suite.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void unit_run(unit_t * u)
{
    unit_test_print_str("\r\nUnit test");

    uint32_t i;
    for (i = 0; i < n->n_suites; i++) suite_run(n->suites[i]);
}

void unit_print_str(const char * str) __attribute((weak))
{
    printf("%s", str);
}

void unit_print_int(const int32_t n) __attribute((weak))
{
    printf("%d", n);
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup UNIT */
