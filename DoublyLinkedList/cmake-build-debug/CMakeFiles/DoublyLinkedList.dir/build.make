# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DoublyLinkedList.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DoublyLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DoublyLinkedList.dir/flags.make

CMakeFiles/DoublyLinkedList.dir/Driver.cpp.o: CMakeFiles/DoublyLinkedList.dir/flags.make
CMakeFiles/DoublyLinkedList.dir/Driver.cpp.o: ../Driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DoublyLinkedList.dir/Driver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DoublyLinkedList.dir/Driver.cpp.o -c /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/Driver.cpp

CMakeFiles/DoublyLinkedList.dir/Driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoublyLinkedList.dir/Driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/Driver.cpp > CMakeFiles/DoublyLinkedList.dir/Driver.cpp.i

CMakeFiles/DoublyLinkedList.dir/Driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoublyLinkedList.dir/Driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/Driver.cpp -o CMakeFiles/DoublyLinkedList.dir/Driver.cpp.s

# Object files for target DoublyLinkedList
DoublyLinkedList_OBJECTS = \
"CMakeFiles/DoublyLinkedList.dir/Driver.cpp.o"

# External object files for target DoublyLinkedList
DoublyLinkedList_EXTERNAL_OBJECTS =

DoublyLinkedList: CMakeFiles/DoublyLinkedList.dir/Driver.cpp.o
DoublyLinkedList: CMakeFiles/DoublyLinkedList.dir/build.make
DoublyLinkedList: CMakeFiles/DoublyLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DoublyLinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DoublyLinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DoublyLinkedList.dir/build: DoublyLinkedList
.PHONY : CMakeFiles/DoublyLinkedList.dir/build

CMakeFiles/DoublyLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DoublyLinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DoublyLinkedList.dir/clean

CMakeFiles/DoublyLinkedList.dir/depend:
	cd /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug /mnt/c/Users/nickb/Documents/GitHub/Data-Structures---Algorithms-/DoublyLinkedList/cmake-build-debug/CMakeFiles/DoublyLinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DoublyLinkedList.dir/depend
