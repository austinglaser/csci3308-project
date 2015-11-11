/**
 * @file    microunit_util.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Utility Source
 *
 * @addtogroup MICROUNIT
 * @{
 *
 * @addtogroup MICROUNIT_UTIL
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "microunit.h"

// Standard
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */
/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

__attribute((weak)) void microunit_internal_assertion_failure(const char * message)
{
    fprintf(stderr, "%s\n", message);
    exit(-1);
}

__attribute((weak)) void microunit_print_string(const char * string)
{
    printf("%s", string);
}

void microunit_print_n(int32_t n)
{
    char str[33];

    snprintf(str, 33, "%ld", n);
}

/** @} addtogroup MICROUNIT_UTIL */
/** @} addtogroup MICROUNIT */
