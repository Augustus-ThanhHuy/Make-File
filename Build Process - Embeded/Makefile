

GCC_DIR := C:/Users/Dell/Downloads/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi/
CC = $(GCC_DIR)/bin/arm-none-eabi-gcc
LD_FILE := LINKER/stm_ls.ld

MODULE := GPIO
PATH_OUTPUT := ./Output

# Include Files
INC_DIRS += Driver/$(MODULE)/inc \
			User/inc
INC_FILES += $(foreach INC_DIRS, $(INC_DIRS), $(wildcard $(INC_DIRS)/*))

# Source Files
SRC_DIRS += Driver/$(MODULE)/src \
			User/src \
			Startup

SRC_FILES += $(foreach SRC_DIRS, $(SRC_DIRS), $(wildcard $(SRC_DIRS)/*))

# CC Opt for INC_DIRS
INC_DIRS_OPT = $(foreach INC_DIRS,$(INC_DIRS), -I$(INC_DIRS)) 

# ObJect Files
OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o, $(OBJ_FILES))
PATH_OBJS := $(foreach OBJ_FILES, $(OBJ_FILES), $(PATH_OUTPUT)/$(OBJ_FILES))

CHIP=cortex-m3

CCFLAGS= -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 $(INC_DIRS_OPT)
LDFLAGS= -nostdlib -T $(LD_FILE) -Wl,-Map=$(PATH_OUTPUT)/$(MODULE).map

vpath %.c $(SRC_DIRS)

build: $(PATH_OUTPUT)/$(MODULE).hex
	@echo "----->Build xong"

%.o:%.c
	$(CC) $(CCFLAGS) $^ -o $(PATH_OUTPUT)/$@

	
$(PATH_OUTPUT)/$(MODULE).elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS)  -o $@ $(PATH_OBJS)
	
$(PATH_OUTPUT)/$(MODULE).hex: $(PATH_OUTPUT)/$(MODULE).elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"

run: 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -ME
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -p "$(PATH_OUTPUT)/$(MODULE).hex" 0x08000000 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -rst
	@echo "----->Running"


clean:
	rm -rf ./$(PATH_OUTPUT)/*

print-%:
	@echo $($(subst print-,,$@))




