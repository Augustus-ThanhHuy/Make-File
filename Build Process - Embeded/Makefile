

GCC_DIR := C:/Users/Dell/Downloads/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi/
CC = $(GCC_DIR)/bin/arm-none-eabi-gcc
LD_FILE := LINKER/stm_ls.ld

PATH_OUTPUT := ./Output

# Include Files
INC_DIRS += Driver/GPIO/inc \
			Driver/UART/inc
INC_FILES += $(foreach INC_DIRS, $(INC_DIRS), $(wildcard $(INC_DIRS)/*))

# Source Files
SRC_DIRS += Driver/GPIO/src
SRC_FILES += $(foreach SRC_DIRS, $(SRC_DIRS), $(wildcard $(SRC_DIRS)/*))

# CC Opt for INC_DIRS
INC_DIRS_OPT = $(foreach INC_DIRS,$(INC_DIRS), -I$(INC_DIRS)) 

CHIP=cortex-m3

CCFLAGS= -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIRS_OPT)
LDFLAGS= -nostdlib -T $(LD_FILE) -Wl,-Map=$(PATH_OUTPUT)/GPIO.map

build: $(PATH_OUTPUT)/GPIO.hex
	@echo "----->Build xong"

$(PATH_OUTPUT)/main.o: User/src/main.c
	$(CC) $(CCFLAGS) $^ -o $@
$(PATH_OUTPUT)/GPIO.o: $(SRC_DIRS)/GPIO.c
	$(CC) $(CCFLAGS) $^ -o $@ 
$(PATH_OUTPUT)/stm32_startup.o: Startup/stm32_startup.c
	$(CC) $(CCFLAGS) $^ -o $@
	
$(PATH_OUTPUT)/GPIO.elf: $(PATH_OUTPUT)/main.o $(PATH_OUTPUT)/GPIO.o $(PATH_OUTPUT)/stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@ 
	
$(PATH_OUTPUT)/GPIO.hex: $(PATH_OUTPUT)/GPIO.elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"

run: 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -ME
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -p "$(PATH_OUTPUT)/GPIO.hex" 0x08000000 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -rst
	@echo "----->Running"


clean:
	rm -rf ./$(PATH_OUTPUT)/*

print-%:
	@echo $($(subst print-,,$@))




