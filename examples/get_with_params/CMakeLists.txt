SET(GetWithParams params)

PROJECT(${GetWithParams})

# set c++11 standard
SET(CMAKE_CXX_STANDARD 11)

# set cmake 
CMAKE_MINIMUM_REQUIRED(VERSION 3.17.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

LINK_DIRECTORIES(../../build/lib)

# libhoopd header directory
include_directories(../../src)

# executable
aux_source_directory(. SRCS)
add_executable (${GetWithParams} ${SRCS})

# link targets
target_link_libraries (${GetWithParams} hoopd)
target_link_libraries (${GetWithParams} pthread)
