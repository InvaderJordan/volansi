# -----------------------------------------------------------------------------
# @file Makefile
# @author Jacob Crabill <jacob@flyvoly.com>
# @date September 2020
# @brief Makefile for K-D Tree Library
#
# For Volans-i's Fall 2020 Embedded Software Team Interview Exercise
# -----------------------------------------------------------------------------

# CANDIDATE TODO: Set up variables needed for compiler, flags, objects, generic target, etc.
CC=gcc
CFLAGS=-Wall
INCLUDES=-I.
SRCS=main.c kdtree.c
OBJS=$(SRCS:.c=.o)
MAIN=volansi

# --------------------------------------------
# Basic 'make' target
# --------------------------------------------
all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

# --------------------------------------------
# Custom 'make' targets
# --------------------------------------------
# Build libkdtree as a static library
.PHONY: libstatic
libstatic: # CANDIDATE TODO: Implement the 'make libstatic' target
	$(CC) $(CFLAGS) -c $(INCLUDES) -o kdtree.o kdtree.c
	ar -rc libkdtree.a kdtree.o

# Build libkdtree as a shared library
.PHONY: libshared
libshared: # CANDIDATE TODO: Implement the 'make libshared' target
	$(CC) $(CFLAGS) -c -fPIC $(INCLUDES) -o kdtree.o kdtree.c
	$(CC) -shared -Wl,-install_name,libkdtree.so -o libkdtree.so *.o


# Build 'main' with static linking to libkdtree
.PHONY: static
static: libstatic
static: # CANDIDATE TODO: Implement the 'make static' target
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) main.c libkdtree.a

# Build 'main' with dynamic linking to libkdtree
.PHONY: shared
shared: libshared
shared: # CANDIDATE TODO: Implement the 'make shared' target
	$(CC) $(CFLAGS) -L. -lkdtree $(INCLUDES) -o $(MAIN) main.c
# Bonus: Create a 'make clean' target to remove all build-generated files
# CANDIDATE TODO (optional bonus ;)
.PHONY: clean
clean:
	rm -f *.o
	rm -f $(MAIN)
	rm -f *.a
	rm -f *.so

# --------------------------------------------
# Implicit build rules
# --------------------------------------------
# CANDIDATE TODO: Implement the generic / 'implicit' compilation rules
