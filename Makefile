# -----------------------------------------------------------------------------
# @file Makefile
# @author Jacob Crabill <jacob@flyvoly.com>
# @date September 2020
# @brief Makefile for K-D Tree Library
#
# For Volans-i's Fall 2020 Embedded Software Team Interview Exercise
# -----------------------------------------------------------------------------

# CANDIDATE TODO: Set up variables needed for compiler, flags, objects, generic target, etc.

# --------------------------------------------
# Basic 'make' target
# --------------------------------------------
# CANDIDATE TODO: implement some basic target for  when you type 'make'

# --------------------------------------------
# Custom 'make' targets
# --------------------------------------------
# Build libkdtree as a static library
.PHONY: libstatic
libstatic: # CANDIDATE TODO: Implement the 'make libstatic' target

# Build libkdtree as a shared library
.PHONY: libshared
libshared: # CANDIDATE TODO: Implement the 'make libshared' target

# Build 'main' with static linking to libkdtree
.PHONY: static
static: libstatic
static: # CANDIDATE TODO: Implement the 'make static' target

# Build 'main' with dynamic linking to libkdtree
.PHONY: shared
shared: libshared
shared: # CANDIDATE TODO: Implement the 'make shared' target

# Bonus: Create a 'make clean' target to remove all build-generated files
# CANDIDATE TODO (optional bonus ;) 
.PHONY: clean
clean: 
	rm -f *.o

# --------------------------------------------
# Implicit build rules
# --------------------------------------------
# CANDIDATE TODO: Implement the generic / 'implicit' compilation rules
