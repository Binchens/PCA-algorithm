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
CMAKE_SOURCE_DIR = /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled

# Include any dependencies generated for this target.
include libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/depend.make

# Include the progress variables for this target.
include libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/progress.make

# Include the compile flags for this target's objects.
include libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o: libs/orcc-runtime/src/dataflow.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/dataflow.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/dataflow.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/dataflow.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/dataflow.c > CMakeFiles/orcc-runtime.dir/src/dataflow.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/dataflow.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/dataflow.c -o CMakeFiles/orcc-runtime.dir/src/dataflow.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o: libs/orcc-runtime/src/graph.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/graph.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/graph.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/graph.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/graph.c > CMakeFiles/orcc-runtime.dir/src/graph.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/graph.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/graph.c -o CMakeFiles/orcc-runtime.dir/src/graph.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o: libs/orcc-runtime/src/options.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/options.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/options.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/options.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/options.c > CMakeFiles/orcc-runtime.dir/src/options.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/options.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/options.c -o CMakeFiles/orcc-runtime.dir/src/options.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o: libs/orcc-runtime/src/scheduler.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/scheduler.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/scheduler.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/scheduler.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/scheduler.c > CMakeFiles/orcc-runtime.dir/src/scheduler.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/scheduler.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/scheduler.c -o CMakeFiles/orcc-runtime.dir/src/scheduler.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o: libs/orcc-runtime/src/trace.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/trace.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/trace.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/trace.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/trace.c > CMakeFiles/orcc-runtime.dir/src/trace.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/trace.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/trace.c -o CMakeFiles/orcc-runtime.dir/src/trace.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o: libs/orcc-runtime/src/util.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/util.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/util.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/util.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/util.c > CMakeFiles/orcc-runtime.dir/src/util.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/util.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/util.c -o CMakeFiles/orcc-runtime.dir/src/util.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o: libs/orcc-runtime/src/mapping.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/mapping.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/mapping.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/mapping.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/mapping.c > CMakeFiles/orcc-runtime.dir/src/mapping.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/mapping.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/mapping.c -o CMakeFiles/orcc-runtime.dir/src/mapping.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o: libs/orcc-runtime/src/profiling.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/profiling.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/profiling.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/profiling.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/profiling.c > CMakeFiles/orcc-runtime.dir/src/profiling.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/profiling.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/profiling.c -o CMakeFiles/orcc-runtime.dir/src/profiling.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o: libs/orcc-runtime/src/getopt.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/getopt.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/getopt.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/getopt.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/getopt.c > CMakeFiles/orcc-runtime.dir/src/getopt.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/getopt.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/getopt.c -o CMakeFiles/orcc-runtime.dir/src/getopt.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/flags.make
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o: libs/orcc-runtime/src/serialize.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/orcc-runtime.dir/src/serialize.c.o   -c /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/serialize.c

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/orcc-runtime.dir/src/serialize.c.i"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/serialize.c > CMakeFiles/orcc-runtime.dir/src/serialize.c.i

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/orcc-runtime.dir/src/serialize.c.s"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/src/serialize.c -o CMakeFiles/orcc-runtime.dir/src/serialize.c.s

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.requires:
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.provides: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.requires
	$(MAKE) -f libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.provides.build
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.provides

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.provides.build: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o

# Object files for target orcc-runtime
orcc__runtime_OBJECTS = \
"CMakeFiles/orcc-runtime.dir/src/dataflow.c.o" \
"CMakeFiles/orcc-runtime.dir/src/graph.c.o" \
"CMakeFiles/orcc-runtime.dir/src/options.c.o" \
"CMakeFiles/orcc-runtime.dir/src/scheduler.c.o" \
"CMakeFiles/orcc-runtime.dir/src/trace.c.o" \
"CMakeFiles/orcc-runtime.dir/src/util.c.o" \
"CMakeFiles/orcc-runtime.dir/src/mapping.c.o" \
"CMakeFiles/orcc-runtime.dir/src/profiling.c.o" \
"CMakeFiles/orcc-runtime.dir/src/getopt.c.o" \
"CMakeFiles/orcc-runtime.dir/src/serialize.c.o"

# External object files for target orcc-runtime
orcc__runtime_EXTERNAL_OBJECTS =

libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build.make
libs/orcc-runtime/liborcc-runtime.a: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library liborcc-runtime.a"
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && $(CMAKE_COMMAND) -P CMakeFiles/orcc-runtime.dir/cmake_clean_target.cmake
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/orcc-runtime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build: libs/orcc-runtime/liborcc-runtime.a
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/build

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/dataflow.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/graph.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/options.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/scheduler.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/trace.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/util.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/mapping.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/profiling.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/getopt.c.o.requires
libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires: libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/src/serialize.c.o.requires
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/requires

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/clean:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime && $(CMAKE_COMMAND) -P CMakeFiles/orcc-runtime.dir/cmake_clean.cmake
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/clean

libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/depend:
	cd /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime /home/skynet/instalador/instalador_prueba/project/hsi_system_Optimized_v1.0/compiled/libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/orcc-runtime/CMakeFiles/orcc-runtime.dir/depend

