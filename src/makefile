# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Iheader/ 
LDFLAGS := 
TARGET := build/program

# Source directories
SRC_DIR := .
C_DIR := c
HEADERS_DIR := headers
BUILD_DIR := build

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/*.c) \
         $(wildcard $(C_DIR)/*.c)

# Generate object file names in build directory
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, \
         $(filter $(SRC_DIR)/%, $(SRCS)))
OBJS += $(patsubst $(C_DIR)/%.c,$(BUILD_DIR)/c/%.o, \
         $(filter $(C_DIR)/%, $(SRCS)))

# Default target
all: $(TARGET)

# Link all objects into executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ -o $@

# Compile main.c
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile c/*.c files
$(BUILD_DIR)/c/%.o: $(C_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Print variables (for debugging)
.PHONY: vars
vars:
	@echo "Sources: $(SRCS)"
	@echo "Objects: $(OBJS)"
	@echo "Target: $(TARGET)"