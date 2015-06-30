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

PROJECT = Queue
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
LIBRARY_PATH = ../../../libs
CLIB_LIBRARIES = clib_List.a

# includes
INCLUDE_PATHS = ../../../include
INCLUDE_PARAMS = $(foreach d, $(INCLUDE_PATHS), -I$d)

# compiler flags
LFLAGS = -g -shared -Wl,-soname,clib_$(PROJECT).so.$(VERSION_MAJOR) -o $(LIBRARY_PATH)/clib_$(PROJECT).so.$(VERSION_MAJOR).$(VERSION_MINOR)
CFLAGS = -g -c -fPIC -Wall -pedantic -Wno-unknown-pragmas -Wno-variadic-macros $(INCLUDE_PARAMS)
CLIB_LDFLAGS = $(foreach d, $(CLIB_LIBRARIES), $(LIBRARY_PATH)/$d)

#
# Compiling
#

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) $(CLIB_LDFLAGS)


#
# Directory Cleanup
#

clean:
	rm *.o $(LIBRARY_PATH)/clib_$(PROJECT).*


#
# Library Creation
#

static:
	ar rcs $(LIBRARY_PATH)/clib_$(PROJECT).a $(OBJECTS)


#
# Documentation Creation
#

docs:
	$(DOXYGEN) doxgen.cfg

