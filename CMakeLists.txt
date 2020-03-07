cmake_minimum_required(VERSION 2.8.9)
project(pokepack)
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

enable_testing()

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES PokeGen.cpp PokeGen.h PokeGen.m.cpp)
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

add_executable(pokepack ${SOURCES})

file(GLOB TEST_SOURCES PokeGen.t.cpp PokeGen.cpp PokeGen.h)
add_executable(pokepack.t ${TEST_SOURCES})

target_link_libraries(pokepack.t gtest_main)
add_test(NAME pockepack.t COMMAND pokepack.t)
