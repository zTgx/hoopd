cmake_minimum_required(VERSION 3.7.0)
project(seephit)

set(CMAKE_CXX_STANDARD 17)

# Include
include(GNUInstallDirs)
include(ExternalProject)

add_library(${PROJECT_NAME} INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

export(TARGETS ${PROJECT_NAME} FILE httplibConfig.cmake)
