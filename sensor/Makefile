################################################################################
# Top-level makefile for Lumenexus                                             #
################################################################################

# --- PROJECT ROOT DIRECTORY ------------------------------------------------- #

# Root directory is the one this makefile resides in
ROOT_DIR	:= $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

# --- PROJECT CONFIGURATION -------------------------------------------------- #

PROJECT		:= outletify-sensor

DEBUG		?= true
TEST		?= false

# --- PROJECT DIRECTORIES ---------------------------------------------------- #

# Code Directories
SYSTEM_DIR	:= $(ROOT_DIR)/system
SUPPORT_DIR	:= $(ROOT_DIR)/support
CHIBIOS		:= $(ROOT_DIR)/chibios

# Generated directories
BUILDDIR	:= $(ROOT_DIR)/build

# --- OPTIONS ---------------------------------------------------------------- #

# Delete files on failed target completion
.DELETE_ON_ERROR:

# --- PROJECT SECTIONS ------------------------------------------------------- #

# Board
include $(SYSTEM_DIR)/boards/boards.mk

# Drivers
include $(SYSTEM_DIR)/drivers/drivers.mk

# Application
include $(SYSTEM_DIR)/app/app.mk

# Test
include $(SYSTEM_DIR)/test/test.mk

# Test
ifeq ($(TEST), true)
include $(SYSTEM_DIR)/test/test.mk
endif

# --- PROJECT COMPILATION ---------------------------------------------------- #

include $(SUPPORT_DIR)/chibios.mk
