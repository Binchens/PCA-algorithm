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
CMAKE_SOURCE_DIR = /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled

# Include any dependencies generated for this target.
include libs/roxml/CMakeFiles/roxml.dir/depend.make

# Include the progress variables for this target.
include libs/roxml/CMakeFiles/roxml.dir/progress.make

# Include the compile flags for this target's objects.
include libs/roxml/CMakeFiles/roxml.dir/flags.make

libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o: libs/roxml/CMakeFiles/roxml.dir/flags.make
libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o: libs/roxml/src/roxml-parse-engine.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml-parse-engine.c

libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/roxml.dir/src/roxml-parse-engine.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml-parse-engine.c > CMakeFiles/roxml.dir/src/roxml-parse-engine.c.i

libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/roxml.dir/src/roxml-parse-engine.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml-parse-engine.c -o CMakeFiles/roxml.dir/src/roxml-parse-engine.c.s

libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.requires:
.PHONY : libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.requires

libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.provides: libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.requires
	$(MAKE) -f libs/roxml/CMakeFiles/roxml.dir/build.make libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.provides.build
.PHONY : libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.provides

libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.provides.build: libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o

libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o: libs/roxml/CMakeFiles/roxml.dir/flags.make
libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o: libs/roxml/src/roxml.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/roxml.dir/src/roxml.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml.c

libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/roxml.dir/src/roxml.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml.c > CMakeFiles/roxml.dir/src/roxml.c.i

libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/roxml.dir/src/roxml.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml.c -o CMakeFiles/roxml.dir/src/roxml.c.s

libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.requires:
.PHONY : libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.requires

libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.provides: libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.requires
	$(MAKE) -f libs/roxml/CMakeFiles/roxml.dir/build.make libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.provides.build
.PHONY : libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.provides

libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.provides.build: libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o

libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o: libs/roxml/CMakeFiles/roxml.dir/flags.make
libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o: libs/roxml/src/roxml-internal.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/roxml.dir/src/roxml-internal.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml-internal.c

libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/roxml.dir/src/roxml-internal.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml-internal.c > CMakeFiles/roxml.dir/src/roxml-internal.c.i

libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/roxml.dir/src/roxml-internal.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/src/roxml-internal.c -o CMakeFiles/roxml.dir/src/roxml-internal.c.s

libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.requires:
.PHONY : libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.requires

libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.provides: libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.requires
	$(MAKE) -f libs/roxml/CMakeFiles/roxml.dir/build.make libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.provides.build
.PHONY : libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.provides

libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.provides.build: libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o

# Object files for target roxml
roxml_OBJECTS = \
"CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o" \
"CMakeFiles/roxml.dir/src/roxml.c.o" \
"CMakeFiles/roxml.dir/src/roxml-internal.c.o"

# External object files for target roxml
roxml_EXTERNAL_OBJECTS =

libs/roxml/libroxml.a: libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o
libs/roxml/libroxml.a: libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o
libs/roxml/libroxml.a: libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o
libs/roxml/libroxml.a: libs/roxml/CMakeFiles/roxml.dir/build.make
libs/roxml/libroxml.a: libs/roxml/CMakeFiles/roxml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libroxml.a"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && $(CMAKE_COMMAND) -P CMakeFiles/roxml.dir/cmake_clean_target.cmake
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roxml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/roxml/CMakeFiles/roxml.dir/build: libs/roxml/libroxml.a
.PHONY : libs/roxml/CMakeFiles/roxml.dir/build

libs/roxml/CMakeFiles/roxml.dir/requires: libs/roxml/CMakeFiles/roxml.dir/src/roxml-parse-engine.c.o.requires
libs/roxml/CMakeFiles/roxml.dir/requires: libs/roxml/CMakeFiles/roxml.dir/src/roxml.c.o.requires
libs/roxml/CMakeFiles/roxml.dir/requires: libs/roxml/CMakeFiles/roxml.dir/src/roxml-internal.c.o.requires
.PHONY : libs/roxml/CMakeFiles/roxml.dir/requires

libs/roxml/CMakeFiles/roxml.dir/clean:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml && $(CMAKE_COMMAND) -P CMakeFiles/roxml.dir/cmake_clean.cmake
.PHONY : libs/roxml/CMakeFiles/roxml.dir/clean

libs/roxml/CMakeFiles/roxml.dir/depend:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml /home/skynet/instalador/instalador_prueba/project/hsi_system/compiled/libs/roxml/CMakeFiles/roxml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/roxml/CMakeFiles/roxml.dir/depend

