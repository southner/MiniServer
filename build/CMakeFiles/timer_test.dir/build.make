# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /root/workspace/MiniServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/MiniServer/build

# Include any dependencies generated for this target.
include CMakeFiles/timer_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/timer_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/timer_test.dir/flags.make

CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.o: ../test/timer/timer_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.o -c /root/workspace/MiniServer/test/timer/timer_test.cpp

CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/test/timer/timer_test.cpp > CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.i

CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/test/timer/timer_test.cpp -o CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.s

CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.o: ../code/buffer/buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.o -c /root/workspace/MiniServer/code/buffer/buffer.cpp

CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/buffer/buffer.cpp > CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.i

CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/buffer/buffer.cpp -o CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.s

CMakeFiles/timer_test.dir/code/http/http_conn.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/http/http_conn.cpp.o: ../code/http/http_conn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/timer_test.dir/code/http/http_conn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/http/http_conn.cpp.o -c /root/workspace/MiniServer/code/http/http_conn.cpp

CMakeFiles/timer_test.dir/code/http/http_conn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/http/http_conn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/http/http_conn.cpp > CMakeFiles/timer_test.dir/code/http/http_conn.cpp.i

CMakeFiles/timer_test.dir/code/http/http_conn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/http/http_conn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/http/http_conn.cpp -o CMakeFiles/timer_test.dir/code/http/http_conn.cpp.s

CMakeFiles/timer_test.dir/code/http/http_request.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/http/http_request.cpp.o: ../code/http/http_request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/timer_test.dir/code/http/http_request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/http/http_request.cpp.o -c /root/workspace/MiniServer/code/http/http_request.cpp

CMakeFiles/timer_test.dir/code/http/http_request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/http/http_request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/http/http_request.cpp > CMakeFiles/timer_test.dir/code/http/http_request.cpp.i

CMakeFiles/timer_test.dir/code/http/http_request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/http/http_request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/http/http_request.cpp -o CMakeFiles/timer_test.dir/code/http/http_request.cpp.s

CMakeFiles/timer_test.dir/code/http/http_response.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/http/http_response.cpp.o: ../code/http/http_response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/timer_test.dir/code/http/http_response.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/http/http_response.cpp.o -c /root/workspace/MiniServer/code/http/http_response.cpp

CMakeFiles/timer_test.dir/code/http/http_response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/http/http_response.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/http/http_response.cpp > CMakeFiles/timer_test.dir/code/http/http_response.cpp.i

CMakeFiles/timer_test.dir/code/http/http_response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/http/http_response.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/http/http_response.cpp -o CMakeFiles/timer_test.dir/code/http/http_response.cpp.s

CMakeFiles/timer_test.dir/code/json11/json11.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/json11/json11.cpp.o: ../code/json11/json11.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/timer_test.dir/code/json11/json11.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/json11/json11.cpp.o -c /root/workspace/MiniServer/code/json11/json11.cpp

CMakeFiles/timer_test.dir/code/json11/json11.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/json11/json11.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/json11/json11.cpp > CMakeFiles/timer_test.dir/code/json11/json11.cpp.i

CMakeFiles/timer_test.dir/code/json11/json11.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/json11/json11.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/json11/json11.cpp -o CMakeFiles/timer_test.dir/code/json11/json11.cpp.s

CMakeFiles/timer_test.dir/code/log/log.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/log/log.cpp.o: ../code/log/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/timer_test.dir/code/log/log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/log/log.cpp.o -c /root/workspace/MiniServer/code/log/log.cpp

CMakeFiles/timer_test.dir/code/log/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/log/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/log/log.cpp > CMakeFiles/timer_test.dir/code/log/log.cpp.i

CMakeFiles/timer_test.dir/code/log/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/log/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/log/log.cpp -o CMakeFiles/timer_test.dir/code/log/log.cpp.s

CMakeFiles/timer_test.dir/code/mux/mux.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/mux/mux.cpp.o: ../code/mux/mux.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/timer_test.dir/code/mux/mux.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/mux/mux.cpp.o -c /root/workspace/MiniServer/code/mux/mux.cpp

CMakeFiles/timer_test.dir/code/mux/mux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/mux/mux.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/mux/mux.cpp > CMakeFiles/timer_test.dir/code/mux/mux.cpp.i

CMakeFiles/timer_test.dir/code/mux/mux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/mux/mux.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/mux/mux.cpp -o CMakeFiles/timer_test.dir/code/mux/mux.cpp.s

CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.o: ../code/pool/sql_conn_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.o -c /root/workspace/MiniServer/code/pool/sql_conn_pool.cpp

CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/pool/sql_conn_pool.cpp > CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.i

CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/pool/sql_conn_pool.cpp -o CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.s

CMakeFiles/timer_test.dir/code/server/server.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/server/server.cpp.o: ../code/server/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/timer_test.dir/code/server/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/server/server.cpp.o -c /root/workspace/MiniServer/code/server/server.cpp

CMakeFiles/timer_test.dir/code/server/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/server/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/server/server.cpp > CMakeFiles/timer_test.dir/code/server/server.cpp.i

CMakeFiles/timer_test.dir/code/server/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/server/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/server/server.cpp -o CMakeFiles/timer_test.dir/code/server/server.cpp.s

CMakeFiles/timer_test.dir/code/timer/timer.cpp.o: CMakeFiles/timer_test.dir/flags.make
CMakeFiles/timer_test.dir/code/timer/timer.cpp.o: ../code/timer/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/timer_test.dir/code/timer/timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timer_test.dir/code/timer/timer.cpp.o -c /root/workspace/MiniServer/code/timer/timer.cpp

CMakeFiles/timer_test.dir/code/timer/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timer_test.dir/code/timer/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/MiniServer/code/timer/timer.cpp > CMakeFiles/timer_test.dir/code/timer/timer.cpp.i

CMakeFiles/timer_test.dir/code/timer/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timer_test.dir/code/timer/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/MiniServer/code/timer/timer.cpp -o CMakeFiles/timer_test.dir/code/timer/timer.cpp.s

# Object files for target timer_test
timer_test_OBJECTS = \
"CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.o" \
"CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.o" \
"CMakeFiles/timer_test.dir/code/http/http_conn.cpp.o" \
"CMakeFiles/timer_test.dir/code/http/http_request.cpp.o" \
"CMakeFiles/timer_test.dir/code/http/http_response.cpp.o" \
"CMakeFiles/timer_test.dir/code/json11/json11.cpp.o" \
"CMakeFiles/timer_test.dir/code/log/log.cpp.o" \
"CMakeFiles/timer_test.dir/code/mux/mux.cpp.o" \
"CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.o" \
"CMakeFiles/timer_test.dir/code/server/server.cpp.o" \
"CMakeFiles/timer_test.dir/code/timer/timer.cpp.o"

# External object files for target timer_test
timer_test_EXTERNAL_OBJECTS =

timer_test: CMakeFiles/timer_test.dir/test/timer/timer_test.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/buffer/buffer.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/http/http_conn.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/http/http_request.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/http/http_response.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/json11/json11.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/log/log.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/mux/mux.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/pool/sql_conn_pool.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/server/server.cpp.o
timer_test: CMakeFiles/timer_test.dir/code/timer/timer.cpp.o
timer_test: CMakeFiles/timer_test.dir/build.make
timer_test: lib/libgtest_main.a
timer_test: lib/libgtest.a
timer_test: CMakeFiles/timer_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/workspace/MiniServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable timer_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timer_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=timer_test -D TEST_EXECUTABLE=/root/workspace/MiniServer/build/timer_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/root/workspace/MiniServer/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=timer_test_TESTS -D CTEST_FILE=/root/workspace/MiniServer/build/timer_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -P /usr/share/cmake-3.16/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/timer_test.dir/build: timer_test

.PHONY : CMakeFiles/timer_test.dir/build

CMakeFiles/timer_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/timer_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/timer_test.dir/clean

CMakeFiles/timer_test.dir/depend:
	cd /root/workspace/MiniServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/MiniServer /root/workspace/MiniServer /root/workspace/MiniServer/build /root/workspace/MiniServer/build /root/workspace/MiniServer/build/CMakeFiles/timer_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/timer_test.dir/depend

