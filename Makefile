# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tbox/MyMQ/CMakeFiles /home/tbox/MyMQ/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tbox/MyMQ/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named demo

# Build rule for target.
demo: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 demo
.PHONY : demo

# fast build rule for target.
demo/fast:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/build
.PHONY : demo/fast

# target to build an object file
Acceptor.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Acceptor.o
.PHONY : Acceptor.o

# target to preprocess a source file
Acceptor.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Acceptor.i
.PHONY : Acceptor.i

# target to generate assembly for a file
Acceptor.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Acceptor.s
.PHONY : Acceptor.s

# target to build an object file
EventLoop.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/EventLoop.o
.PHONY : EventLoop.o

# target to preprocess a source file
EventLoop.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/EventLoop.i
.PHONY : EventLoop.i

# target to generate assembly for a file
EventLoop.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/EventLoop.s
.PHONY : EventLoop.s

# target to build an object file
InetAddr.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/InetAddr.o
.PHONY : InetAddr.o

# target to preprocess a source file
InetAddr.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/InetAddr.i
.PHONY : InetAddr.i

# target to generate assembly for a file
InetAddr.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/InetAddr.s
.PHONY : InetAddr.s

# target to build an object file
Server.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Server.o
.PHONY : Server.o

# target to preprocess a source file
Server.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Server.i
.PHONY : Server.i

# target to generate assembly for a file
Server.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Server.s
.PHONY : Server.s

# target to build an object file
Socket.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Socket.o
.PHONY : Socket.o

# target to preprocess a source file
Socket.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Socket.i
.PHONY : Socket.i

# target to generate assembly for a file
Socket.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/Socket.s
.PHONY : Socket.s

# target to build an object file
main.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/main.o
.PHONY : main.o

# target to preprocess a source file
main.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/main.i
.PHONY : main.i

# target to generate assembly for a file
main.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/main.s
.PHONY : main.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... demo"
	@echo "... edit_cache"
	@echo "... Acceptor.o"
	@echo "... Acceptor.i"
	@echo "... Acceptor.s"
	@echo "... EventLoop.o"
	@echo "... EventLoop.i"
	@echo "... EventLoop.s"
	@echo "... InetAddr.o"
	@echo "... InetAddr.i"
	@echo "... InetAddr.s"
	@echo "... Server.o"
	@echo "... Server.i"
	@echo "... Server.s"
	@echo "... Socket.o"
	@echo "... Socket.i"
	@echo "... Socket.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

