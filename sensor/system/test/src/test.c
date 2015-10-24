/**
 * @file    test.c
 * @author  Austin Glaser <austin.glaser@gmail.com>
 * @brief   Test Source
 *
 * @addtogroup TEST
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// This Module
#include "test.h"

// Standard
#include <stdint.h>
#include <stdbool.h>

// AceUnit
#include "AceUnit.h"
#include "AceUnitData.h"

// Application
#include "debug.h"

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */

#define TEST_CASES_FOR_VERIFICATION 12

/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- TEST FIXTURES -------------------------------------------------------- */

// AceUnitTest
extern TestFixture_t AceUnitTestFixture;
extern int myTestCaseCount;

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

void test(void)
{
    //AceUnitTest
    runFixture(&AceUnitTestFixture);
    if (runnerData->testCaseFailureCount != 0) {
        DEBUG_PRINTF("Test Cases: %d  Errors: %d\r\n", runnerData->testCaseCount, runnerData->testCaseFailureCount);
    }
    if (runnerData->testCaseCount != TEST_CASES_FOR_VERIFICATION) {
        DEBUG_PRINTF("Test Cases: %d but expected %d\r\n", runnerData->testCaseCount, TEST_CASES_FOR_VERIFICATION);
    }
    if (myTestCaseCount != TEST_CASES_FOR_VERIFICATION) {
        DEBUG_PRINTF("Test Cases really executed: %d but expected %d\r\n", myTestCaseCount, TEST_CASES_FOR_VERIFICATION);
    }
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

/** @} addtogroup TEST */
