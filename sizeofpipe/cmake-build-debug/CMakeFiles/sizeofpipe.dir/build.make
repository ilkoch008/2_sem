# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/progi/sizeofpipe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/progi/sizeofpipe/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sizeofpipe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sizeofpipe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sizeofpipe.dir/flags.make

CMakeFiles/sizeofpipe.dir/main.c.o: CMakeFiles/sizeofpipe.dir/flags.make
CMakeFiles/sizeofpipe.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/progi/sizeofpipe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sizeofpipe.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sizeofpipe.dir/main.c.o   -c /home/ilya/progi/sizeofpipe/main.c

CMakeFiles/sizeofpipe.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sizeofpipe.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ilya/progi/sizeofpipe/main.c > CMakeFiles/sizeofpipe.dir/main.c.i

CMakeFiles/sizeofpipe.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sizeofpipe.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ilya/progi/sizeofpipe/main.c -o CMakeFiles/sizeofpipe.dir/main.c.s

# Object files for target sizeofpipe
sizeofpipe_OBJECTS = \
"CMakeFiles/sizeofpipe.dir/main.c.o"

# External object files for target sizeofpipe
sizeofpipe_EXTERNAL_OBJECTS =

sizeofpipe: CMakeFiles/sizeofpipe.dir/main.c.o
sizeofpipe: CMakeFiles/sizeofpipe.dir/build.make
sizeofpipe: CMakeFiles/sizeofpipe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/progi/sizeofpipe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sizeofpipe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sizeofpipe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sizeofpipe.dir/build: sizeofpipe

.PHONY : CMakeFiles/sizeofpipe.dir/build

CMakeFiles/sizeofpipe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sizeofpipe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sizeofpipe.dir/clean

CMakeFiles/sizeofpipe.dir/depend:
	cd /home/ilya/progi/sizeofpipe/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/progi/sizeofpipe /home/ilya/progi/sizeofpipe /home/ilya/progi/sizeofpipe/cmake-build-debug /home/ilya/progi/sizeofpipe/cmake-build-debug /home/ilya/progi/sizeofpipe/cmake-build-debug/CMakeFiles/sizeofpipe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sizeofpipe.dir/depend
