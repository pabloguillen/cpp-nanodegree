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
CMAKE_SOURCE_DIR = /home/workspace/CppND-Capstone-FlappyFish

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/workspace/CppND-Capstone-FlappyFish/build

# Include any dependencies generated for this target.
include CMakeFiles/FlappyFish.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FlappyFish.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FlappyFish.dir/flags.make

CMakeFiles/FlappyFish.dir/src/controller.cpp.o: CMakeFiles/FlappyFish.dir/flags.make
CMakeFiles/FlappyFish.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FlappyFish.dir/src/controller.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FlappyFish.dir/src/controller.cpp.o -c /home/workspace/CppND-Capstone-FlappyFish/src/controller.cpp

CMakeFiles/FlappyFish.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlappyFish.dir/src/controller.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-FlappyFish/src/controller.cpp > CMakeFiles/FlappyFish.dir/src/controller.cpp.i

CMakeFiles/FlappyFish.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlappyFish.dir/src/controller.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-FlappyFish/src/controller.cpp -o CMakeFiles/FlappyFish.dir/src/controller.cpp.s

CMakeFiles/FlappyFish.dir/src/fish.cpp.o: CMakeFiles/FlappyFish.dir/flags.make
CMakeFiles/FlappyFish.dir/src/fish.cpp.o: ../src/fish.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FlappyFish.dir/src/fish.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FlappyFish.dir/src/fish.cpp.o -c /home/workspace/CppND-Capstone-FlappyFish/src/fish.cpp

CMakeFiles/FlappyFish.dir/src/fish.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlappyFish.dir/src/fish.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-FlappyFish/src/fish.cpp > CMakeFiles/FlappyFish.dir/src/fish.cpp.i

CMakeFiles/FlappyFish.dir/src/fish.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlappyFish.dir/src/fish.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-FlappyFish/src/fish.cpp -o CMakeFiles/FlappyFish.dir/src/fish.cpp.s

CMakeFiles/FlappyFish.dir/src/game.cpp.o: CMakeFiles/FlappyFish.dir/flags.make
CMakeFiles/FlappyFish.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FlappyFish.dir/src/game.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FlappyFish.dir/src/game.cpp.o -c /home/workspace/CppND-Capstone-FlappyFish/src/game.cpp

CMakeFiles/FlappyFish.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlappyFish.dir/src/game.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-FlappyFish/src/game.cpp > CMakeFiles/FlappyFish.dir/src/game.cpp.i

CMakeFiles/FlappyFish.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlappyFish.dir/src/game.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-FlappyFish/src/game.cpp -o CMakeFiles/FlappyFish.dir/src/game.cpp.s

CMakeFiles/FlappyFish.dir/src/main.cpp.o: CMakeFiles/FlappyFish.dir/flags.make
CMakeFiles/FlappyFish.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FlappyFish.dir/src/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FlappyFish.dir/src/main.cpp.o -c /home/workspace/CppND-Capstone-FlappyFish/src/main.cpp

CMakeFiles/FlappyFish.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlappyFish.dir/src/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-FlappyFish/src/main.cpp > CMakeFiles/FlappyFish.dir/src/main.cpp.i

CMakeFiles/FlappyFish.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlappyFish.dir/src/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-FlappyFish/src/main.cpp -o CMakeFiles/FlappyFish.dir/src/main.cpp.s

CMakeFiles/FlappyFish.dir/src/obstacle.cpp.o: CMakeFiles/FlappyFish.dir/flags.make
CMakeFiles/FlappyFish.dir/src/obstacle.cpp.o: ../src/obstacle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FlappyFish.dir/src/obstacle.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FlappyFish.dir/src/obstacle.cpp.o -c /home/workspace/CppND-Capstone-FlappyFish/src/obstacle.cpp

CMakeFiles/FlappyFish.dir/src/obstacle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlappyFish.dir/src/obstacle.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-FlappyFish/src/obstacle.cpp > CMakeFiles/FlappyFish.dir/src/obstacle.cpp.i

CMakeFiles/FlappyFish.dir/src/obstacle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlappyFish.dir/src/obstacle.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-FlappyFish/src/obstacle.cpp -o CMakeFiles/FlappyFish.dir/src/obstacle.cpp.s

CMakeFiles/FlappyFish.dir/src/renderer.cpp.o: CMakeFiles/FlappyFish.dir/flags.make
CMakeFiles/FlappyFish.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FlappyFish.dir/src/renderer.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FlappyFish.dir/src/renderer.cpp.o -c /home/workspace/CppND-Capstone-FlappyFish/src/renderer.cpp

CMakeFiles/FlappyFish.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlappyFish.dir/src/renderer.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-FlappyFish/src/renderer.cpp > CMakeFiles/FlappyFish.dir/src/renderer.cpp.i

CMakeFiles/FlappyFish.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlappyFish.dir/src/renderer.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-FlappyFish/src/renderer.cpp -o CMakeFiles/FlappyFish.dir/src/renderer.cpp.s

# Object files for target FlappyFish
FlappyFish_OBJECTS = \
"CMakeFiles/FlappyFish.dir/src/controller.cpp.o" \
"CMakeFiles/FlappyFish.dir/src/fish.cpp.o" \
"CMakeFiles/FlappyFish.dir/src/game.cpp.o" \
"CMakeFiles/FlappyFish.dir/src/main.cpp.o" \
"CMakeFiles/FlappyFish.dir/src/obstacle.cpp.o" \
"CMakeFiles/FlappyFish.dir/src/renderer.cpp.o"

# External object files for target FlappyFish
FlappyFish_EXTERNAL_OBJECTS =

FlappyFish: CMakeFiles/FlappyFish.dir/src/controller.cpp.o
FlappyFish: CMakeFiles/FlappyFish.dir/src/fish.cpp.o
FlappyFish: CMakeFiles/FlappyFish.dir/src/game.cpp.o
FlappyFish: CMakeFiles/FlappyFish.dir/src/main.cpp.o
FlappyFish: CMakeFiles/FlappyFish.dir/src/obstacle.cpp.o
FlappyFish: CMakeFiles/FlappyFish.dir/src/renderer.cpp.o
FlappyFish: CMakeFiles/FlappyFish.dir/build.make
FlappyFish: /usr/lib/x86_64-linux-gnu/libSDL2main.a
FlappyFish: /usr/lib/x86_64-linux-gnu/libSDL2.so
FlappyFish: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
FlappyFish: CMakeFiles/FlappyFish.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable FlappyFish"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FlappyFish.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FlappyFish.dir/build: FlappyFish

.PHONY : CMakeFiles/FlappyFish.dir/build

CMakeFiles/FlappyFish.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FlappyFish.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FlappyFish.dir/clean

CMakeFiles/FlappyFish.dir/depend:
	cd /home/workspace/CppND-Capstone-FlappyFish/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/workspace/CppND-Capstone-FlappyFish /home/workspace/CppND-Capstone-FlappyFish /home/workspace/CppND-Capstone-FlappyFish/build /home/workspace/CppND-Capstone-FlappyFish/build /home/workspace/CppND-Capstone-FlappyFish/build/CMakeFiles/FlappyFish.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FlappyFish.dir/depend

