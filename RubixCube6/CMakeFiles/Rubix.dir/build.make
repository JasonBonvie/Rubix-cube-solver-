# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/william/GitHub/teamProject/RubixCube6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/william/GitHub/teamProject/RubixCube6

# Include any dependencies generated for this target.
include CMakeFiles/Rubix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rubix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rubix.dir/flags.make

CMakeFiles/Rubix.dir/rubix.cpp.o: CMakeFiles/Rubix.dir/flags.make
CMakeFiles/Rubix.dir/rubix.cpp.o: rubix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/william/GitHub/teamProject/RubixCube6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Rubix.dir/rubix.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rubix.dir/rubix.cpp.o -c /Users/william/GitHub/teamProject/RubixCube6/rubix.cpp

CMakeFiles/Rubix.dir/rubix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rubix.dir/rubix.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/william/GitHub/teamProject/RubixCube6/rubix.cpp > CMakeFiles/Rubix.dir/rubix.cpp.i

CMakeFiles/Rubix.dir/rubix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rubix.dir/rubix.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/william/GitHub/teamProject/RubixCube6/rubix.cpp -o CMakeFiles/Rubix.dir/rubix.cpp.s

CMakeFiles/Rubix.dir/rubix.cpp.o.requires:

.PHONY : CMakeFiles/Rubix.dir/rubix.cpp.o.requires

CMakeFiles/Rubix.dir/rubix.cpp.o.provides: CMakeFiles/Rubix.dir/rubix.cpp.o.requires
	$(MAKE) -f CMakeFiles/Rubix.dir/build.make CMakeFiles/Rubix.dir/rubix.cpp.o.provides.build
.PHONY : CMakeFiles/Rubix.dir/rubix.cpp.o.provides

CMakeFiles/Rubix.dir/rubix.cpp.o.provides.build: CMakeFiles/Rubix.dir/rubix.cpp.o


CMakeFiles/Rubix.dir/ShiftArray.cpp.o: CMakeFiles/Rubix.dir/flags.make
CMakeFiles/Rubix.dir/ShiftArray.cpp.o: ShiftArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/william/GitHub/teamProject/RubixCube6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Rubix.dir/ShiftArray.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rubix.dir/ShiftArray.cpp.o -c /Users/william/GitHub/teamProject/RubixCube6/ShiftArray.cpp

CMakeFiles/Rubix.dir/ShiftArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rubix.dir/ShiftArray.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/william/GitHub/teamProject/RubixCube6/ShiftArray.cpp > CMakeFiles/Rubix.dir/ShiftArray.cpp.i

CMakeFiles/Rubix.dir/ShiftArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rubix.dir/ShiftArray.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/william/GitHub/teamProject/RubixCube6/ShiftArray.cpp -o CMakeFiles/Rubix.dir/ShiftArray.cpp.s

CMakeFiles/Rubix.dir/ShiftArray.cpp.o.requires:

.PHONY : CMakeFiles/Rubix.dir/ShiftArray.cpp.o.requires

CMakeFiles/Rubix.dir/ShiftArray.cpp.o.provides: CMakeFiles/Rubix.dir/ShiftArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/Rubix.dir/build.make CMakeFiles/Rubix.dir/ShiftArray.cpp.o.provides.build
.PHONY : CMakeFiles/Rubix.dir/ShiftArray.cpp.o.provides

CMakeFiles/Rubix.dir/ShiftArray.cpp.o.provides.build: CMakeFiles/Rubix.dir/ShiftArray.cpp.o


CMakeFiles/Rubix.dir/RCube.cpp.o: CMakeFiles/Rubix.dir/flags.make
CMakeFiles/Rubix.dir/RCube.cpp.o: RCube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/william/GitHub/teamProject/RubixCube6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Rubix.dir/RCube.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rubix.dir/RCube.cpp.o -c /Users/william/GitHub/teamProject/RubixCube6/RCube.cpp

CMakeFiles/Rubix.dir/RCube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rubix.dir/RCube.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/william/GitHub/teamProject/RubixCube6/RCube.cpp > CMakeFiles/Rubix.dir/RCube.cpp.i

CMakeFiles/Rubix.dir/RCube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rubix.dir/RCube.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/william/GitHub/teamProject/RubixCube6/RCube.cpp -o CMakeFiles/Rubix.dir/RCube.cpp.s

CMakeFiles/Rubix.dir/RCube.cpp.o.requires:

.PHONY : CMakeFiles/Rubix.dir/RCube.cpp.o.requires

CMakeFiles/Rubix.dir/RCube.cpp.o.provides: CMakeFiles/Rubix.dir/RCube.cpp.o.requires
	$(MAKE) -f CMakeFiles/Rubix.dir/build.make CMakeFiles/Rubix.dir/RCube.cpp.o.provides.build
.PHONY : CMakeFiles/Rubix.dir/RCube.cpp.o.provides

CMakeFiles/Rubix.dir/RCube.cpp.o.provides.build: CMakeFiles/Rubix.dir/RCube.cpp.o


CMakeFiles/Rubix.dir/RCubeSolver.cpp.o: CMakeFiles/Rubix.dir/flags.make
CMakeFiles/Rubix.dir/RCubeSolver.cpp.o: RCubeSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/william/GitHub/teamProject/RubixCube6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Rubix.dir/RCubeSolver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rubix.dir/RCubeSolver.cpp.o -c /Users/william/GitHub/teamProject/RubixCube6/RCubeSolver.cpp

CMakeFiles/Rubix.dir/RCubeSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rubix.dir/RCubeSolver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/william/GitHub/teamProject/RubixCube6/RCubeSolver.cpp > CMakeFiles/Rubix.dir/RCubeSolver.cpp.i

CMakeFiles/Rubix.dir/RCubeSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rubix.dir/RCubeSolver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/william/GitHub/teamProject/RubixCube6/RCubeSolver.cpp -o CMakeFiles/Rubix.dir/RCubeSolver.cpp.s

CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.requires:

.PHONY : CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.requires

CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.provides: CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.requires
	$(MAKE) -f CMakeFiles/Rubix.dir/build.make CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.provides.build
.PHONY : CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.provides

CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.provides.build: CMakeFiles/Rubix.dir/RCubeSolver.cpp.o


# Object files for target Rubix
Rubix_OBJECTS = \
"CMakeFiles/Rubix.dir/rubix.cpp.o" \
"CMakeFiles/Rubix.dir/ShiftArray.cpp.o" \
"CMakeFiles/Rubix.dir/RCube.cpp.o" \
"CMakeFiles/Rubix.dir/RCubeSolver.cpp.o"

# External object files for target Rubix
Rubix_EXTERNAL_OBJECTS =

Rubix: CMakeFiles/Rubix.dir/rubix.cpp.o
Rubix: CMakeFiles/Rubix.dir/ShiftArray.cpp.o
Rubix: CMakeFiles/Rubix.dir/RCube.cpp.o
Rubix: CMakeFiles/Rubix.dir/RCubeSolver.cpp.o
Rubix: CMakeFiles/Rubix.dir/build.make
Rubix: CMakeFiles/Rubix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/william/GitHub/teamProject/RubixCube6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Rubix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rubix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rubix.dir/build: Rubix

.PHONY : CMakeFiles/Rubix.dir/build

CMakeFiles/Rubix.dir/requires: CMakeFiles/Rubix.dir/rubix.cpp.o.requires
CMakeFiles/Rubix.dir/requires: CMakeFiles/Rubix.dir/ShiftArray.cpp.o.requires
CMakeFiles/Rubix.dir/requires: CMakeFiles/Rubix.dir/RCube.cpp.o.requires
CMakeFiles/Rubix.dir/requires: CMakeFiles/Rubix.dir/RCubeSolver.cpp.o.requires

.PHONY : CMakeFiles/Rubix.dir/requires

CMakeFiles/Rubix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Rubix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Rubix.dir/clean

CMakeFiles/Rubix.dir/depend:
	cd /Users/william/GitHub/teamProject/RubixCube6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/william/GitHub/teamProject/RubixCube6 /Users/william/GitHub/teamProject/RubixCube6 /Users/william/GitHub/teamProject/RubixCube6 /Users/william/GitHub/teamProject/RubixCube6 /Users/william/GitHub/teamProject/RubixCube6/CMakeFiles/Rubix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rubix.dir/depend
