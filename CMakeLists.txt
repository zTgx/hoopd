#Author : beautifularea
#Date   : 26/8/2019
#Desc   : web

SET(PROJECTNAME watermelon)
PROJECT(${PROJECTNAME})

CMAKE_MINIMUM_REQUIRED(VERSION 3.15.0)

add_subdirectory (src)
add_subdirectory (test)

# ADD_EXECUTABLE(${PROJECTNAME} ${DIR_MAIN_SRCS})

SET(CMAKE_CXX_STANDARD 17)

enable_testing ()
add_test (NAME UnitTest COMMAND UnitTest)
