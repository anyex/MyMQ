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
CMAKE_SOURCE_DIR = /home/anyex/WtTbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anyex/WtTbox

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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anyex/WtTbox/CMakeFiles /home/anyex/WtTbox/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anyex/WtTbox/CMakeFiles 0
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

# target to build an object file
net/Acceptor.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Acceptor.o
.PHONY : net/Acceptor.o

# target to preprocess a source file
net/Acceptor.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Acceptor.i
.PHONY : net/Acceptor.i

# target to generate assembly for a file
net/Acceptor.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Acceptor.s
.PHONY : net/Acceptor.s

# target to build an object file
net/Channel.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Channel.o
.PHONY : net/Channel.o

# target to preprocess a source file
net/Channel.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Channel.i
.PHONY : net/Channel.i

# target to generate assembly for a file
net/Channel.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Channel.s
.PHONY : net/Channel.s

# target to build an object file
net/Connection.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Connection.o
.PHONY : net/Connection.o

# target to preprocess a source file
net/Connection.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Connection.i
.PHONY : net/Connection.i

# target to generate assembly for a file
net/Connection.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Connection.s
.PHONY : net/Connection.s

# target to build an object file
net/Epoller.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Epoller.o
.PHONY : net/Epoller.o

# target to preprocess a source file
net/Epoller.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Epoller.i
.PHONY : net/Epoller.i

# target to generate assembly for a file
net/Epoller.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Epoller.s
.PHONY : net/Epoller.s

# target to build an object file
net/EventLoop.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/EventLoop.o
.PHONY : net/EventLoop.o

# target to preprocess a source file
net/EventLoop.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/EventLoop.i
.PHONY : net/EventLoop.i

# target to generate assembly for a file
net/EventLoop.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/EventLoop.s
.PHONY : net/EventLoop.s

# target to build an object file
net/InetAddr.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/InetAddr.o
.PHONY : net/InetAddr.o

# target to preprocess a source file
net/InetAddr.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/InetAddr.i
.PHONY : net/InetAddr.i

# target to generate assembly for a file
net/InetAddr.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/InetAddr.s
.PHONY : net/InetAddr.s

# target to build an object file
net/Server.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Server.o
.PHONY : net/Server.o

# target to preprocess a source file
net/Server.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Server.i
.PHONY : net/Server.i

# target to generate assembly for a file
net/Server.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Server.s
.PHONY : net/Server.s

# target to build an object file
net/Socket.o:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Socket.o
.PHONY : net/Socket.o

# target to preprocess a source file
net/Socket.i:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Socket.i
.PHONY : net/Socket.i

# target to generate assembly for a file
net/Socket.s:
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/net/Socket.s
.PHONY : net/Socket.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... demo"
	@echo "... edit_cache"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... net/Acceptor.o"
	@echo "... net/Acceptor.i"
	@echo "... net/Acceptor.s"
	@echo "... net/Channel.o"
	@echo "... net/Channel.i"
	@echo "... net/Channel.s"
	@echo "... net/Connection.o"
	@echo "... net/Connection.i"
	@echo "... net/Connection.s"
	@echo "... net/Epoller.o"
	@echo "... net/Epoller.i"
	@echo "... net/Epoller.s"
	@echo "... net/EventLoop.o"
	@echo "... net/EventLoop.i"
	@echo "... net/EventLoop.s"
	@echo "... net/InetAddr.o"
	@echo "... net/InetAddr.i"
	@echo "... net/InetAddr.s"
	@echo "... net/Server.o"
	@echo "... net/Server.i"
	@echo "... net/Server.s"
	@echo "... net/Socket.o"
	@echo "... net/Socket.i"
	@echo "... net/Socket.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

