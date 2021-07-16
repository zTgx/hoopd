
SET(INC_DIR "/usr/include")
SET(LINK_DIR "/usr/local/lib")

INCLUDE_DIRECTORIES(${INC_DIR})
link_directories(${LINK_DIR})

SET(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable (HelloworldTest helloworld.cc)
# add_executable (RequestTest request.cc)

target_link_libraries (HelloworldTest gtest)
target_link_libraries (HelloworldTest gtest_main)

add_test (NAME HelloworldTest COMMAND HelloworldTest)
