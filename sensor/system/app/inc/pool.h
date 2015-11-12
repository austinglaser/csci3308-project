/**
 * @file    pool.h
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Memory Pool Interface
 */

#ifndef POOL_H
#define POOL_H

/**@defgroup POOL Memory Pool
 * @{ 
 *
 * @brief
 */

/* --- PUBLIC DEPENDENCIES -------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>

/* --- PUBLIC CONSTANTS ----------------------------------------------------- */

/**@brief   Size of the memory regions allocated by the pool
 *
 * Total memory usage is @ref POOL_MEMORY_SIZE * @ref POOL_AVAILABLE
 */
#define POOL_MEMORY_SIZE        (64)

/**@brief   Number of availble memory regions
 *
 * Total memory usage is @ref POOL_MEMORY_SIZE * @ref POOL_AVAILABLE
 */
#define POOL_AVAILABLE          (5)

/* --- PUBLIC DATATYPES ----------------------------------------------------- */
/* --- PUBLIC MACROS -------------------------------------------------------- */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**@brief   Initialize the memory pool */
void pool_init(void);

/**@brief   Allocate memory from the pool
 *
 * The size of the region is @ref POOL_MEMORY_SIZE
 *
 * Normal API, this function can be invoked by regular system threads but not from within a lock zone
 * 
 * @return          A pointer to the allocated memory
 * @retval NULL:    No memory available
 */
void * pool_alloc(void);

/**@brief   Allocate memory from the pool
 *
 * The size of the region is @ref POOL_MEMORY_SIZE
 * 
 * This is an I-Class API, this function can be invoked from within a system lock zone by both threads and interrupt handlers
 *
 * @return          A pointer to the allocated memory
 * @retval NULL:    No memory available
 */
void * pool_alloc_i(void);

/**@brief   Release the region pointed to by p back into the memory pool
 *
 * @p p must have been allocated by @ref pool_alloc
 *
 * Normal API, this function can be invoked by regular system threads but not from within a lock zone
 *
 * @param[in] p:    Pointer to the region to be freed
 */
void pool_free(void * p);

/**@brief   Release the region pointed to by p back into the memory pool
 *
 * @p p must have been allocated by @ref pool_alloc
 *
 * This is an I-Class API, this function can be invoked from within a system lock zone by both threads and interrupt handlers
 *
 * @param[in] p:    Pointer to the region to be freed
 */
void pool_free_i(void * p);

/** @} defgroup POOL */

#endif /* ifndef POOL_H */
