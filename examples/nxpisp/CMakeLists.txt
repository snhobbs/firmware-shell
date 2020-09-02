cmake_minimum_required(VERSION 3.18)
project(nxpisp LANGUAGES CXX C)

set(PROJECT_SOURCE ../../shell/src)
set(PROJECT_INCLUDE ../../shell/include)
add_executable(nxpisp main.c shell_commands.c ${PROJECT_SOURCE}/shell.c)
SET_SOURCE_FILES_PROPERTIES(shell_commands.c PROPERTIES LANGUAGE CXX )
SET_SOURCE_FILES_PROPERTIES(main.c PROPERTIES LANGUAGE CXX )
SET_SOURCE_FILES_PROPERTIES(${PROJECT_SOURCE}/shell.c PROPERTIES LANGUAGE CXX )
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE})
target_include_directories(${PROJECT_NAME} PUBLIC ../)

target_compile_options(${PROJECT_NAME} PUBLIC -fpermissive)
