# Optimization level, can be [0, 1, 2, 3, s].
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)

#TOOLCHAIN_NAME ?= arm-none-eabi-
TOOLCHAIN_NAME ?=

BUILD_TYPE ?= debug


# Compiler flag to set the C Standard level.
# c89, c99, c11, c17, gnu89, gnu99, gnu11, gnu17
C_STANDARD := gnu17

# Compiler flag to set the C++ Standard level.
# c++98, c++11, c++14, c++17, gnu++98, gnu++11, gnu++14, gnu++17
CPP_STANDARD := gnu++17


# List any directories to look for include files here.
#     Each directory must be seperated by a space.
INC_DIRS :=


# LibC library: NATIVE, NEWLIB, MCULIBC or none
LIBC := NATIVE


LIBS =
LIBC_FLAGS =
CDEFS =
CFLAGS =
CONLYFLAGS =
ADEFS =
AFLAGS =
CPPDEFS =
CPPFLAGS =
LDFLAGS =

AFLAGS += -x assembler-with-cpp

# Set debug format
ifneq ($(strip $(DEBUGGING_FORMAT)),)
	CFLAGS += -g$(DEBUGGING_FORMAT)
	AFLAGS += -Wa,-g$(DEBUGGING_FORMAT)
	LDFLAGS += -Wl,-g
else
	CFLAGS += -g
	AFLAGS += -Wa,-g
	LDFLAGS += -Wl,-g
endif

# Generate ASM listing file
#  -Wa,...:   tell GCC to pass this to the assembler.
#  -ahlms:    create listing
ifneq ($(strip $(MCU)),)
	CFLAGS += -Wa,-adhlns=$(subst $(suffix $<),.lst,$<)
	AFLAGS += -Wa,-adhlns=$(subst $(suffix $<),.lst,$<)
endif


ifeq ($(strip $(LIBC)),)
	# Do not use the standard system startup files
	CFLAGS += -nostartfiles
	# Do not use the standard system libraries when linking
	CFLAGS += -nodefaultlibs
	# Do not use the C library or system libraries tightly coupled with it when linking
	CFLAGS += -nolibc
else ifeq ($(LIBC),NONE)
	# Do not use the standard system startup files
	CFLAGS += -nostartfiles
	# Do not use the standard system libraries when linking
	CFLAGS += -nodefaultlibs
	# Do not use the C library or system libraries tightly coupled with it when linking
	CFLAGS += -nolibc
else ifeq ($(LIBC),NEWLIB)
	LIBC_FLAGS += -Wl,--start-group -lstdc++ -lc -lm -lgcc -lnosys -Wl,--end-group
	LDFLAGS += --specs=nano.specs
	LDFLAGS += --specs=nosys.specs
else ifeq ($(LIBC),MCULIBC)
	INC_DIRS += $(MCULIBC_DIR) $(MCULIBCPP_DIR)
	LIBC_FLAGS += -L$(MCULIBC_DIR) -L$(MCULIBCPP_DIR)
	LIBC_FLAGS += -Wl,--start-group -lc++ -lc++abi -lcpp -lc -lgcc -Wl,--end-group
else ifeq ($(LIBC),NATIVE)
	LIBC_FLAGS += -Wl,--start-group -lstdc++ -lc -lm -lgcc -Wl,--end-group
else
	$(error Unsuported LIBC)
endif


ifneq ($(BUILD_TYPE),debug)
	ifneq ($(BUILD_TYPE),release)
		$(error Unsupported build type '$(BUILD_TYPE)'! Use BUILD_TYPE=release or BUILD_TYPE=debug)
	endif
endif


# Include source file definitions
include sources.mk

LIBS += $(LIBC_FLAGS)

# Include directories
INCS = $(patsubst %,-I%,$(INC_DIRS))


# ---------------------------------------------------------------------------

ifeq ($(OS),Windows_NT)
    HOST_OS := windows
	TOOLCHAIN_BIN_DIR ?= C:/armgcc/bin/
	TEST := C:/bin/UnixUtils/usr/local/wbin/test
else ifeq ($(shell uname -s),Linux)
	HOST_OS := linux
	TOOLCHAIN_BIN_DIR ?= /usr/bin/
	TEST := test
else
    $(error Unsupported host OS!)
endif

MD := mkdir -p
RM := rm -rf
CP := cp -u
CAT := cat


# Tools location and definiton
CC      := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)gcc
CPP     := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)g++
LD      := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)g++
AR      := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)ar
AS      := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)as
OBJCOPY := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)objcopy
OBJDUMP := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)objdump
SIZE    := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)size
NM      := $(TOOLCHAIN_BIN_DIR)$(TOOLCHAIN_NAME)nm
GCOV    := gcov
LCOV    := lcov
GENHTML := genhtml


# Display size of file.
HEXSIZE = $(TEST) -f $(BINDIR)$(TARGET).hex && $(SIZE) --target=$(OUTPUT_FORMAT) $(BINDIR)$(TARGET).hex
ELFSIZE = $(TEST) -f $(BINDIR)$(TARGET)$(TARGET_EXT) && $(SIZE) -A $(BINDIR)$(TARGET)$(TARGET_EXT)

# Define Messages
# English
MSG_COMPILING := Compiling C:
MSG_COMPILING_ARM := "Compiling C (ARM-only):"
MSG_COMPILINGCPP := Compiling C++:
MSG_COMPILINGCPP_ARM := "Compiling C++ (ARM-only):"
MSG_ASSEMBLING := Assembling:
MSG_ASSEMBLING_ARM := "Assembling (ARM-only):"

# ---------------------------------------------------------------------------

# Define all object files.
COBJ_Os      := $(addprefix $(OBJDIR),$(SRCOs:.c=.o))
COBJ_O0      := $(addprefix $(OBJDIR),$(SRCO0:.c=.o))
COBJ_O1      := $(addprefix $(OBJDIR),$(SRCO1:.c=.o))
COBJ_O2      := $(addprefix $(OBJDIR),$(SRCO2:.c=.o))
COBJ_O3      := $(addprefix $(OBJDIR),$(SRCO3:.c=.o))
COBJ_ARMOs   := $(addprefix $(OBJDIR),$(SRCARMOs:.c=.o))
COBJ_ARMO0   := $(addprefix $(OBJDIR),$(SRCARMO0:.c=.o))
COBJ_ARMO1   := $(addprefix $(OBJDIR),$(SRCARMO1:.c=.o))
COBJ_ARMO2   := $(addprefix $(OBJDIR),$(SRCARMO2:.c=.o))
COBJ_ARMO3   := $(addprefix $(OBJDIR),$(SRCARMO3:.c=.o))
CPPOBJ_Os    := $(addprefix $(OBJDIR),$(CPPSRCOs:.cpp=.o))
CPPOBJ_O0    := $(addprefix $(OBJDIR),$(CPPSRCO0:.cpp=.o))
CPPOBJ_O1    := $(addprefix $(OBJDIR),$(CPPSRCO1:.cpp=.o))
CPPOBJ_O2    := $(addprefix $(OBJDIR),$(CPPSRCO2:.cpp=.o))
CPPOBJ_O3    := $(addprefix $(OBJDIR),$(CPPSRCO3:.cpp=.o))
CPPOBJ_ARMOs := $(addprefix $(OBJDIR),$(CPPSRCARMOs:.cpp=.o))
CPPOBJ_ARMO0 := $(addprefix $(OBJDIR),$(CPPSRCARMO0:.cpp=.o))
CPPOBJ_ARMO1 := $(addprefix $(OBJDIR),$(CPPSRCARMO1:.cpp=.o))
CPPOBJ_ARMO2 := $(addprefix $(OBJDIR),$(CPPSRCARMO2:.cpp=.o))
CPPOBJ_ARMO3 := $(addprefix $(OBJDIR),$(CPPSRCARMO3:.cpp=.o))
AOBJ         := $(addprefix $(OBJDIR),$(ASRC:.S=.o))
AOBJ_ARM     := $(addprefix $(OBJDIR),$(ASRCARM:.S=.o))



ALL_OBJ := $(AOBJ_ARM) $(AOBJ)
ALL_OBJ += $(COBJ_ARMOs) $(COBJ_ARMO0) $(COBJ_ARMO1) $(COBJ_ARMO2) $(COBJ_ARMO3)
ALL_OBJ += $(COBJ_Os) $(COBJ_O0) $(COBJ_O1) $(COBJ_O2) $(COBJ_O3)
ALL_OBJ += $(CPPOBJ_ARMOs) $(CPPOBJ_ARMO0) $(CPPOBJ_ARMO1) $(CPPOBJ_ARMO2) $(CPPOBJ_ARMO3)
ALL_OBJ += $(CPPOBJ_Os) $(CPPOBJ_O0) $(CPPOBJ_O1) $(CPPOBJ_O2) $(CPPOBJ_O3)

# Define all source files
ALL_SRC =  $(ASRC) $(ASRCARM)
ALL_SRC +=    $(SRCOs)    $(SRCO0)    $(SRCO1)    $(SRCO2)    $(SRCO3)
ALL_SRC += $(SRCARMOs) $(SRCARMO0) $(SRCARMO1) $(SRCARMO2) $(SRCARMO3)
ALL_SRC += $(CPPSRCOs) $(CPPSRCO0) $(CPPSRCO1) $(CPPSRCO2) $(CPPSRCO3)
ALL_SRC += $(CPPSRCARMOs) $(CPPSRCARMO0) $(CPPSRCARMO1) $(CPPSRCARMO2) $(CPPSRCARMO3)

# Define all listing files.
LST :=  $(ALL_OBJ:.o=.lst)

# dependency directory
DEPDIR := .dep-$(BUILD_TYPE)/

# Compiler flags to generate dependency files.
### GENDEPFLAGS = -Wp,-M,-MP,-MT,$(*F).o,-MF,.dep/$(@F).d
# GENDEPFLAGS = -MD -MP -MF .dep/$(@F).d
# GENDEPFLAGS = -MD -MP -MMD -MT $@ -MF .dep-$(BUILD_TYPE)/$(@F).d
GENDEPFLAGS = -MD -MP -MMD -MT $@ -MF $(DEPDIR)$@.d

# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS = $(CFLAGS) $(INCS) $(CDEFS) $(GENDEPFLAGS)


# Default target.
debug: begin gccversion build end

#all: begin gccversion update_timestamp sizebefore build sizeafter finished end
#all: begin gccversion sizebefore build sizeafter end
#all: begin gccversion build end
all: debug release

release:
	@$(MAKE) BUILD_TYPE=release

ifneq ($(OUTPUT_FORMAT),)
build: elf sym hex lss dis
else
build: elf sym
endif

elf: $(BINDIR)$(TARGET)$(TARGET_EXT)
lss: $(BINDIR)$(TARGET).lss
sym: $(BINDIR)$(TARGET).sym
dis: $(BINDIR)$(TARGET).dis
hex: $(BINDIR)$(TARGET)$(TARGET_EXT)
	@$(info )
	@$(info Creating load file for Flash: $(BINDIR)$(TARGET).hex)
	@$(OBJCOPY) -O $(OUTPUT_FORMAT) $< $(BINDIR)$(TARGET).hex


# create OBJDIR
ifneq ($(strip $(OBJDIR)),)
objdir:
	@$(TEST) -d $(OBJDIR) || $(MD) $(OBJDIR)
else
objdir:
endif


coverage: debug
	$(BINDIR)$(TARGET)
	-$(GCOV) -o $(OBJDIR) $(ALL_SRC)
	$(LCOV) -c -d $(OBJDIR) -o coverage.info
	$(GENHTML) coverage.info -o coverage



begin:
	@$(info )
	@$(info -------- begin --------)

end:
	@$(info --------  end  --------)
	@$(info )


# Display size of file.
sizebefore:
	@$(info )
	@$(info Size before: $(shell $(ELFSIZE)))
	@$(info )

sizeafter:
	@$(info )
	@$(info Size after: $(shell $(ELFSIZE)))
	@$(info )


# Display compiler version information.
gccversion :
	@$(CC) --version





# Create extended listing file from ELF output file.
$(BINDIR)$(TARGET).lss: $(BINDIR)$(TARGET)$(TARGET_EXT)
	@$(info )
	@$(info Creating Extended Listing: $@)
	@$(MD) $(@D)
	$(OBJDUMP) -h -S -C $< > $@

# Create full disasembly from ELF output file.
$(BINDIR)$(TARGET).dis: $(BINDIR)$(TARGET)$(TARGET_EXT)
	@$(info )
	@$(info Creating Full Disasembly: $@)
	@$(MD) $(@D)
	$(OBJDUMP) -D $< > $@


# Create a symbol table from ELF output file.
$(BINDIR)$(TARGET).sym: $(BINDIR)$(TARGET)$(TARGET_EXT)
	@$(info )
	@$(info Creating Symbol Table: $@)
	@$(MD) $(@D)
	$(NM) -n $< > $@


# Link: create ELF output file from object files.
.SECONDARY : $(BINDIR)$(TARGET)$(TARGET_EXT)
.PRECIOUS : $(ALL_OBJ)
$(BINDIR)$(TARGET)$(TARGET_EXT): $(ALL_OBJ)
	@$(info )
	@$(info Linking: $@)
	@$(MD) $(@D)
	$(CPP) $(THUMB) $(ALL_CFLAGS) $(LDFLAGS) $(ALL_OBJ) --output $@ $(LIBS)


# Link: create .a output file from object files.
.SECONDARY : $(BINDIR)$(TARGETLIB).a
.PRECIOUS : $(ALL_OBJ)
$(BINDIR)$(TARGETLIB).a: $(ALL_OBJ)
	@$(info )
	@$(info Linking: $@)
	@$(MD) $(@D)
	@cd $(OBJDIR)
	$(AR) rc $(BINDIR)$(TARGETLIB).a $(ALL_OBJ)
	@cd -


# Optimization -Os

# Compile: create object files from C source files. ARM/Thumb
$(COBJ_Os) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(THUMB) $(ALL_CFLAGS) $(CONLYFLAGS) -Os -c $< -o $@

# Compile: create object files from C source files. ARM-only
$(COBJ_ARMOs) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(ARM) $(ALL_CFLAGS) $(CONLYFLAGS) -Os -c $< -o $@

# Compile: create object files from C++ source files. ARM/Thumb
$(CPPOBJ_Os) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(THUMB) $(ALL_CFLAGS) $(CPPFLAGS) -Os -c $< -o $@

# Compile: create object files from C++ source files. ARM-only
$(CPPOBJ_ARMOs) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(ARM) $(ALL_CFLAGS) $(CPPFLAGS) -Os -c $< -o $@


# Optimization -O0

# Compile: create object files from C source files. ARM/Thumb
$(COBJ_O0) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(THUMB) $(ALL_CFLAGS) $(CONLYFLAGS) -O0 -c $< -o $@

# Compile: create object files from C source files. ARM-only
$(COBJ_ARMO0) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(ARM) $(ALL_CFLAGS) $(CONLYFLAGS) -O0 -c $< -o $@

# Compile: create object files from C++ source files. ARM/Thumb
$(CPPOBJ_O0) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(THUMB) $(ALL_CFLAGS) $(CPPFLAGS) -O0 -c $< -o $@

# Compile: create object files from C++ source files. ARM-only
$(CPPOBJ_ARMO0) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(ARM) $(ALL_CFLAGS) $(CPPFLAGS) -O0 -c $< -o $@


# Optimization -O1

# Compile: create object files from C source files. ARM/Thumb
$(COBJ_O1) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(THUMB) $(ALL_CFLAGS) $(CONLYFLAGS) -O1 -c $< -o $@

# Compile: create object files from C source files. ARM-only
$(COBJ_ARMO1) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(ARM) $(ALL_CFLAGS) $(CONLYFLAGS) -O1 -c $< -o $@

# Compile: create object files from C++ source files. ARM/Thumb
$(CPPOBJ_O1) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(THUMB) $(ALL_CFLAGS) $(CPPFLAGS) -O1 -c $< -o $@

# Compile: create object files from C++ source files. ARM-only
$(CPPOBJ_ARMO1) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(ARM) $(ALL_CFLAGS) $(CPPFLAGS) -O1 -c $< -o $@


# Optimization -O2

# Compile: create object files from C source files. ARM/Thumb
$(COBJ_O2) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(THUMB) $(ALL_CFLAGS) $(CONLYFLAGS) -O2 -c $< -o $@

# Compile: create object files from C source files. ARM-only
$(COBJ_ARMO2) : $(OBJDIR)%.o : %.c
	@$(info )
	@echo $(MSG_COMPILING_ARM) $<
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(ARM) $(ALL_CFLAGS) $(CONLYFLAGS) -O2 -c $< -o $@

# Compile: create object files from C++ source files. ARM/Thumb
$(CPPOBJ_O2) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(THUMB) $(ALL_CFLAGS) $(CPPFLAGS) -O2 -c $< -o $@

# Compile: create object files from C++ source files. ARM-only
$(CPPOBJ_ARMO2) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(ARM) $(ALL_CFLAGS) $(CPPFLAGS) -O2 -c $< -o $@



# Optimization -O3

# Compile: create object files from C source files. ARM/Thumb
$(COBJ_O3) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(THUMB) $(ALL_CFLAGS) $(CONLYFLAGS) -O3 -c $< -o $@

# Compile: create object files from C source files. ARM-only
$(COBJ_ARMO3) : $(OBJDIR)%.o : %.c
	@$(info )
	@$(info $(MSG_COMPILING_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(ARM) $(ALL_CFLAGS) $(CONLYFLAGS) -O3 -c $< -o $@

# Compile: create object files from C++ source files. ARM/Thumb
$(CPPOBJ_O3) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(THUMB) $(ALL_CFLAGS) $(CPPFLAGS) -O3 -c $< -o $@

# Compile: create object files from C++ source files. ARM-only
$(CPPOBJ_ARMO3) : $(OBJDIR)%.o : %.cpp
	@$(info )
	@$(info $(MSG_COMPILINGCPP_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CPP) $(ARM) $(ALL_CFLAGS) $(CPPFLAGS) -O3 -c $< -o $@


# Assemble: create object files from assembler source files. ARM/Thumb
$(AOBJ) : $(OBJDIR)%.o : %.S
	@$(info )
	@$(info $(MSG_ASSEMBLING) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(THUMB) $(AFLAGS) $(INCS) $(ADEFS) -c $< -o $@


# Assemble: create object files from assembler source files. ARM-only
$(AOBJ_ARM) : $(OBJDIR)%.o : %.S
	@$(info )
	@$(info $(MSG_ASSEMBLING_ARM) $<)
	@$(MD) $(@D) $(DEPDIR)$(@D)
	$(CC) $(ARM) $(AFLAGS) $(INCS) $(ADEFS) -c $< -o $@



# Target: clean project.
clean: cleandebug cleanrelease
cleandebug: begin clean_list celanobjdir celanbindir end
cleanrelease:
	@$(MAKE) BUILD_TYPE=release cleandebug

ifneq ($(firstword $(subst /, ,$(OBJDIR))),)
celanobjdir :
	@$(RM) $(firstword $(subst /, ,$(OBJDIR)))
else
celanobjdir :
endif

ifneq ($(firstword $(subst /, ,$(BINDIR))),)
celanbindir :
	@$(RM) $(firstword $(subst /, ,$(BINDIR)))
else
celanbindir :
endif

clean_list :
	@$(info )
	@echo Cleaning project:
	@$(RM) $(SRCOs:.c=.s)
	@$(RM) $(SRCO0:.c=.s)
	@$(RM) $(SRCO1:.c=.s)
	@$(RM) $(SRCO2:.c=.s)
	@$(RM) $(SRCO3:.c=.s)
	@$(RM) $(SRCOs:.c=.d)
	@$(RM) $(SRCO0:.c=.d)
	@$(RM) $(SRCO1:.c=.d)
	@$(RM) $(SRCO2:.c=.d)
	@$(RM) $(SRCO3:.c=.d)
	@$(RM) $(SRCOs:.c=.i)
	@$(RM) $(SRCO0:.c=.i)
	@$(RM) $(SRCO1:.c=.i)
	@$(RM) $(SRCO2:.c=.i)
	@$(RM) $(SRCO3:.c=.i)
	@$(RM) $(SRCARMOs:.c=.s)
	@$(RM) $(SRCARMO0:.c=.s)
	@$(RM) $(SRCARMO1:.c=.s)
	@$(RM) $(SRCARMO2:.c=.s)
	@$(RM) $(SRCARMO3:.c=.s)
	@$(RM) $(SRCARMOs:.c=.d)
	@$(RM) $(SRCARMO0:.c=.d)
	@$(RM) $(SRCARMO1:.c=.d)
	@$(RM) $(SRCARMO2:.c=.d)
	@$(RM) $(SRCARMO3:.c=.d)
	@$(RM) $(SRCARMOs:.c=.i)
	@$(RM) $(SRCARMO0:.c=.i)
	@$(RM) $(SRCARMO1:.c=.i)
	@$(RM) $(SRCARMO2:.c=.i)
	@$(RM) $(SRCARMO3:.c=.i)
	@$(RM) $(CPPSRCOs:.cpp=.s)
	@$(RM) $(CPPSRCO0:.cpp=.s)
	@$(RM) $(CPPSRCO1:.cpp=.s)
	@$(RM) $(CPPSRCO2:.cpp=.s)
	@$(RM) $(CPPSRCO3:.cpp=.s)
	@$(RM) $(CPPSRCOs:.cpp=.d)
	@$(RM) $(CPPSRCO0:.cpp=.d)
	@$(RM) $(CPPSRCO1:.cpp=.d)
	@$(RM) $(CPPSRCO2:.cpp=.d)
	@$(RM) $(CPPSRCO3:.cpp=.d)
	@$(RM) $(CPPSRCOs:.cpp=.i)
	@$(RM) $(CPPSRCO0:.cpp=.i)
	@$(RM) $(CPPSRCO1:.cpp=.i)
	@$(RM) $(CPPSRCO2:.cpp=.i)
	@$(RM) $(CPPSRCO3:.cpp=.i)
	@$(RM) $(CPPSRCARMOs:.cpp=.s)
	@$(RM) $(CPPSRCARMO0:.cpp=.s)
	@$(RM) $(CPPSRCARMO1:.cpp=.s)
	@$(RM) $(CPPSRCARMO2:.cpp=.s)
	@$(RM) $(CPPSRCARMO3:.cpp=.s)
	@$(RM) $(CPPSRCARMOs:.cpp=.d)
	@$(RM) $(CPPSRCARMO0:.cpp=.d)
	@$(RM) $(CPPSRCARMO1:.cpp=.d)
	@$(RM) $(CPPSRCARMO2:.cpp=.d)
	@$(RM) $(CPPSRCARMO3:.cpp=.d)
	@$(RM) $(CPPSRCARMOs:.cpp=.i)
	@$(RM) $(CPPSRCARMO0:.cpp=.i)
	@$(RM) $(CPPSRCARMO1:.cpp=.i)
	@$(RM) $(CPPSRCARMO2:.cpp=.i)
	@$(RM) $(CPPSRCARMO3:.cpp=.i)
#	@$(RM) $(BINDIR)$(TARGET).hex
#	@$(RM) $(BINDIR)$(TARGETLIB).a
	@$(RM) $(BINDIR)$(TARGET)$(TARGET_EXT)
	@$(RM) $(BINDIR)$(TARGET).map
	@$(RM) $(BINDIR)$(TARGET).a90
	@$(RM) $(BINDIR)$(TARGET).sym
	@$(RM) $(BINDIR)$(TARGET).lnk
	@$(RM) $(BINDIR)$(TARGET).dic
	@$(RM) $(BINDIR)$(TARGETLIB).a
	@$(RM) $(ALL_OBJ)
	@$(RM) $(LST)
	@$(RM) $(DEPDIR)
	@$(RM) coverage
	@$(RM) *.gcov


# Include the dependency files.
# -include $(shell mkdir .dep-$(BUILD_TYPE) 2>/dev/null) $(wildcard .dep-$(BUILD_TYPE)/*)
DEPS := $(ALL_OBJ:.o=.o.d)
-include $(addprefix $(DEPDIR),$(DEPS))


# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion build buildlib elf hex \
lss sym dis clean clean_i program debug release cleandebug cleanrelease clean_list \
celanobjdir celanbindir coverage

