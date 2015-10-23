################################################################################
# General board selection makefile for Lumenexus                               #
#                                                                              #
# A makefile including this should define:                                     #
# - REVISION                Board hardware revsion                             #
# - NODE                    Node, effectively location in the array            #
#                                                                              #
# This file provides:                                                          #
# - BOARDS_DIR              The top-level boards directory                     #
# - BOARD_MK                The board file for the specific revision/node      #
################################################################################

# --- BOARD ROOT DIRECTORY --------------------------------------------------- #

# Boards directory is the one this makefile resides in
BOARDS_DIR	:= $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

# --- BOARD SELECTION -------------------------------------------------------- #

# Board makefile
BOARD_MK := $(BOARDS_DIR)/ST_STM32F3_DISCOVERY/board.mk

# Ensure project board file exists
ifneq ("$(wildcard $(BOARD_MK))","")
include $(BOARD_MK)
else
$(error no available board configuration)
endif
