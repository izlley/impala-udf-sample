# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_SOURCE_DIR = /home/leejy/work/impala

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leejy/work/impala

# Utility rule file for udf-sample-ir.

be/src/udf_samples/CMakeFiles/udf-sample-ir: be/build/release/udf_samples/udf-sample.ll

be/build/release/udf_samples/udf-sample.ll: be/src/udf_samples/udf-sample.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leejy/work/impala/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../../build/release//udf_samples/udf-sample.ll"
	cd /home/leejy/work/impala/be/src/udf_samples && /usr/local/bin/clang++ -emit-llvm -O3 -c -I../ udf-sample.cc -o /home/leejy/work/impala/be/build/release//udf_samples/udf-sample.ll

udf-sample-ir: be/src/udf_samples/CMakeFiles/udf-sample-ir
udf-sample-ir: be/build/release/udf_samples/udf-sample.ll
udf-sample-ir: be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/build.make
.PHONY : udf-sample-ir

# Rule to build all files generated by this target.
be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/build: udf-sample-ir
.PHONY : be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/build

be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/clean:
	cd /home/leejy/work/impala/be/src/udf_samples && $(CMAKE_COMMAND) -P CMakeFiles/udf-sample-ir.dir/cmake_clean.cmake
.PHONY : be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/clean

be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/depend:
	cd /home/leejy/work/impala && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leejy/work/impala /home/leejy/work/impala/be/src/udf_samples /home/leejy/work/impala /home/leejy/work/impala/be/src/udf_samples /home/leejy/work/impala/be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : be/src/udf_samples/CMakeFiles/udf-sample-ir.dir/depend

