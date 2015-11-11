################################################################################
# Microunit test framework makefile                                            #
#                                                                              #
# This file provides:                                                          #
# - MICROUNIT_INC    Directories to search for Test headers                    #
# - MICROUNIT_SRC    Microunit source files                                    #
# - MICROUNIT_ASM    Microunit assembly files                                  #
# - MICROUNIT_SRC    Microunit preprocessor definitions                        #
################################################################################

# --- DIRECTORIES ------------------------------------------------------------ #

# Test directory is the one this makefile resides in
MICROUNIT_DIR	:= $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

MICROUNIT_INC_DIR	:= $(MICROUNIT_DIR)/inc
MICROUNIT_SRC_DIR	:= $(MICROUNIT_DIR)/src

# --- HEADERS ---------------------------------------------------------------- #

MICROUNIT_INC	:=
MICROUNIT_INC	+= $(MICROUNIT_INC_DIR)

# --- SOURCES ---------------------------------------------------------------- #

MICROUNIT_SRC	:=
MICROUNIT_SRC	+= $(MICROUNIT_SRC_DIR)/microunit_test.c
MICROUNIT_SRC	+= $(MICROUNIT_SRC_DIR)/microunit_suite.c
MICROUNIT_SRC	+= $(MICROUNIT_SRC_DIR)/microunit_util.c

# --- ASSEMBLY --------------------------------------------------------------- #

MICROUNIT_ASM	:=

# --- DEFINITIONS ------------------------------------------------------------ #

MICROUNIT_DEF	:=
