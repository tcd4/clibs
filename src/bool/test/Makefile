####################
#
# Linux Makefile
#
####################


#
# Object Files
#

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))


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
STATIC_LIBRARIES = clib_bool.a
LIBRARY_PATH = ../../../libs

# includes
INCLUDE_PATHS = ../../../include
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -o $(PROJECT)
CFLAGS = -g $(INCLUDE_PARAMS) -Wall -pedantic -std=gnu99 -fgnu89-inline -Wno-unknown-pragmas -Wno-variadic-macros 
CLIB_LDFLAGS = -L$(LIBRARY_PATH) $(foreach d, $(STATIC_LIBRARIES), $(LIBRARY_PATH)/$d)


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
