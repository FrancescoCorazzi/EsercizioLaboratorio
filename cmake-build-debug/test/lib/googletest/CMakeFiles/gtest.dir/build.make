# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/coraz/CLionProjects/EsLaboratorio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug

# Include any dependencies generated for this target.
include test/lib/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include test/lib/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include test/lib/googletest/CMakeFiles/gtest.dir/flags.make

test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: test/lib/googletest/CMakeFiles/gtest.dir/flags.make
test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../test/lib/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/coraz/CLionProjects/EsLaboratorio/test/lib/googletest/src/gtest-all.cc

test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/coraz/CLionProjects/EsLaboratorio/test/lib/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/coraz/CLionProjects/EsLaboratorio/test/lib/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

test/lib/googletest/libgtestd.a: test/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
test/lib/googletest/libgtestd.a: test/lib/googletest/CMakeFiles/gtest.dir/build.make
test/lib/googletest/libgtestd.a: test/lib/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtestd.a"
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/lib/googletest/CMakeFiles/gtest.dir/build: test/lib/googletest/libgtestd.a

.PHONY : test/lib/googletest/CMakeFiles/gtest.dir/build

test/lib/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : test/lib/googletest/CMakeFiles/gtest.dir/clean

test/lib/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/coraz/CLionProjects/EsLaboratorio /home/coraz/CLionProjects/EsLaboratorio/test/lib/googletest /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest /home/coraz/CLionProjects/EsLaboratorio/cmake-build-debug/test/lib/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/lib/googletest/CMakeFiles/gtest.dir/depend

