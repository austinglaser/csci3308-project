/**
 * @file    pool_test.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Memory Pool Test Interface
 */

#ifndef POOL_TEST_H
#define POOL_TEST_H

/**@addtogroup TEST
 * @{
 */

/**@defgroup POOL_TEST PoolTest
 * @{ 
 *
 * @brief
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

// Test framework
#include "microunit.h"

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */
/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Get the pool test suite
 *
 * @return  A reference to the test suite
 */
microunit_suite_t * pool_get_test_suite(void);

/** @} defgroup POOL_TEST */
/** @} addtogrooup TEST */

#endif /* ifndef POOL_TEST_H */
