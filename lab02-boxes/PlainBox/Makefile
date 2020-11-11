#
# Makefile for Generating C++ executables
#
# CSCI 232 - Data Structures and Algorithms
#
# Phillip J. Curtiss, Associate Professor
# Computer Science Department, Montana Tech
#
# Lab02-Boxes
#
# Specify the Course Below
COURSE = CSCI232 Data Structures and Algorithms
# Specify the Project Name below
PROJ =	Lab02-Boxes: Classes and Inheritence 
#
# Project Files Specified Below
##
# Source files should be added to the SRCS variable
SRCS1 = driver-typedef.cpp PlainBoxTypeDef.cpp
SRCS2 =	driver.cpp PlainBox.cpp
# Object files will be inferred from soruce files; adjust as needed
OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 =	$(SRCS2:.cpp=.o)
# Dependency files will be inferred from source files; adjust as needed
DEPS =	$(SRCS1:.cpp=.dep) $(SRCS2:.cpp=.dep)
# List all targets this Makefile is to create from source files
TARGET1 = driver-typedef
TARGET2 = driver

###################################################
# Should Not need to modify lines of Makefile below
#
# g++ compiler flags; standard is C++14; level-3 optimization
CXXFLAGS = -std=gnu++17 -O3 -Wall -Werror
# Additional Library Search Paths specified below
LDFLAGS = 
# Additional Libraries to link in with executable below
LDLIBS = 

#
# Provide Make with additionally known suffixes
.SUFFIXES:	.dia .dep .tex .md

# Default rule to make if no target specified
# (make dependencies first, then all targets)
default: $(DEPS) $(TARGET1) $(TARGET2) 

# Rules to generate targets
# Note: If more than one target, might need multiple rules
#       of the form below
$(TARGET1): $(OBJS1)
	$(CXX) -o $@ $^

$(TARGET2): $(OBJS2)
	$(CXX) -o $@ $^

# Make dependency file for each source file
# include all dependency files so Make can 
# conditionally make required project file
%.dep: %.cpp
	$(CXX) -MM $< -o $@
-include $(DEPS)

#
# Clean up Intermediate files and targets
.PHONY: clean doxygen
clean: 
	-$(RM) $(DEPS) $(OBJS1) $(OBJS2) $(TARGET1) $(TARGET2)

#
# Generate Documentation for project files
Doxyfile:
	-doxygen -g
	-sed -r -i 's/(^PROJECT_NAME\s*=).*$$/\1 \"$(COURSE)\"/' $@
	-sed -r -i 's/(^PROJECT_BRIEF\s*=).*$$/\1 \"$(PROJ)\"/' $@
	-sed -r -i 's/(^OUTPUT_DIRECTORY\s*=).*$$/\1 doc/' $@
	-sed -r -i 's/(^GENERATE_TREEVIEW\s*=).*$$/\1 YES/' $@

doxygen: Doxyfile
	-doxygen $^


