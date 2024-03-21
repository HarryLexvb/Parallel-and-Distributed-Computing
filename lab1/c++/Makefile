# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Source directories
SRCDIRS := src
INCDIRS := include

# Source files
SRCS := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
OBJS := $(SRCS:.cpp=.o)
HEADERS := $(foreach dir,$(INCDIRS),$(wildcard $(dir)/*.h))

# Executable name
TARGET = run

# Default target
all: $(TARGET)

# Linking object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compilation
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

