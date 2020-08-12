cmake_minimum_required(VERSION 3.18)
project(UnixTest LANGUAGES CXX C)

add_executable(hello_world main.c shell_commands.c ../shell/src/shell.c)
SET_SOURCE_FILES_PROPERTIES(shell_commands.c PROPERTIES LANGUAGE CXX )
SET_SOURCE_FILES_PROPERTIES(main.c PROPERTIES LANGUAGE CXX )
SET_SOURCE_FILES_PROPERTIES(../shell/src/shell.c PROPERTIES LANGUAGE CXX )
target_include_directories(hello_world PUBLIC ../shell/include)
target_include_directories(hello_world PUBLIC ../)

target_compile_options(hello_world PUBLIC -fpermissive)
