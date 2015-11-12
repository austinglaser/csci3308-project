/**
 * @file    pool_test.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Memory Pool Test Source
 *
 * @addtogroup TEST
 * @{
 *
 * @addtogroup POOL_TEST
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// Module under test
#include "pool.h"

// This Module
#include "pool_test.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// Test framework
#include "microunit.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */

/**@brief   Releases all acquired memory into the pool */
static void pool_memory_release(void);

/**@brief   Test that we can allocate a piece of memory */
static void test_allocate(void);

/**@brief   Test that we can free a piece of memory */
static void test_free(void);

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

microunit_suite_t * pool_get_test_suite(void) {
    static microunit_test_t tests[] = {
        MICROUNIT_TEST(pool_memory_release, test_allocate, pool_memory_release),
        MICROUNIT_TEST(pool_memory_release, test_free,     pool_memory_release),
    };

    MICROUNIT_SUITE(pool_test_suite, tests);

    return &pool_test_suite;
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

static void pool_memory_release(void)
{
    // Pull out all memory
    while(pool_alloc());

    // Re-initialize
    pool_init();
}

static void test_allocate(void)
{
    void * p = pool_alloc();
    microunit_assert(p != NULL);
}

static void test_free(void)
{
    void * p = pool_alloc();
    pool_free(p);

    // TODO: Find how to test for success
}

/** @} addtogroup POOL_TEST */
/** @} addtogroup TEST */
