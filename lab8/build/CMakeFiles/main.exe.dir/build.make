# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\ES_ITI\C++\udemy\lab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\ES_ITI\C++\udemy\lab8\build

# Include any dependencies generated for this target.
include CMakeFiles/main.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.exe.dir/flags.make

CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj: CMakeFiles/main.exe.dir/flags.make
CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj: E:/ES_ITI/C++/udemy/lab8/projectandEmployee.cpp
CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj: CMakeFiles/main.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\ES_ITI\C++\udemy\lab8\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj -MF CMakeFiles\main.exe.dir\projectandEmployee.cpp.obj.d -o CMakeFiles\main.exe.dir\projectandEmployee.cpp.obj -c E:\ES_ITI\C++\udemy\lab8\projectandEmployee.cpp

CMakeFiles/main.exe.dir/projectandEmployee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.exe.dir/projectandEmployee.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\ES_ITI\C++\udemy\lab8\projectandEmployee.cpp > CMakeFiles\main.exe.dir\projectandEmployee.cpp.i

CMakeFiles/main.exe.dir/projectandEmployee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.exe.dir/projectandEmployee.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\ES_ITI\C++\udemy\lab8\projectandEmployee.cpp -o CMakeFiles\main.exe.dir\projectandEmployee.cpp.s

# Object files for target main.exe
main_exe_OBJECTS = \
"CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj"

# External object files for target main.exe
main_exe_EXTERNAL_OBJECTS =

main.exe.exe: CMakeFiles/main.exe.dir/projectandEmployee.cpp.obj
main.exe.exe: CMakeFiles/main.exe.dir/build.make
main.exe.exe: CMakeFiles/main.exe.dir/linkLibs.rsp
main.exe.exe: CMakeFiles/main.exe.dir/objects1.rsp
main.exe.exe: CMakeFiles/main.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\ES_ITI\C++\udemy\lab8\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main.exe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.exe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.exe.dir/build: main.exe.exe
.PHONY : CMakeFiles/main.exe.dir/build

CMakeFiles/main.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.exe.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.exe.dir/clean

CMakeFiles/main.exe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\ES_ITI\C++\udemy\lab8 E:\ES_ITI\C++\udemy\lab8 E:\ES_ITI\C++\udemy\lab8\build E:\ES_ITI\C++\udemy\lab8\build E:\ES_ITI\C++\udemy\lab8\build\CMakeFiles\main.exe.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.exe.dir/depend

