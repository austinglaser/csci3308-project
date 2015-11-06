################################################################################
# Test makefile                                                                #
#                                                                              #
# This file provides:                                                          #
# - TEST_INC    Directories to search for Test headers                         #
# - TEST_SRC    Test source files                                              #
# - TEST_ASM    Test assembly files                                            #
# - TEST_SRC    Test preprocessor definitions                                  #
################################################################################

# --- DIRECTORIES ------------------------------------------------------------ #

# Test directory is the one this makefile resides in
TEST_DIR	:= $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

TEST_INC_DIR	:= $(TEST_DIR)/inc
TEST_SRC_DIR	:= $(TEST_DIR)/src

# --- HEADERS ---------------------------------------------------------------- #

TEST_INC	:=
TEST_INC	+= $(TEST_INC_DIR)

# --- SOURCES ---------------------------------------------------------------- #

TEST_SRC	:=

# --- ASSEMBLY --------------------------------------------------------------- #

TEST_ASM	:=

# --- DEFINITIONS ------------------------------------------------------------ #

TEST_DEF	:=
TEST_DEF	+= -DTEST
