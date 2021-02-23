#----------------------------------------------------------
# Select all source files in ./src
#----------------------------------------------------------

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} sources)
list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")


#----------------------------------------------------------
# Build exe
#----------------------------------------------------------

# Build target
add_executable(target_exe ${sources} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Set exe name, instead of target name
set_target_properties(target_exe PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Set include path
target_include_directories(target_exe
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)


#----------------------------------------------------------
# Build lib as shared or static library
#----------------------------------------------------------

# Build target
if (BUILD_SHARED_LIBS)
  add_library(target_lib SHARED ${sources})
else()
  add_library(target_lib STATIC ${sources})
endif()

# Set lib name, instead of target name
set_target_properties(target_lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Set include path
target_include_directories(target_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)


#----------------------------------------------------------
# Install into ${CMAKE_INSTALL_PREFIX}
#----------------------------------------------------------

install(TARGETS target_lib DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/${PROJECT_NAME} DESTINATION include)
