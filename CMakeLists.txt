cmake_minimum_required(VERSION 2.8.9)
project(pokepack)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES PokeGen.cpp PokeGen.h PokeGen.m.cpp)

add_executable(pokepack ${SOURCES})

file(GLOB TEST_SOURCES PokeGen.t.cpp PokeGen.cpp PokeGen.h)
add_executable(pokepack.t ${TEST_SOURCES})

target_link_libraries(pokepack.t ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
add_test(NAME pockepack.t COMMAND pokepack.t)
