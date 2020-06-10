SET(CMAKE_CXX_STANDARD 11)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# executable
aux_source_directory(. SRCS)
add_executable (echo ${SRCS})

# link sub lib
LINK_LIBRARIES(../../build/lib/libhoopd.a)

# libhoopd header directory
include_directories(../../src)

target_link_libraries (echo pthread)
