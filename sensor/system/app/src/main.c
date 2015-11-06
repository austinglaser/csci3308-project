/**
 * @file    main.c
 * @author  Austin Glaser <austin@boulderes.com>
 * @brief   Application Entry Point
 *
 * @defgroup MAIN Main
 * @{
 */

/* --- PRIVATE DEPENDENCIES ------------------------------------------------- */

// Standard
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Chibios
#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "ctype.h"

// Application
#include "debug.h"

#if defined(TEST)
#include "microunit.h"
#endif

/* --- PRIVATE DATATYPES ---------------------------------------------------- */
/* --- PRIVATE FUNCTION PROTOTYPES ------------------------------------------ */

/**
 *  @brief  Converts a string to lower case
 */
static uint8_t* str_to_lower(uint8_t* str);

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */

#define DO_ECHO     TRUE        /**< Whether or not to echo characters */
#define BUF_LEN     256         /**< Number of characters to store */
#define DEL         0x7F        /**< ASCII value to recognize as delete */

/* --- PRIVATE MACROS ------------------------------------------------------- */

#if DO_ECHO == TRUE || defined(__DOXYGEN__)
    #define ECHO(c) do {                                      \
                        if (c == '\r') {                      \
                            sdPut(&SD1, '\r');                \
                            sdPut(&SD1, '\n');                \
                        }                                     \
                        else if (c == DEL && buf_index > 0) { \
                            sdPut(&SD1, '\b');                \
                            sdPut(&SD1, ' ');                 \
                            sdPut(&SD1, '\b');                \
                        }                                     \
                        else {                                \
                            sdPut(&SD1, c);                   \
                        }                                     \
                    } while (0)
#else
    #define ECHO(...) ((void) 0)
#endif

#define ON_CONDITION(buf, buf_len)  (((buf_len) > 0) && (strncmp((char *) (buf), "on", (buf_len))    == 0))

#define OFF_CONDITION(buf, buf_len) (((buf_len) > 0) && \
                                     ((strncmp((char *) (buf), "f", (buf_len)) == 0) || (strncmp((char *) (buf), "off", (buf_len)) == 0)))

#define TOG_CONDITION(buf, buf_len) ((buf_len) > 0 && (strncmp((char *) (buf), "toggle", (buf_len)) == 0))


/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

/**
 * @brief   Application entry point
 */
int main(void) {

    // ChibiOS init
    halInit();
    chSysInit();

    palClearPad(GPIOC, 8);
    palSetPadMode(GPIOC,  8, PAL_MODE_OUTPUT_PUSHPULL);

    // Application init
    debug_init();

    static uint8_t buffer[BUF_LEN + 1] = { [0 ... BUF_LEN] = '\0'};
    static uint32_t buf_index = 0;

    while (true) {
        //palTogglePad(GPIOC, 8);
        //chThdSleepMilliseconds(5000);
        msg_t char_in = sdGet(&SD1);
        ECHO(char_in);
        //chprintf((BaseSequentialStream *) &SD1, "%02x\r\n", char_in);

        // backspace
        if (char_in == DEL && buf_index > 0) {
            buf_index--;
            buffer[buf_index] = '\0';
        }
        
        // nonfull buffer
        else if (buf_index < BUF_LEN && char_in != '\r') {
            buffer[buf_index] = char_in;
            buffer[buf_index + 1] = '\0';
            buf_index++;
        }

        // end of line
        if (char_in == '\r') {
            // process command
            str_to_lower(buffer);
            if (ON_CONDITION(buffer, buf_index)) {
                palSetPad(GPIOC, 8);
                sdWrite(&SD1, (uint8_t*) "OK\r\n", 4);
            }
            else if (OFF_CONDITION(buffer, buf_index)) {
                palSetPad(GPIOC, 8);
                palClearPad(GPIOC, 8);
                sdWrite(&SD1, (uint8_t*) "OK\r\n", 4);
            }
            else if (TOG_CONDITION(buffer, buf_index)) {
                palTogglePad(GPIOC, 8);
                sdWrite(&SD1, (uint8_t*) "OK\r\n", 4);
            }
            else {
                sdWrite(&SD1, (uint8_t*) "ERROR\r\n", 7);
            }


            // reset buffer
            buf_index = 0;
            buffer[0] = '\0';
        }
    }
}

/* --- PRIVATE FUNCTION DEFINITIONS ----------------------------------------- */

static uint8_t* str_to_lower(uint8_t* str)
{
    uint32_t i;
    for (i = 0; str[i]; i++) str[i] = tolower(str[i]);

    return str;
}

/** @} defgroup MAIN */
