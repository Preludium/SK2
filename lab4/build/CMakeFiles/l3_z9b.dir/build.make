# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/mikol/Desktop/SK2/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/mikol/Desktop/SK2/lab4/build

# Include any dependencies generated for this target.
include CMakeFiles/l3_z9b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/l3_z9b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/l3_z9b.dir/flags.make

CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o: CMakeFiles/l3_z9b.dir/flags.make
CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o: ../l3_z9b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mikol/Desktop/SK2/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o -c /mnt/c/Users/mikol/Desktop/SK2/lab4/l3_z9b.cpp

CMakeFiles/l3_z9b.dir/l3_z9b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l3_z9b.dir/l3_z9b.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mikol/Desktop/SK2/lab4/l3_z9b.cpp > CMakeFiles/l3_z9b.dir/l3_z9b.cpp.i

CMakeFiles/l3_z9b.dir/l3_z9b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l3_z9b.dir/l3_z9b.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mikol/Desktop/SK2/lab4/l3_z9b.cpp -o CMakeFiles/l3_z9b.dir/l3_z9b.cpp.s

CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.requires:

.PHONY : CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.requires

CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.provides: CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.requires
	$(MAKE) -f CMakeFiles/l3_z9b.dir/build.make CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.provides.build
.PHONY : CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.provides

CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.provides.build: CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o


# Object files for target l3_z9b
l3_z9b_OBJECTS = \
"CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o"

# External object files for target l3_z9b
l3_z9b_EXTERNAL_OBJECTS =

l3_z9b: CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o
l3_z9b: CMakeFiles/l3_z9b.dir/build.make
l3_z9b: CMakeFiles/l3_z9b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/mikol/Desktop/SK2/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable l3_z9b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/l3_z9b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/l3_z9b.dir/build: l3_z9b

.PHONY : CMakeFiles/l3_z9b.dir/build

CMakeFiles/l3_z9b.dir/requires: CMakeFiles/l3_z9b.dir/l3_z9b.cpp.o.requires

.PHONY : CMakeFiles/l3_z9b.dir/requires

CMakeFiles/l3_z9b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/l3_z9b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/l3_z9b.dir/clean

CMakeFiles/l3_z9b.dir/depend:
	cd /mnt/c/Users/mikol/Desktop/SK2/lab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/mikol/Desktop/SK2/lab4 /mnt/c/Users/mikol/Desktop/SK2/lab4 /mnt/c/Users/mikol/Desktop/SK2/lab4/build /mnt/c/Users/mikol/Desktop/SK2/lab4/build /mnt/c/Users/mikol/Desktop/SK2/lab4/build/CMakeFiles/l3_z9b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/l3_z9b.dir/depend

