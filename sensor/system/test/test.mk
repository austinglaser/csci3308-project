################################################################################
# Unit Test makefile                                                           #
#                                                                              #
# This file provides:                                                          #
# - TEST_INC    Directories to search for test headers                         #
# - TEST_SRC    Test source files                                              #
# - TEST_ASM    Test assembly files                                            #
# - TEST_SRC    Test preprocessor definitions                                  #
################################################################################

# --- DIRECTORIES ------------------------------------------------------------ #

# Test directory is the one this makefile resides in
TEST_DIR		:= $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

TEST_INC_DIR		:= $(TEST_DIR)/inc
TEST_SRC_DIR		:= $(TEST_DIR)/src
TEST_FXT_INC_DIR	:= $(BUILDDIR)/test_inc

# --- SUBMODULES ------------------------------------------------------------- #

ACEUNIT_CONFIG_FILE	:= $(TEST_INC_DIR)/AceUnitConfig.h
include $(TEST_DIR)/aceunit/aceunit.mk

# --- FIXTURES --------------------------------------------------------------- #

TEST_FXT_SRC		:=
TEST_FXT_SRC		+= $(TEST_SRC_DIR)/AceUnitTest.c

# --- HEADERS ---------------------------------------------------------------- #

TEST_INC		:=
TEST_INC		+= $(TEST_INC_DIR)
TEST_INC		+= $(ACEUNIT_INC)

# --- SOURCES ---------------------------------------------------------------- #

TEST_SRC		:=
TEST_SRC		+= $(TEST_SRC_DIR)/test.c
TEST_SRC		+= $(TEST_SRC_DIR)/DebugLogger.c
TEST_SRC		+= $(ACEUNIT_SRC)

# --- ASSEMBLY --------------------------------------------------------------- #

TEST_ASM		:=
TEST_ASM		+= $(ACEUNIT_ASM)

# --- DEFINITIONS ------------------------------------------------------------ #

TEST_DEF		:=
TEST_DEF		+= -DACEUNIT_CONFIG_FILE=\"$(ACEUNIT_CONFIG_FILE)\"
TEST_DEF		+= -DTEST
TEST_DEF		+= $(ACEUNIT_DEF)

