# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/vukolov/Downloads/clion-2017.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/vukolov/Downloads/clion-2017.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vukolov/Documents/unit/fdf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vukolov/Documents/unit/fdf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fdf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fdf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fdf.dir/flags.make

CMakeFiles/fdf.dir/src/main.c.o: CMakeFiles/fdf.dir/flags.make
CMakeFiles/fdf.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vukolov/Documents/unit/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fdf.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf.dir/src/main.c.o   -c /home/vukolov/Documents/unit/fdf/src/main.c

CMakeFiles/fdf.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vukolov/Documents/unit/fdf/src/main.c > CMakeFiles/fdf.dir/src/main.c.i

CMakeFiles/fdf.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vukolov/Documents/unit/fdf/src/main.c -o CMakeFiles/fdf.dir/src/main.c.s

CMakeFiles/fdf.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/fdf.dir/src/main.c.o.requires

CMakeFiles/fdf.dir/src/main.c.o.provides: CMakeFiles/fdf.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/fdf.dir/src/main.c.o.provides

CMakeFiles/fdf.dir/src/main.c.o.provides.build: CMakeFiles/fdf.dir/src/main.c.o


CMakeFiles/fdf.dir/src/draw_line.c.o: CMakeFiles/fdf.dir/flags.make
CMakeFiles/fdf.dir/src/draw_line.c.o: ../src/draw_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vukolov/Documents/unit/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/fdf.dir/src/draw_line.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf.dir/src/draw_line.c.o   -c /home/vukolov/Documents/unit/fdf/src/draw_line.c

CMakeFiles/fdf.dir/src/draw_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf.dir/src/draw_line.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vukolov/Documents/unit/fdf/src/draw_line.c > CMakeFiles/fdf.dir/src/draw_line.c.i

CMakeFiles/fdf.dir/src/draw_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf.dir/src/draw_line.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vukolov/Documents/unit/fdf/src/draw_line.c -o CMakeFiles/fdf.dir/src/draw_line.c.s

CMakeFiles/fdf.dir/src/draw_line.c.o.requires:

.PHONY : CMakeFiles/fdf.dir/src/draw_line.c.o.requires

CMakeFiles/fdf.dir/src/draw_line.c.o.provides: CMakeFiles/fdf.dir/src/draw_line.c.o.requires
	$(MAKE) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/draw_line.c.o.provides.build
.PHONY : CMakeFiles/fdf.dir/src/draw_line.c.o.provides

CMakeFiles/fdf.dir/src/draw_line.c.o.provides.build: CMakeFiles/fdf.dir/src/draw_line.c.o


# Object files for target fdf
fdf_OBJECTS = \
"CMakeFiles/fdf.dir/src/main.c.o" \
"CMakeFiles/fdf.dir/src/draw_line.c.o"

# External object files for target fdf
fdf_EXTERNAL_OBJECTS =

fdf: CMakeFiles/fdf.dir/src/main.c.o
fdf: CMakeFiles/fdf.dir/src/draw_line.c.o
fdf: CMakeFiles/fdf.dir/build.make
fdf: classes_lib/libclasses_lib.a
fdf: libft/liblibft.a.a
fdf: libft/ft_printf/libft_printf.a
fdf: libft/ft_printf/libftprintf/liblibft.a
fdf: CMakeFiles/fdf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vukolov/Documents/unit/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable fdf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fdf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fdf.dir/build: fdf

.PHONY : CMakeFiles/fdf.dir/build

CMakeFiles/fdf.dir/requires: CMakeFiles/fdf.dir/src/main.c.o.requires
CMakeFiles/fdf.dir/requires: CMakeFiles/fdf.dir/src/draw_line.c.o.requires

.PHONY : CMakeFiles/fdf.dir/requires

CMakeFiles/fdf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fdf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fdf.dir/clean

CMakeFiles/fdf.dir/depend:
	cd /home/vukolov/Documents/unit/fdf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vukolov/Documents/unit/fdf /home/vukolov/Documents/unit/fdf /home/vukolov/Documents/unit/fdf/cmake-build-debug /home/vukolov/Documents/unit/fdf/cmake-build-debug /home/vukolov/Documents/unit/fdf/cmake-build-debug/CMakeFiles/fdf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fdf.dir/depend
