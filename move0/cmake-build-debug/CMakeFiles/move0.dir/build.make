# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /opt/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmas/job_interview/cpp/move0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmas/job_interview/cpp/move0/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/move0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/move0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/move0.dir/flags.make

CMakeFiles/move0.dir/main.cpp.o: CMakeFiles/move0.dir/flags.make
CMakeFiles/move0.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmas/job_interview/cpp/move0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/move0.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/move0.dir/main.cpp.o -c /home/dmas/job_interview/cpp/move0/main.cpp

CMakeFiles/move0.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move0.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmas/job_interview/cpp/move0/main.cpp > CMakeFiles/move0.dir/main.cpp.i

CMakeFiles/move0.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move0.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmas/job_interview/cpp/move0/main.cpp -o CMakeFiles/move0.dir/main.cpp.s

# Object files for target move0
move0_OBJECTS = \
"CMakeFiles/move0.dir/main.cpp.o"

# External object files for target move0
move0_EXTERNAL_OBJECTS =

move0: CMakeFiles/move0.dir/main.cpp.o
move0: CMakeFiles/move0.dir/build.make
move0: CMakeFiles/move0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmas/job_interview/cpp/move0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable move0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/move0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/move0.dir/build: move0

.PHONY : CMakeFiles/move0.dir/build

CMakeFiles/move0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/move0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/move0.dir/clean

CMakeFiles/move0.dir/depend:
	cd /home/dmas/job_interview/cpp/move0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmas/job_interview/cpp/move0 /home/dmas/job_interview/cpp/move0 /home/dmas/job_interview/cpp/move0/cmake-build-debug /home/dmas/job_interview/cpp/move0/cmake-build-debug /home/dmas/job_interview/cpp/move0/cmake-build-debug/CMakeFiles/move0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/move0.dir/depend

