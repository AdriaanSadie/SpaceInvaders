# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/workspace/SpaceInvaders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/workspace/SpaceInvaders/build

# Include any dependencies generated for this target.
include CMakeFiles/SpaceInvaders.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SpaceInvaders.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpaceInvaders.dir/flags.make

CMakeFiles/SpaceInvaders.dir/src/main.cpp.o: CMakeFiles/SpaceInvaders.dir/flags.make
CMakeFiles/SpaceInvaders.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SpaceInvaders.dir/src/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceInvaders.dir/src/main.cpp.o -c /home/workspace/SpaceInvaders/src/main.cpp

CMakeFiles/SpaceInvaders.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceInvaders.dir/src/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/SpaceInvaders/src/main.cpp > CMakeFiles/SpaceInvaders.dir/src/main.cpp.i

CMakeFiles/SpaceInvaders.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceInvaders.dir/src/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/SpaceInvaders/src/main.cpp -o CMakeFiles/SpaceInvaders.dir/src/main.cpp.s

CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.o: CMakeFiles/SpaceInvaders.dir/flags.make
CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.o -c /home/workspace/SpaceInvaders/src/renderer.cpp

CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/SpaceInvaders/src/renderer.cpp > CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.i

CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/SpaceInvaders/src/renderer.cpp -o CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.s

CMakeFiles/SpaceInvaders.dir/src/game.cpp.o: CMakeFiles/SpaceInvaders.dir/flags.make
CMakeFiles/SpaceInvaders.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SpaceInvaders.dir/src/game.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceInvaders.dir/src/game.cpp.o -c /home/workspace/SpaceInvaders/src/game.cpp

CMakeFiles/SpaceInvaders.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceInvaders.dir/src/game.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/SpaceInvaders/src/game.cpp > CMakeFiles/SpaceInvaders.dir/src/game.cpp.i

CMakeFiles/SpaceInvaders.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceInvaders.dir/src/game.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/SpaceInvaders/src/game.cpp -o CMakeFiles/SpaceInvaders.dir/src/game.cpp.s

CMakeFiles/SpaceInvaders.dir/src/player.cpp.o: CMakeFiles/SpaceInvaders.dir/flags.make
CMakeFiles/SpaceInvaders.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SpaceInvaders.dir/src/player.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceInvaders.dir/src/player.cpp.o -c /home/workspace/SpaceInvaders/src/player.cpp

CMakeFiles/SpaceInvaders.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceInvaders.dir/src/player.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/SpaceInvaders/src/player.cpp > CMakeFiles/SpaceInvaders.dir/src/player.cpp.i

CMakeFiles/SpaceInvaders.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceInvaders.dir/src/player.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/SpaceInvaders/src/player.cpp -o CMakeFiles/SpaceInvaders.dir/src/player.cpp.s

CMakeFiles/SpaceInvaders.dir/src/controller.cpp.o: CMakeFiles/SpaceInvaders.dir/flags.make
CMakeFiles/SpaceInvaders.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SpaceInvaders.dir/src/controller.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceInvaders.dir/src/controller.cpp.o -c /home/workspace/SpaceInvaders/src/controller.cpp

CMakeFiles/SpaceInvaders.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceInvaders.dir/src/controller.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/SpaceInvaders/src/controller.cpp > CMakeFiles/SpaceInvaders.dir/src/controller.cpp.i

CMakeFiles/SpaceInvaders.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceInvaders.dir/src/controller.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/SpaceInvaders/src/controller.cpp -o CMakeFiles/SpaceInvaders.dir/src/controller.cpp.s

CMakeFiles/SpaceInvaders.dir/src/level.cpp.o: CMakeFiles/SpaceInvaders.dir/flags.make
CMakeFiles/SpaceInvaders.dir/src/level.cpp.o: ../src/level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SpaceInvaders.dir/src/level.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SpaceInvaders.dir/src/level.cpp.o -c /home/workspace/SpaceInvaders/src/level.cpp

CMakeFiles/SpaceInvaders.dir/src/level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceInvaders.dir/src/level.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/SpaceInvaders/src/level.cpp > CMakeFiles/SpaceInvaders.dir/src/level.cpp.i

CMakeFiles/SpaceInvaders.dir/src/level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceInvaders.dir/src/level.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/SpaceInvaders/src/level.cpp -o CMakeFiles/SpaceInvaders.dir/src/level.cpp.s

# Object files for target SpaceInvaders
SpaceInvaders_OBJECTS = \
"CMakeFiles/SpaceInvaders.dir/src/main.cpp.o" \
"CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.o" \
"CMakeFiles/SpaceInvaders.dir/src/game.cpp.o" \
"CMakeFiles/SpaceInvaders.dir/src/player.cpp.o" \
"CMakeFiles/SpaceInvaders.dir/src/controller.cpp.o" \
"CMakeFiles/SpaceInvaders.dir/src/level.cpp.o"

# External object files for target SpaceInvaders
SpaceInvaders_EXTERNAL_OBJECTS =

SpaceInvaders: CMakeFiles/SpaceInvaders.dir/src/main.cpp.o
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/src/renderer.cpp.o
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/src/game.cpp.o
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/src/player.cpp.o
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/src/controller.cpp.o
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/src/level.cpp.o
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/build.make
SpaceInvaders: CMakeFiles/SpaceInvaders.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/workspace/SpaceInvaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SpaceInvaders"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpaceInvaders.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpaceInvaders.dir/build: SpaceInvaders

.PHONY : CMakeFiles/SpaceInvaders.dir/build

CMakeFiles/SpaceInvaders.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpaceInvaders.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpaceInvaders.dir/clean

CMakeFiles/SpaceInvaders.dir/depend:
	cd /home/workspace/SpaceInvaders/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/workspace/SpaceInvaders /home/workspace/SpaceInvaders /home/workspace/SpaceInvaders/build /home/workspace/SpaceInvaders/build /home/workspace/SpaceInvaders/build/CMakeFiles/SpaceInvaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpaceInvaders.dir/depend

