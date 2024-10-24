# Toolchain
TOOLCHAIN = /projects/mipssw/toolchains/riscv-elf/v3.01/bin/riscv32-mti-elf-

# Compiler
CC = $(TOOLCHAIN)gcc

# Compiler flags
CFLAGS = -frecord-gcc-switches -g

# Include directory
INCLUDE_DIR =./inc

# Target executable
TARGET = CFFT_1024_FP32.elf

# Source files
SRCS = $(wildcard src/*.c) $(wildcard src/*.S) #Benchmark_TransformFunctions1.c 

# Object files
OBJS = $(SRCS:.c=.o) 

# Default target
all: $(TARGET) disassembly

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

#Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

disassembly: $(TARGET)
	$(TOOLCHAIN)objdump -d -S $(TARGET) > $(TARGET).dis

# Clean up build files
clean:
	rm -f $(TARGET) $(TARGET).dis src/*.o

# Phony targets
.PHONY: all clean

