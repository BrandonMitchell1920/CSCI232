#
# Makefile for Generating C++ Executables
#
# CSCI 232 Data Structures and Algorithms
# 
# Phillip J. Curtiss, Associate Professor
# Department of Computer Science, Montana Tech
# pcurtiss@mtech.edu, 406-496-4807
#
# Lab Bag ADT

# Define Macros 
CFLAGS= -std=c++17 -O3 -Wall -Werror

# Target Builds
TARGET= driver

# Build ALL Rule
all: $(TARGET)

# Explicit Rules
driver: driver.o Bag.o 
	$(CXX) -o $@ $^

# Implicit Rules
.cpp.o:
	$(CXX) $(CFLAGS) -c $<

.PHONY: clean

clean:
	$(RM) *.o $(TARGET)

# Dependency Lists
driver.o: driver.cpp Bag.h BagInterface.h
Bag.o: Bag.cpp Bag.h BagInterface.h