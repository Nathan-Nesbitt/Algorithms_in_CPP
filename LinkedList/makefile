# Compiler 
CC=g++

# Flags
# 	-g		Adds debugging information
#	-Wall	Turns on most compiler warnings
CFLAGS = -g -Wall

# Setting the target executable
TARGET = linked_list_example

# Specify other header directories than /usr/include
INCLUDES = -I../generic_elements

# Specify C source files
SRCS = linked_list.c 

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(TARGET).cpp

# Removes all of the files we created 
clean:
	$(RM) $(TARGET)
