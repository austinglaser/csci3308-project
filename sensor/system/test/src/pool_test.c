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

// ChibiOS
#include "ch.h"
#include "hal.h"

// Test framework
#include "microunit.h"

// Application
#include "debug.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */

/**@brief   Releases all acquired memory into the pool */
static void pool_memory_release(void);

/**@brief   Test that we can allocate a piece of memory */
static void allocate(void);

/**@brief   Test that we can allocate a piece of memory using the lock-zone API */
static void allocate_i(void);

/**@brief   Test that we can free a piece of memory */
static void can_free(void);

/**@brief   Test that we can free a piece of memory using the lock-zone API */
static void can_free_i(void);

/**@brief   Test that we can allocate at least as many buffers as the header says */
static void allocate_all(void);

/**@brief   Test that allocated memory regions are separated sufficiently */
static void no_overlap(void);

/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

microunit_suite_t * pool_get_test_suite(void) {
    static microunit_test_t tests[] = {
        MICROUNIT_TEST(pool_memory_release, allocate,     pool_memory_release),
        MICROUNIT_TEST(pool_memory_release, allocate_i,   pool_memory_release),
        MICROUNIT_TEST(pool_memory_release, can_free,     pool_memory_release),
        MICROUNIT_TEST(pool_memory_release, can_free_i,   pool_memory_release),
        MICROUNIT_TEST(pool_memory_release, allocate_all, pool_memory_release),
        MICROUNIT_TEST(pool_memory_release, no_overlap,   pool_memory_release),
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

static void allocate(void)
{
    void * p = pool_alloc();
    microunit_assert(p != NULL);
}

static void allocate_i(void)
{
    chSysLock();
    void * p = pool_alloc_i();
    chSysUnlock();
    microunit_assert(p != NULL);
}

static void can_free(void)
{
    void * p = pool_alloc();

    // This could fail on an internal assertion failure; we assume success if
    // it does not
    pool_free(p);
}

static void can_free_i(void)
{
    void * p = pool_alloc();

    // This could fail on an internal assertion failure; we assume success if
    // it does not
    chSysLock();
    pool_free_i(p);
    chSysUnlock();
}

static void allocate_all(void)
{
    uint32_t i;
    for (i = 0; i < POOL_AVAILABLE; i++) {
        void * p = pool_alloc();
        microunit_assert(p != NULL);
    }
}

static void no_overlap(void)
{
    void * p[POOL_AVAILABLE];
    uint32_t i, j;

    for (i = 0; i < POOL_AVAILABLE; i++) {
        p[i] = pool_alloc();
        microunit_assert(p[i] != NULL);
    }

    for (i = 0; i < POOL_AVAILABLE; i++) {
        for (j = i + 1; j < POOL_AVAILABLE; j++) {
            size_t separation = p[i] > p[j] ? p[i] - p[j] : p[j] - p[i];
            microunit_assert(separation >= POOL_MEMORY_SIZE);
        }
    }
}

/** @} addtogroup POOL_TEST */
/** @} addtogroup TEST */
