

GCC_DIR := C:/Users/Dell/Downloads/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi/
CC = $(GCC_DIR)/bin/arm-none-eabi-gcc
LD_FILE := LINKER/stm_ls.ld

# Include Files
INC_DIRS += Driver/GPIO/inc \
			Driver/UART/inc
INC_FILES = $(foreach INC_DIRS, $(INC_DIRS), $(wildcard $(INC_DIRS)/*))

# Source Files
SRC_DIRS += Driver/GPIO/src
SRC_FILES = $(foreach SRC_DIRS, $(SRC_DIRS), $(wildcard $(SRC_DIRS)/*))

CHIP=cortex-m3

CC_INC = $(foreach INC_DIRS,$(INC_DIRS), -I$(INC_DIRS)) 

CCFLAGS= -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIRS)
LDFLAGS= -nostdlib -T $(LD_FILE) -Wl,-Map=Output/GPIO.map

build: Output/GPIO.hex
	@echo "----->Build xong"

Output/main.o: User/src/main.c
	$(CC) $(CCFLAGS) $^ -o $@
Output/GPIO.o: Driver/GPIO/src/GPIO.c
	$(CC) $(CCFLAGS) $^ -o $@ 
Output/stm32_startup.o: Startup/stm32_startup.c
	$(CC) $(CCFLAGS) $^ -o $@
	
Output/GPIO.elf: Output/main.o Output/GPIO.o Output/stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@ 
	
Output/GPIO.hex: Output/GPIO.elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"

run: 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -ME
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -p "Output/GPIO.hex" 0x08000000 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -rst
	@echo "----->Running"


clean:
	rm -rf ./Output/*

print-%:
	@echo $($(subst print-,,$@))




