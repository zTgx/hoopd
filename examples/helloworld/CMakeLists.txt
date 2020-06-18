PROJECT(helloworld)

# set c++11 standard
SET(CMAKE_CXX_STANDARD 11)

# set cmake 
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 该句必须在add_executable之前, 否则无效
LINK_DIRECTORIES(../../build/lib)

# libhoopd header directory
include_directories(../../src)

# executable
aux_source_directory(. SRCS)
add_executable (helloworld ${SRCS})

# link targets
target_link_libraries (helloworld hoopd)
target_link_libraries (helloworld pthread)
