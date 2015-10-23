################################################################################
# AceUnit makefile                                                             #
#                                                                              #
# This file provides:                                                          #
# - ACEUNIT_INC        Directories to search for AceUnit headers               #
# - ACEUNIT_SRC        AceUnit source files                                    #
# - ACEUNIT_ASM        AceUnit assembly files                                  #
# - ACEUNIT_SRC        AceUnit preprocessor definitions                        #
# - ACEUNIT_HDR_GEN    AceUnit header generator                                #
################################################################################

# --- DIRECTORIES ------------------------------------------------------------ #

# AceUnit directory is the one this makefile resides in
ACEUNIT_DIR	:= $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

ACEUNIT_INC_DIR	:= $(ACEUNIT_DIR)/native
ACEUNIT_SRC_DIR	:= $(ACEUNIT_DIR)/native
ACEUNIT_JAVA_DIR:= $(ACEUNIT_DIR)/java

# --- GENERATOR -------------------------------------------------------------- #

ACEUNIT_HDR_GEN	:= java -jar $(ACEUNIT_JAVA_DIR)/AceUnit.jar

# --- HEADERS ---------------------------------------------------------------- #

ACEUNIT_INC	:=
ACEUNIT_INC	+= $(ACEUNIT_INC_DIR)

# --- SOURCES ---------------------------------------------------------------- #

ACEUNIT_SRC	:=
ACEUNIT_SRC	+= $(ACEUNIT_SRC_DIR)/AceUnit.c
ACEUNIT_SRC	+= $(ACEUNIT_SRC_DIR)/AceUnitData.c

# --- ASSEMBLY --------------------------------------------------------------- #

ACEUNIT_ASM	:=

# --- DEFINITIONS ------------------------------------------------------------ #

ACEUNIT_DEF	:=
