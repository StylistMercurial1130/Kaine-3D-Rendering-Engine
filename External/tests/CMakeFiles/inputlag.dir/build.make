# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Repos\Kaine3DRenderingEngine\External

# Include any dependencies generated for this target.
include tests/CMakeFiles/inputlag.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/inputlag.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/inputlag.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/inputlag.dir/flags.make

tests/CMakeFiles/inputlag.dir/inputlag.c.obj: tests/CMakeFiles/inputlag.dir/flags.make
tests/CMakeFiles/inputlag.dir/inputlag.c.obj: tests/CMakeFiles/inputlag.dir/includes_C.rsp
tests/CMakeFiles/inputlag.dir/inputlag.c.obj: C:/Users/wrkkr/Downloads/glfw-3.3.7/glfw-3.3.7/tests/inputlag.c
tests/CMakeFiles/inputlag.dir/inputlag.c.obj: tests/CMakeFiles/inputlag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Repos\Kaine3DRenderingEngine\External\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/inputlag.dir/inputlag.c.obj"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/inputlag.dir/inputlag.c.obj -MF CMakeFiles\inputlag.dir\inputlag.c.obj.d -o CMakeFiles\inputlag.dir\inputlag.c.obj -c C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\tests\inputlag.c

tests/CMakeFiles/inputlag.dir/inputlag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/inputlag.c.i"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\tests\inputlag.c > CMakeFiles\inputlag.dir\inputlag.c.i

tests/CMakeFiles/inputlag.dir/inputlag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/inputlag.c.s"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\tests\inputlag.c -o CMakeFiles\inputlag.dir\inputlag.c.s

tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: tests/CMakeFiles/inputlag.dir/flags.make
tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: tests/CMakeFiles/inputlag.dir/includes_C.rsp
tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: C:/Users/wrkkr/Downloads/glfw-3.3.7/glfw-3.3.7/deps/getopt.c
tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: tests/CMakeFiles/inputlag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Repos\Kaine3DRenderingEngine\External\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj -MF CMakeFiles\inputlag.dir\__\deps\getopt.c.obj.d -o CMakeFiles\inputlag.dir\__\deps\getopt.c.obj -c C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\deps\getopt.c

tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/__/deps/getopt.c.i"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\deps\getopt.c > CMakeFiles\inputlag.dir\__\deps\getopt.c.i

tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/__/deps/getopt.c.s"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\deps\getopt.c -o CMakeFiles\inputlag.dir\__\deps\getopt.c.s

tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/inputlag.dir/flags.make
tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/inputlag.dir/includes_C.rsp
tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: C:/Users/wrkkr/Downloads/glfw-3.3.7/glfw-3.3.7/deps/glad_gl.c
tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/inputlag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Repos\Kaine3DRenderingEngine\External\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\inputlag.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\inputlag.dir\__\deps\glad_gl.c.obj -c C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\deps\glad_gl.c

tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\deps\glad_gl.c > CMakeFiles\inputlag.dir\__\deps\glad_gl.c.i

tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && D:\C_C++\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\deps\glad_gl.c -o CMakeFiles\inputlag.dir\__\deps\glad_gl.c.s

# Object files for target inputlag
inputlag_OBJECTS = \
"CMakeFiles/inputlag.dir/inputlag.c.obj" \
"CMakeFiles/inputlag.dir/__/deps/getopt.c.obj" \
"CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj"

# External object files for target inputlag
inputlag_EXTERNAL_OBJECTS =

tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/inputlag.c.obj
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/build.make
tests/inputlag.exe: src/libglfw3dll.a
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/linklibs.rsp
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/objects1.rsp
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Repos\Kaine3DRenderingEngine\External\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable inputlag.exe"
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\inputlag.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/inputlag.dir/build: tests/inputlag.exe
.PHONY : tests/CMakeFiles/inputlag.dir/build

tests/CMakeFiles/inputlag.dir/clean:
	cd /d D:\Repos\Kaine3DRenderingEngine\External\tests && $(CMAKE_COMMAND) -P CMakeFiles\inputlag.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/inputlag.dir/clean

tests/CMakeFiles/inputlag.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7 C:\Users\wrkkr\Downloads\glfw-3.3.7\glfw-3.3.7\tests D:\Repos\Kaine3DRenderingEngine\External D:\Repos\Kaine3DRenderingEngine\External\tests D:\Repos\Kaine3DRenderingEngine\External\tests\CMakeFiles\inputlag.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/inputlag.dir/depend

