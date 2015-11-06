/**
 * @file    unit.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Unit Interface
 */

#ifndef UNIT_H
#define UNIT_H

/**@defgroup UNIT Unit
 * @{ 
 *
 * @brief A lightweight framework, developed to address problems with other
 *        available embedded unit test libraries
 *
 * @par Terms
 * Many unit test frameworks have a plethora of terms used, often without good
 * definition. For this framework, we will attempt to keep the number of terms
 * used low, and to define them well.
 *
 * @b Test: A single procedure for verifying code functionality. A test has:
 *
 * - A body function, which runs main procedure
 * - An optional setup function, which can allocate memory or initialize data
 *   structures, and can be shared across multiple tests
 * - An optional teardown function, which can free memory or do other cleanup
 *   tasks, and can be shared across multiple tests
 *
 * @b Suite: A set of tests, which are run together. Results can be reported in
 * aggregate for a suite. A suite has:
 *
 * - Several tests
 * - An optional setup function, which is run once before any tests.
 * - An optional teardown function, which is run once after all tests complete.
 *
 * @b Unit: A set of suites, run in sequence
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// Framework components
#include "test.h"
#include "suite.h"
#include "unit_util.h"

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */

/**@brief   Top-level test object
 * 
 * @note    Always declare with the declaration macros
 */
typedef struct {
    uint32_t            n_suites;           /**< Number of test suites in the unit */
    const suite_t **    suites;             /**< Array of test suites */
} unit_t;

/* --- PUBLIC MACROS -------------------------------------------------------- */

/**@brief   Start the declaration of a unit
 *
 * @note    @p name MUST match the name provided to @ref UNIT_DECLARATION_END
 *
 * @param[in] name: The unit's name
 */
#define UNIT_DECLARATION_START(name)         static const suite_t UNIT_CAT_SYM(name, _suites)[] = {

/**@brief   Add a suite to a unit
 *
 * @param[in] suite:    Pointer to the suite to add
 */
#define UNIT_DECLARATION_ADD_SUITE(suite)       ((suite_t *) suite)

/**@brief   End the declaration of a unit
 *
 * @note    @p name MUST match the name provided to @ref UNIT_DECLARATION_START
 *
 * @param[in] name: The unit's name
 */
#define UNIT_DECLARATION_END(name)          };                                                              \
                                            static const unit_t name = {                                    \
                                                .n_suites   = UNIT_ARRAY_ELEM(UNIT_CAT_SYM(name, _suites)), \
                                                .suites     = UNIT_CAT_SYM(name, _suites)                   \
                                            };

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Run the unit test
 *
 * @param[in] u:    The unit test to run
 */
void unit_run(unit_t * u);

/**@brief   Print a null-terminated string
 *
 * @note    unit provides a default implementation of this as a weak symbol.
 *          For embedded platforms, the user can override it
 *
 * @param[in] str:  The null-terminated string to print
 */
void unit_print_str(const char * str);

/**@brief   Print an integer
 *
 * @note    unit provides a default implementation of this as a weak symbol.
 *          For embedded platforms, the user can override it
 *
 * @param[in] n:    The number to print
 */
void unit_print_int(const int32_t n);

/** @} defgroup UNIT */

#endif /* ifndef UNIT_H */
