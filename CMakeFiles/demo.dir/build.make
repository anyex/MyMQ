# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tbox/MyMQ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tbox/MyMQ

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/Acceptor.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Acceptor.o: Acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/Acceptor.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Acceptor.o -c /home/tbox/MyMQ/Acceptor.cpp

CMakeFiles/demo.dir/Acceptor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Acceptor.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tbox/MyMQ/Acceptor.cpp > CMakeFiles/demo.dir/Acceptor.i

CMakeFiles/demo.dir/Acceptor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Acceptor.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tbox/MyMQ/Acceptor.cpp -o CMakeFiles/demo.dir/Acceptor.s

CMakeFiles/demo.dir/Acceptor.o.requires:

.PHONY : CMakeFiles/demo.dir/Acceptor.o.requires

CMakeFiles/demo.dir/Acceptor.o.provides: CMakeFiles/demo.dir/Acceptor.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Acceptor.o.provides.build
.PHONY : CMakeFiles/demo.dir/Acceptor.o.provides

CMakeFiles/demo.dir/Acceptor.o.provides.build: CMakeFiles/demo.dir/Acceptor.o


CMakeFiles/demo.dir/EventLoop.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/EventLoop.o: EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo.dir/EventLoop.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/EventLoop.o -c /home/tbox/MyMQ/EventLoop.cpp

CMakeFiles/demo.dir/EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/EventLoop.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tbox/MyMQ/EventLoop.cpp > CMakeFiles/demo.dir/EventLoop.i

CMakeFiles/demo.dir/EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/EventLoop.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tbox/MyMQ/EventLoop.cpp -o CMakeFiles/demo.dir/EventLoop.s

CMakeFiles/demo.dir/EventLoop.o.requires:

.PHONY : CMakeFiles/demo.dir/EventLoop.o.requires

CMakeFiles/demo.dir/EventLoop.o.provides: CMakeFiles/demo.dir/EventLoop.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/EventLoop.o.provides.build
.PHONY : CMakeFiles/demo.dir/EventLoop.o.provides

CMakeFiles/demo.dir/EventLoop.o.provides.build: CMakeFiles/demo.dir/EventLoop.o


CMakeFiles/demo.dir/InetAddr.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/InetAddr.o: InetAddr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/demo.dir/InetAddr.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/InetAddr.o -c /home/tbox/MyMQ/InetAddr.cpp

CMakeFiles/demo.dir/InetAddr.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/InetAddr.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tbox/MyMQ/InetAddr.cpp > CMakeFiles/demo.dir/InetAddr.i

CMakeFiles/demo.dir/InetAddr.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/InetAddr.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tbox/MyMQ/InetAddr.cpp -o CMakeFiles/demo.dir/InetAddr.s

CMakeFiles/demo.dir/InetAddr.o.requires:

.PHONY : CMakeFiles/demo.dir/InetAddr.o.requires

CMakeFiles/demo.dir/InetAddr.o.provides: CMakeFiles/demo.dir/InetAddr.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/InetAddr.o.provides.build
.PHONY : CMakeFiles/demo.dir/InetAddr.o.provides

CMakeFiles/demo.dir/InetAddr.o.provides.build: CMakeFiles/demo.dir/InetAddr.o


CMakeFiles/demo.dir/Server.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Server.o: Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/demo.dir/Server.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Server.o -c /home/tbox/MyMQ/Server.cpp

CMakeFiles/demo.dir/Server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Server.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tbox/MyMQ/Server.cpp > CMakeFiles/demo.dir/Server.i

CMakeFiles/demo.dir/Server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Server.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tbox/MyMQ/Server.cpp -o CMakeFiles/demo.dir/Server.s

CMakeFiles/demo.dir/Server.o.requires:

.PHONY : CMakeFiles/demo.dir/Server.o.requires

CMakeFiles/demo.dir/Server.o.provides: CMakeFiles/demo.dir/Server.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Server.o.provides.build
.PHONY : CMakeFiles/demo.dir/Server.o.provides

CMakeFiles/demo.dir/Server.o.provides.build: CMakeFiles/demo.dir/Server.o


CMakeFiles/demo.dir/Socket.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Socket.o: Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/demo.dir/Socket.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Socket.o -c /home/tbox/MyMQ/Socket.cpp

CMakeFiles/demo.dir/Socket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Socket.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tbox/MyMQ/Socket.cpp > CMakeFiles/demo.dir/Socket.i

CMakeFiles/demo.dir/Socket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Socket.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tbox/MyMQ/Socket.cpp -o CMakeFiles/demo.dir/Socket.s

CMakeFiles/demo.dir/Socket.o.requires:

.PHONY : CMakeFiles/demo.dir/Socket.o.requires

CMakeFiles/demo.dir/Socket.o.provides: CMakeFiles/demo.dir/Socket.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Socket.o.provides.build
.PHONY : CMakeFiles/demo.dir/Socket.o.provides

CMakeFiles/demo.dir/Socket.o.provides.build: CMakeFiles/demo.dir/Socket.o


CMakeFiles/demo.dir/main.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/main.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/demo.dir/main.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/main.o -c /home/tbox/MyMQ/main.cpp

CMakeFiles/demo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tbox/MyMQ/main.cpp > CMakeFiles/demo.dir/main.i

CMakeFiles/demo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tbox/MyMQ/main.cpp -o CMakeFiles/demo.dir/main.s

CMakeFiles/demo.dir/main.o.requires:

.PHONY : CMakeFiles/demo.dir/main.o.requires

CMakeFiles/demo.dir/main.o.provides: CMakeFiles/demo.dir/main.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/main.o.provides.build
.PHONY : CMakeFiles/demo.dir/main.o.provides

CMakeFiles/demo.dir/main.o.provides.build: CMakeFiles/demo.dir/main.o


# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/Acceptor.o" \
"CMakeFiles/demo.dir/EventLoop.o" \
"CMakeFiles/demo.dir/InetAddr.o" \
"CMakeFiles/demo.dir/Server.o" \
"CMakeFiles/demo.dir/Socket.o" \
"CMakeFiles/demo.dir/main.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/Acceptor.o
demo: CMakeFiles/demo.dir/EventLoop.o
demo: CMakeFiles/demo.dir/InetAddr.o
demo: CMakeFiles/demo.dir/Server.o
demo: CMakeFiles/demo.dir/Socket.o
demo: CMakeFiles/demo.dir/main.o
demo: CMakeFiles/demo.dir/build.make
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tbox/MyMQ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo

.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/Acceptor.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/EventLoop.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/InetAddr.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/Server.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/Socket.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/main.o.requires

.PHONY : CMakeFiles/demo.dir/requires

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/tbox/MyMQ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tbox/MyMQ /home/tbox/MyMQ /home/tbox/MyMQ /home/tbox/MyMQ /home/tbox/MyMQ/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend
