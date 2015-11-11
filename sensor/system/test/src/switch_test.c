/**
 * @file    switch_test.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Power Switch Driver Test Source
 *
 * @addtogroup TEST
 * @{
 *
 * @addtogroup SWITCH_TEST
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// Module under test
#include "switch.h"

// This Module
#include "switch_test.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// Test framework
#include "microunit.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */
/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */

/**@brief   Performs setup functions for each test */
static void common_setup(void);

/**@brief   Test that the switch is off after initialization */
static void test_starts_off(void);

/**@brief   Test that the power switch can be turned on */
static void test_on(void);

/**@brief   Test that the power switch can be turned off */
static void test_off(void);

/**@brief   Test that the power switch can be toggled */
static void test_toggle(void);

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

microunit_suite_t * switch_test(void)
{
    static microunit_test_t tests[] = {
        MICROUNIT_TEST(common_setup, test_starts_off, NULL),
        MICROUNIT_TEST(common_setup, test_on,         NULL),
        MICROUNIT_TEST(common_setup, test_off,        NULL),
        MICROUNIT_TEST(common_setup, test_toggle,     NULL),
    };

    MICROUNIT_SUITE(switch_test_suite, tests);

    return &switch_test_suite;
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

static void common_setup(void)
{
    switch_init();
}

static void test_starts_off(void)
{
    // Init happens in setup
    microunit_assert(switch_get_state() == false);
}

static void test_on(void)
{
    switch_set_state(true);
    microunit_assert(switch_get_state() == true);
}

static void test_off(void)
{
    switch_set_state(false);
    microunit_assert(switch_get_state() == false);
}

static void test_toggle(void)
{
    bool initial_state = switch_get_state();
    switch_toggle();
    bool toggled_state = switch_get_state();
    microunit_assert(initial_state != toggled_state);
    switch_toggle();
    toggled_state = switch_get_state();
    microunit_assert(initial_state == toggled_state);
}

/** @} addtogroup SWITCH_TEST */
/** @} addtogroup TEST */
