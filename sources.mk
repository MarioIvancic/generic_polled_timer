# List of source files
# This file is included in the main Makefile
# ASRC     Assembler source files for Thumb code
# ASRCARM  Assembler source files for ARM code
# SRCOs, SRCO0, SRCO1, SRCO2, SRCO3 for Thumb code with
#  s,      0,     1,     2,     3   optimization level
# SRCARMOs, SRCARMO0, SRCARMO1, SRCARMO2, SRCARMO3 for ARM code with
#    s,         0,       1,         2,        3    optimisation level
# CPPSRCOs, CPPSRCO0, CPPSRCO1, CPPSRCO2, CPPSRCO3 for Thumb C++ code with
#    s,         0,       1,        2,        3     optimisation level
# CPPSRCARMOs, CPPSRCARMO0, CPPSRCARMO1, CPPSRCARMO2, CPPSRCARMO3 for ARM C++ code with
#     s,            0,           1,           2,           3      optimisation level

# define directory for object files
# it must be deeper than number of .. in sources.mk and it must end with /
OBJDIR := obj/$(BUILD_TYPE)/obj/

# define directory for binary files
BINDIR := bin/$(BUILD_TYPE)/

# Target file name (without extension).
TARGET := generic_polled_timer_test
#TARGET_EXT := .elf
TARGET_EXT :=

# fakes for testing
INC_DIRS += fakes

# unity library for testing
INC_DIRS += unity

# Additional libraries, like -lssl.
LIBS +=


CPPSRCO2 += main.cpp
CPPSRCO2 += generic_polled_timer_test.cpp
INC_DIRS += ./

SRCO2 += unity/unity.c
SRCO2 += fakes/monotonic_time.c


# Place -D or -U options for C here
ifeq ($(BUILD_TYPE),debug)
	CDEFS += -D_DEBUG=1
else
	CDEFS += -D_DEBUG=0
endif


# Place -D or -U options for ASM here
ifeq ($(BUILD_TYPE),debug)
# ADEFS += -DDEBUG
endif


# Flags for C and C++

# warning and error levels
CFLAGS += -Wall
#CFLAGS += -Wcast-align
#CFLAGS += -Wcast-qual
#CFLAGS += -Wimplicit
#CFLAGS += -Wpointer-arith
#CFLAGS += -Wswitch
#CFLAGS += -Wredundant-decls
#CFLAGS += -Wreturn-type
#CFLAGS += -Wshadow
#CFLAGS += -Wunused
CFLAGS += -ftest-coverage -fprofile-arcs --coverage

# preserve temporary files
#CFLAGS += -save-temps

# Generate APCS stack frame
#CFLAGS += -mapcs-frame

#CFLAGS += -fomit-frame-pointer

#CFLAGS += -fno-exceptions
#CFLAGS += -fno-unwind-tables
#CFLAGS += -fno-asynchronous-unwind-tables

# put functions and variables in its own sections
CFLAGS += -ffunction-sections -fdata-sections

# treat libc functions as ordinary functions, not as build-in
#CFLAGS += -fno-builtin

# assume there is no libc
#CFLAGS += -ffreestanding

# Do not use the standard system startup files
#CFLAGS += -nostartfiles

# Do not use the standard system libraries when linking
#CFLAGS += -nodefaultlibs

# Do not use the C library or system libraries tightly coupled with it when linking
#CFLAGS += -nolibc

# Place uninitialized globals in the bss section, not in COMMON section
CFLAGS += -fno-common

# disable unaligned access to packed structures
#CFLAGS += -mno-unaligned-access

ifeq ($(BUILD_TYPE),release)
	# strip binary
	# CFLAGS += -s
endif

ifeq ($(BUILD_TYPE),debug)
	# generate debugging symbols
	LDFLAGS += -g
endif

# flags only for C
#CONLYFLAGS += -Wstrict-prototypes
#CONLYFLAGS += -Wmissing-declarations
#CONLYFLAGS += -Wmissing-prototypes
#CONLYFLAGS += -Wnested-externs
CONLYFLAGS += -std=$(C_STANDARD)

# flags only for C++ (arm-elf-g++)
CPPFLAGS += -std=$(CPP_STANDARD)
#CPPFLAGS += -fno-rtti
#CPPFLAGS += -fno-exceptions
#CPPFLAGS += -fno-unwind-tables
#CPPFLAGS += -fno-asynchronous-unwind-tables



# Linker flags.
ifneq ($(LD_SCRIPT),)
	# Use this linker script
	LDFLAGS +=-T$(LD_SCRIPT)
endif

# Generate MAP file with cross reference table
LDFLAGS += -Wl,--cref,-Map=$(BINDIR)$(TARGET).map

# Delete unused sections
LDFLAGS += -Wl,--gc-sections

# Print memory usage after final link
#LDFLAGS += -Wl,--print-memory-usage

# allow multiple definitions of the same symbol
#LDFLAGS += -Wl,--allow-multiple-definition


# link static binary
#LDFLAGS += -static

