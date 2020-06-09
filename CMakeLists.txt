#Author : zTgx [747674262@qq.com]
#Date   : 2020/6/7
#Desc   : a http server

SET(PROJECTNAME hoopd)
PROJECT(${PROJECTNAME})

CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)

add_subdirectory (src)
# add_subdirectory (test)

# ADD_EXECUTABLE(${PROJECTNAME} ${DIR_MAIN_SRCS})

SET(CMAKE_CXX_STANDARD 17)

enable_testing ()
add_test (NAME UnitTest COMMAND UnitTest)
