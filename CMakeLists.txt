#Author : beautifularea
#Date   : 26/8/2019
#Desc   : web

SET(PROJECTNAME watermelon)
PROJECT(${PROJECTNAME})

CMAKE_MINIMUM_REQUIRED(VERSION 3.15.0)
AUX_SOURCE_DIRECTORY(./src DIR_MAIN_SRCS)
ADD_EXECUTABLE(${PROJECTNAME} ${DIR_MAIN_SRCS})

SET(CMAKE_CXX_STANDARD 17)

#TARGET_LINK_LIBRARIES(${PROJECTNAME} -lpthread)

# include_directories(/usr/local)
link_directories(/usr/local/lib)
target_link_libraries(${PROJECTNAME} libgtest.a)
target_link_libraries(${PROJECTNAME} libgtest_main.a)
target_link_libraries(${PROJECTNAME} -lpthread)
