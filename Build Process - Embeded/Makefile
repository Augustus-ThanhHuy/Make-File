

GCC_DIR := C:/Users/Dell/Downloads/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi/
CC = $(GCC_DIR)/bin/arm-none-eabi-gcc
LD_FILE := LINKER/stm_ls.ld
INC_DIR := Driver/GPIO/inc

CHIP=cortex-m3

CCFLAGS= -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
LDFLAGS= -nostdlib -T $(LD_FILE) -Wl,-Map=Output/GPIO.map

build: Output/GPIO.hex

Output/main.o: User/src/main.c
	$(CC) $(CCFLAGS) User/src/main.c -o Output/main.o 
Output/GPIO.o: Driver/GPIO/src/GPIO.c
	$(CC) $(CCFLAGS) Driver/GPIO/src/GPIO.c -o Output/GPIO.o 
Output/stm32_startup.o: Startup/stm32_startup.c
	$(CC) $(CCFLAGS)  Startup/stm32_startup.c -o Output/stm32_startup.o
	
Output/GPIO.elf: Output/main.o Output/GPIO.o Output/stm32_startup.o
	$(CC) $(LDFLAGS) -o Output/GPIO.elf Output/main.o Output/GPIO.o Output/stm32_startup.o 
	
Output/GPIO.hex: Output/GPIO.elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "Output/GPIO.elf" "Output/GPIO.hex"

run: 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -ME
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -p "Output/GPIO.hex" 0x08000000 
	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -rst
	

clean:
	rm -rf ./Output/*




# GCC_DIR := C:/Users/Dell/Downloads/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi/
# GCC = $(GCC_DIR)/bin/arm-none-eabi-gcc
# OBJ = $(GCC_DIR)/arm-none-eabi/bin/objcopy.exe
# LK_DIR := LINKER/stm_ls.ld
# CHIP = cortex-m3
# INC_DIR := Driver/GPIO/inc/

# CCFLAGS := -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
# LDFLAGS := -nostdlib -T $(LK_DIR) -Wl,-Map=Output/GPIO.map 

# build: Output/GPIO.hex
# 	@echo "----->Build xong"
# Output/main.o: User/src/main.c
# 	$(GCC) $(CCFLAGS) User/src/main.c -o Output/main.o

# Output/GPIO.o: Driver/GPIO/src/GPIO.c
# 	$(GCC) $(CCFLAGS) Driver/GPIO/src/GPIO.c -o Output/GPIO.o

# Output/stm32_startup.o: Startup/stm32_startup.c
# 	$(GCC) $(CCFLAGS) Startup/stm32_startup.c -o Output/stm32_startup.o

# Output/GPIO.elf: Output/main.o Output/GPIO.o Output/stm32_startup.o
# 	$(GCC) $(LDFLAGS) Output/main.o Output/GPIO.o Output/stm32_startup.o -o Output/GPIO.elf

# Output/GPIO.hex: Output/GPIO.elf
# 	$(OBJ) -O ihex "Output/GPIO.elf" "Output/GPIO.hex"

# run:
# 	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -ME
# 	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -p "Output/GPIO.hex" 0x08000000 
# 	./Tools/ST-LINKUtility/ST-LINK_CLI.exe -rst
# 	@echo "----->Running"

# clean:
# 	rm -rf ./Output/*
