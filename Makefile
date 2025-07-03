CC = gcc
# cross compiler
CC_RPI = aarch64-linux-gnu-gcc
# Source file - main.c appTimer.c LEDDisplay.c
SRC = $(wildcard *.c appTimer/*.c LEDDisplay/*.c)
ASM = $(patsubst %.c,release/%.s,$(notdir $(SRC)))
OBJ = $(patsubst %.c,release/%.o,$(notdir $(SRC)))
DBG = $(patsubst %.c,debug/%.o,$(notdir $(SRC)))
WFLAGS = -Wall -Werror -Wextra  
# Included directories
INCLUDE_DIR += -IappTimer -ILEDDisplay -I.
FOLDER = release debug
VPATH = appTimer LEDDisplay

# create release and debug folders
create_dir:
	mkdir -p $(FOLDER)

# To create object,assembly,debug files
linux : files_asm files_obj files_dbg

# To create Assembly files in release folder
files_asm : create_dir $(ASM)
release/%.s : %.c
	$(CC) -S $(WFLAGS) $(INCLUDE_DIR) $< -o $@

# To create object files in release folder
files_obj : create_dir $(OBJ)
release/%.o : %.c
	$(CC) -c $(WFLAGS) $(INCLUDE_DIR) $< -o $@

# To create Debug files in debug folder
files_dbg : create_dir $(DBG)
debug/%.o : %.c
	$(CC) -g -O0 -c $(WFLAGS) $(INCLUDE_DIR) $< -o $@

# To create executable file in release folder
all : linux rpi 
	$(CC) $(WFLAGS) $(INCLUDE_DIR) $(OBJ) -o release/appTimer.exe

# To create Executable binary files in release folder
rpi : create_dir
	$(CC_RPI) $(WFLAGS) $(INCLUDE_DIR) $(SRC) -o release/AppTimerBinary

# To clear release and debug folder.
clean : 
	rm -rf $(FOLDER)
