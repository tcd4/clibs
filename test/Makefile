####################
#
# Linux Makefile
#
####################

#
# Object Files
#

OBJECTS = 


#
# Project Info
#

PROJECT = test

#
# Compiler Info
#

# clang
CC = gcc

# library
STATIC_LIBRARIES = libclibs_types.a
LIBRARY_PATH = ../libs

# includes
INCLUDE_PATHS = ../include
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -o $(PROJECT)
CFLAGS = -g -Wall -pedantic -std=gnu99 -fgnu89-inline -Wno-unknown-pragmas -Wno-variadic-macros $(INCLUDE_PARAMS)


#
# Compiling
#

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(PROJECT)
