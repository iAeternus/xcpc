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
CMAKE_COMMAND = "D:\Application\Develop\Python 3.11.2\Lib\site-packages\cmake\data\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Application\Develop\Python 3.11.2\Lib\site-packages\cmake\data\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\develop\xcpc\src\better-ds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\develop\xcpc\src\better-ds\build

# Include any dependencies generated for this target.
include CMakeFiles/better-ds.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/better-ds.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/better-ds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/better-ds.dir/flags.make

CMakeFiles/better-ds.dir/src/main.cpp.obj: CMakeFiles/better-ds.dir/flags.make
CMakeFiles/better-ds.dir/src/main.cpp.obj: CMakeFiles/better-ds.dir/includes_CXX.rsp
CMakeFiles/better-ds.dir/src/main.cpp.obj: F:/develop/xcpc/src/better-ds/src/main.cpp
CMakeFiles/better-ds.dir/src/main.cpp.obj: CMakeFiles/better-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\develop\xcpc\src\better-ds\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/better-ds.dir/src/main.cpp.obj"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/better-ds.dir/src/main.cpp.obj -MF CMakeFiles\better-ds.dir\src\main.cpp.obj.d -o CMakeFiles\better-ds.dir\src\main.cpp.obj -c F:\develop\xcpc\src\better-ds\src\main.cpp

CMakeFiles/better-ds.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/better-ds.dir/src/main.cpp.i"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\develop\xcpc\src\better-ds\src\main.cpp > CMakeFiles\better-ds.dir\src\main.cpp.i

CMakeFiles/better-ds.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/better-ds.dir/src/main.cpp.s"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\develop\xcpc\src\better-ds\src\main.cpp -o CMakeFiles\better-ds.dir\src\main.cpp.s

CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj: CMakeFiles/better-ds.dir/flags.make
CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj: CMakeFiles/better-ds.dir/includes_CXX.rsp
CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj: F:/develop/xcpc/src/better-ds/src/common/IteratorOutOfBounds.cpp
CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj: CMakeFiles/better-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\develop\xcpc\src\better-ds\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj -MF CMakeFiles\better-ds.dir\src\common\IteratorOutOfBounds.cpp.obj.d -o CMakeFiles\better-ds.dir\src\common\IteratorOutOfBounds.cpp.obj -c F:\develop\xcpc\src\better-ds\src\common\IteratorOutOfBounds.cpp

CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.i"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\develop\xcpc\src\better-ds\src\common\IteratorOutOfBounds.cpp > CMakeFiles\better-ds.dir\src\common\IteratorOutOfBounds.cpp.i

CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.s"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\develop\xcpc\src\better-ds\src\common\IteratorOutOfBounds.cpp -o CMakeFiles\better-ds.dir\src\common\IteratorOutOfBounds.cpp.s

CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj: CMakeFiles/better-ds.dir/flags.make
CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj: CMakeFiles/better-ds.dir/includes_CXX.rsp
CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj: F:/develop/xcpc/src/better-ds/src/common/NoSuchUnitTestException.cpp
CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj: CMakeFiles/better-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\develop\xcpc\src\better-ds\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj -MF CMakeFiles\better-ds.dir\src\common\NoSuchUnitTestException.cpp.obj.d -o CMakeFiles\better-ds.dir\src\common\NoSuchUnitTestException.cpp.obj -c F:\develop\xcpc\src\better-ds\src\common\NoSuchUnitTestException.cpp

CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.i"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\develop\xcpc\src\better-ds\src\common\NoSuchUnitTestException.cpp > CMakeFiles\better-ds.dir\src\common\NoSuchUnitTestException.cpp.i

CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.s"
	F:\application\develop\gcc\x86_64-13.2.0-release-win32-seh-msvcrt-rt_v11-rev0\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\develop\xcpc\src\better-ds\src\common\NoSuchUnitTestException.cpp -o CMakeFiles\better-ds.dir\src\common\NoSuchUnitTestException.cpp.s

# Object files for target better-ds
better__ds_OBJECTS = \
"CMakeFiles/better-ds.dir/src/main.cpp.obj" \
"CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj" \
"CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj"

# External object files for target better-ds
better__ds_EXTERNAL_OBJECTS =

better-ds.exe: CMakeFiles/better-ds.dir/src/main.cpp.obj
better-ds.exe: CMakeFiles/better-ds.dir/src/common/IteratorOutOfBounds.cpp.obj
better-ds.exe: CMakeFiles/better-ds.dir/src/common/NoSuchUnitTestException.cpp.obj
better-ds.exe: CMakeFiles/better-ds.dir/build.make
better-ds.exe: CMakeFiles/better-ds.dir/linkLibs.rsp
better-ds.exe: CMakeFiles/better-ds.dir/objects1.rsp
better-ds.exe: CMakeFiles/better-ds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=F:\develop\xcpc\src\better-ds\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable better-ds.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\better-ds.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/better-ds.dir/build: better-ds.exe
.PHONY : CMakeFiles/better-ds.dir/build

CMakeFiles/better-ds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\better-ds.dir\cmake_clean.cmake
.PHONY : CMakeFiles/better-ds.dir/clean

CMakeFiles/better-ds.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\develop\xcpc\src\better-ds F:\develop\xcpc\src\better-ds F:\develop\xcpc\src\better-ds\build F:\develop\xcpc\src\better-ds\build F:\develop\xcpc\src\better-ds\build\CMakeFiles\better-ds.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/better-ds.dir/depend
