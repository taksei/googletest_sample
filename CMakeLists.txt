#----------------------------------------------------------
# Set project name (This is used as target lib/exe name)
#----------------------------------------------------------

set(PROJECT_NAME "gtestsample")
cmake_minimum_required(VERSION 3.1)


#----------------------------------------------------------
# Forbit to build in-tree
#----------------------------------------------------------

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Do not build in-tree. Please run cmake in the build directory.")
endif()


#----------------------------------------------------------
# C++ build setting
#----------------------------------------------------------

project(${PROJECT_NAME} C CXX)
set(CMAKE_CXX_STANDARD 11)

option(BUILD_SHARED_LIBS "build as a shared library" OFF)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -Wall")


#----------------------------------------------------------
# Set install paths for dependend libraries
#----------------------------------------------------------

set(GTEST_ROOT "~/local/gtest-1.10.0" CACHE STRING "googletest install directory")


#----------------------------------------------------------
# Build source files
#----------------------------------------------------------

add_subdirectory(src)


#----------------------------------------------------------
# Build test files
#----------------------------------------------------------

if (ENABLE_TEST)
  enable_testing()
  add_subdirectory(test)
endif()

