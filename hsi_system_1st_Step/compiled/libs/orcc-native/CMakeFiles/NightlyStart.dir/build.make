# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled

# Utility rule file for NightlyStart.

# Include the progress variables for this target.
include libs/orcc-native/CMakeFiles/NightlyStart.dir/progress.make

libs/orcc-native/CMakeFiles/NightlyStart:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled/libs/orcc-native && /usr/bin/ctest -D NightlyStart

NightlyStart: libs/orcc-native/CMakeFiles/NightlyStart
NightlyStart: libs/orcc-native/CMakeFiles/NightlyStart.dir/build.make
.PHONY : NightlyStart

# Rule to build all files generated by this target.
libs/orcc-native/CMakeFiles/NightlyStart.dir/build: NightlyStart
.PHONY : libs/orcc-native/CMakeFiles/NightlyStart.dir/build

libs/orcc-native/CMakeFiles/NightlyStart.dir/clean:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled/libs/orcc-native && $(CMAKE_COMMAND) -P CMakeFiles/NightlyStart.dir/cmake_clean.cmake
.PHONY : libs/orcc-native/CMakeFiles/NightlyStart.dir/clean

libs/orcc-native/CMakeFiles/NightlyStart.dir/depend:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled/libs/orcc-native /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled/libs/orcc-native /home/skynet/instalador/instalador_prueba/project/hsi_system_1st_Step/compiled/libs/orcc-native/CMakeFiles/NightlyStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/orcc-native/CMakeFiles/NightlyStart.dir/depend
