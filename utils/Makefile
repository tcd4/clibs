####################
#
# Linux Makefile
#
####################

#
# Object Files
#

OBJECTS = $(pathsubst %.c, %.o,$(wildcard *.c))


#
# Project Info
#

PROJECT = clib_utils
VERSION_MAJOR = 1
VERSION_MINOR = 0.1


#
# Documentation
#

DOXYGEN = doxygen


#
# Compiler Info
#

# clang
CC = gcc

# library
LIBRARY_PATH = ../libs

# includes
INCLUDE_PATHS = ../include
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -shared -Wl,-soname,lib$(PROJECT).so.$(VERSION_MAJOR) -o $(LIBRARY_PATH)/lib$(PROJECT).so.$(VERSION_MAJOR).$(VERSION_MINOR)
CFLAGS = -g -c -fPIC -Wall -pedantic -Wno-unknown-pragmas -Wno-variadic-macros $(INCLUDE_PARAMS)


#
# Compiling
#

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(LIBRARY_PATH)/lib$(PROJECT).a


#
# Library Creation
#

static:
	ar rcs $(LIBRARY_PATH)/lib$(PROJCET).a $(OBJECTS)


#
# Documentation Creation
#

docs:
	$(DOXYGEN) doxgen.cfg
