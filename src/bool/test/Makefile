####################
#
# Linux Makefile
#
####################

#
# Project Info
#

PROJECT = test


#
# Object Files
#

OBJECTS = bool_test.o


#
# Compiler Info
#

# clang
CC = gcc

# library
STATIC_LIBRARIES = 
LIBRARY_PATH = ../../../libs

# includes
INCLUDE_PATHS = ../../../include
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -o $(PROJECT)
CFLAGS = -g -Wall -pedantic -std=gnu99 -fgnu89-inline -Wno-unknown-pragmas -Wno-variadic-macros $(INCLUDE_PARAMS)
CLIB_LDFLAGS = -L$(LIBRARY_PATH) $(LIBRARY_PATH)/$(STATIC_LIBRARIES)


#
# Compiling
#

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) $(CLIBS_LDFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(PROJECT)
