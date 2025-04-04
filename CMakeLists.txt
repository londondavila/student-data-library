# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StudentDataLibrary VERSION 1.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -g -fsanitize=address")

# Enable clang-tidy
# set(CMAKE_CXX_CLANG_TIDY "/opt/homebrew/opt/llvm/bin/clang-tidy;--checks=*")

# Define source directory
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(HEADER_DIRS "${CMAKE_SOURCE_DIR}/include")
set(TEST_DIRS "${CMAKE_SOURCE_DIR}/tests")

# Collect source files
set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/student.cpp
    ${SRC_DIR}/softwareStudent.cpp
    ${SRC_DIR}/securityStudent.cpp
    ${SRC_DIR}/networkStudent.cpp
)

set(HEADERS
    ${HEADER_DIRS}/student.h
    ${HEADER_DIRS}/roster.h
    ${HEADER_DIRS}/softwareStudent.h
    ${HEADER_DIRS}/securityStudent.h
    ${HEADER_DIRS}/networkStudent.h
)

# Create the static library
add_library(StudentLibrary STATIC ${SOURCES} ${HEADERS})

# Define the main executable
add_executable(StudentDataLibrary ${SRC_DIR}/main.cpp)

# Link the library to the executable
target_link_libraries(StudentDataLibrary PRIVATE StudentLibrary)

# Include the directory for headers
target_include_directories(StudentLibrary PUBLIC ${HEADER_DIRS})

# <--- TESTS --->
enable_testing()

# Setup Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  test_roster
  ${TEST_DIRS}/roster_functions_test.cpp
)
target_link_libraries(
  test_roster
  GTest::gtest_main
  StudentLibrary
)

# Include the directory for headers for tests
target_include_directories(test_roster PUBLIC ${HEADER_DIRS})

include(GoogleTest)
gtest_discover_tests(test_roster)
