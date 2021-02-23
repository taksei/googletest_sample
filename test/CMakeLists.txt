#----------------------------------------------------------
# Set include and link paths
#----------------------------------------------------------

# Include path for DUT's public headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Include path for DUT's private headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Link path for DUT lib (build/src/lib${PROJECT_NAME}.a)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/../src)

# Include path for googletest
include_directories(${GTEST_ROOT}/include)

# Link path for googletest
link_directories(${GTEST_ROOT}/lib)


#----------------------------------------------------------
# Set test files
#----------------------------------------------------------

add_executable(test_sample test_sample.cpp)
target_link_libraries(test_sample ${PROJECT_NAME} gtest gtest_main pthread)
add_test(NAME test_sample COMMAND test_sample)

