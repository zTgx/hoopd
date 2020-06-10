#Author : zTgx [747674262@qq.com]
#Date   : 2020/6/7
#Desc   : a http server

SET(CMAKE_CXX_STANDARD 11)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-static ${CMAKE_CXX_FLAGS}")

add_subdirectory (src)
# add_subdirectory (test)

# test
enable_testing ()
add_test (NAME UnitTest COMMAND UnitTest)
