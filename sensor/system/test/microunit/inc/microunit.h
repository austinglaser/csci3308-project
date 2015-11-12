/**
 * @file    microunit.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   MicroUnit Interface
 */

#ifndef MICROUNIT_H
#define MICROUNIT_H

/**@defgroup MICROUNIT MicroUnit
 * @{ 
 *
 * @brief A lightweight, statically-allocated unit test framework
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// Microunit submodules
#include "microunit_test.h"
#include "microunit_suite.h"
#include "microunit_util.h"

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief   Controls whether successful tests are printed */
#define MICROUNIT_PRINT_SUCCESS         FALSE

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/** @} defgroup MICROUNIT */

#endif /* ifndef MICROUNIT_H */
