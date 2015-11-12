/**
 * @file    microunit_util.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Utility Interface
 */

#ifndef MICROUNIT_UTIL_H
#define MICROUNIT_UTIL_H

/**@addtogroup MICROUNIT
 * @{
 */

/**@defgroup MICROUNIT_UTIL MicroUnit Utilities
 * @{ 
 *
 * @brief Utility functions for MicroUnit
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// This module
#include "microunit.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief   Determine the number of elements in a statically or locally allocated array
 *
 * @warning Cannot be used on arrays passed as pointers, function parameters, etc
 */
#define MICROUNIT_ARRAY_ELEMS(arr)      (sizeof(arr)/sizeof((arr)[0]))

#define MICROUNIT_STRINGIFY(sym)        #sym

#define MICROUNIT_TOSTRING(sym)         MICROUNIT_STRINGIFY(sym)

#define MICROUNIT_AT                    __BFILE__ ":" MICROUNIT_TOSTRING(__LINE__)

#define MICROUNIT_DBG_CHECK(condition)  do {                                                                                               \
                                            if (!(condition)) {                                                                            \
                                                microunit_internal_assertion_failure("INTERNAL ERROR: " #condition " (" MICROUNIT_AT ")"); \
                                            }                                                                                              \
                                        } while(0)

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Called on failure of an internal (non-test) assertion
 *
 * @note    Overrideable by user
 */
void microunit_internal_assertion_failure(const char * message);

/**@brief   Called to display a string
 *
 * @note    Overrideable by user
 */
void microunit_print_string(const char * string);

/**@brief   Prints a signed integer
 *
 * @param[in] n:    The integer to print
 */
void microunit_print_n(int32_t n);

/** @} defgroup MICROUNIT_UTIL */
/** @} addtogroup MICROUNIT */

#endif /* ifndef MICROUNIT_UTIL_H */
