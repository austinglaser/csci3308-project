/**
 * @file    unit_util.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Unit Utility Interface
 */

#ifndef UNIT_UTIL_H
#define UNIT_UTIL_H

/**@defgroup UNIT_UTIL Unit Utilities
 * @{ 
 *
 * @brief   Shared utility functions for the unit framework
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief   Concatenates two symbols s1 and s2 exactly, without expanding either
 *
 * @param[in] s1:       The first symbol to concatenate
 * @param[in] s2:       The second symbol to concatenate
 *
 * @return              A single symbol containing s1 and s2 concatenated without expansion
 */
#define _UNIT_CAT_SYM(s1, s2)   s1##s2

/**@brief  Concatenate the symbols s1 and s2, expanding both of them
 *
 * This is important because simply applying s1##s2 doesn't expand them if they're
 * preprocessor tokens themselves
 *
 * @param[in] s1:       The first symbol to concatenate
 * @param[in] s2:       The second symbol to concatenate
 *
 * @return              A single symbol containing s1 expanded followed by s2 expanded
 */
#define UNIT_CAT_SYM(s1, s2)    _UNIT_CAT_SYM(s1, s2)

/**@brief   Determines the number of elements in an array
 *
 * @note    Will not work on non-locally allocated arrays
 *
 * @param[in] arr:      The array to find the size of
 * 
 * @return              The number of elements in @p arr
 */
#define UNIT_ARRAY_ELEM(arr)    (sizeof(arr)/sizeof((arr)[0])

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/** @} defgroup UNIT_UTIL */

#endif /* ifndef UNIT_UTIL_H */
