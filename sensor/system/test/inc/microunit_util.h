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

/**@defgroup MICROUNIT_UTIL MicrounitUtil
 * @{ 
 *
 * @brief Utility functions for MicroUnit
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

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
#define MICROUNIT_ARRRAY_ELEMS(arr)     (sizeof(arr)/sizeof((arr)[0]))

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/** @} defgroup MICROUNIT_UTIL */
/** @} addtogroup MICROUNIT */

#endif /* ifndef MICROUNIT_UTIL_H */
