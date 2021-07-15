#Author : zTgx [747674262@qq.com]
#Date   : 2020/6/7
#Desc   : Nginx inspired web framework

PROJECT(hoopd)

SET(CMAKE_CXX_STANDARD 11)

CMAKE_MINIMUM_REQUIRED(VERSION 3.17.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-static ${CMAKE_CXX_FLAGS}")

include_directories(./src)

# add_subdirectory (src)
# add_subdirectory (test)

# 3rd
aux_source_directory(./src/thirdparty/httpparser HTTPPARSER)

# hoopd
aux_source_directory(./src IMPL)

# lib
add_library(hoopd STATIC ${IMPL} ${HTTPPARSER})

# test
enable_testing ()
add_test (NAME UnitTest COMMAND UnitTest)
