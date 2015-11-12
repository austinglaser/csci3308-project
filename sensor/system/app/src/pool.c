/**
 * @file    pool.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Memory Pool Source
 *
 * @addtogroup POOL
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "pool.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// ChibiOS
#include "ch.h"
#include "hal.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */

/**@brief   Internal ChibiOS memory pool */
static MEMORYPOOL_DECL(pool_mp, POOL_MEMORY_SIZE, NULL);

/**@brief   Array of memory to serve out */
uint8_t pool_array[POOL_MEMORY_SIZE][POOL_AVAILABLE];

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void pool_init(void)
{
    // Because of use of MEMORYPOOL_DECL above, we require no call to an init function

    // Put in our memory array
    chPoolLoadArray(&pool_mp, pool_array, POOL_AVAILABLE);
}

void * pool_alloc(void)
{
    chSysLock();
    void * p = pool_alloc_i();
    chSysUnlock();

    return p;
}

void * pool_alloc_i(void)
{
    chDbgCheckClassI();

    // Get another region from the allocator
    return chPoolAllocI(&pool_mp);
}

void pool_free(void * p)
{
    chSysLock();
    pool_free_i(p);
    chSysUnlock();
}

void pool_free_i(void * p)
{
    chDbgCheckClassI();
    chDbgCheck(p != NULL);
    chDbgCheck(((void*) &pool_array) <= p && p <= (((void*) &pool_array) + (POOL_MEMORY_SIZE * (POOL_AVAILABLE - 1))));
    chDbgCheck(((p - (void*) &pool_array) % POOL_MEMORY_SIZE) == 0);

    chPoolFreeI(&pool_mp, p);
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup POOL */
