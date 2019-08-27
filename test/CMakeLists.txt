
SET(INC_DIR "/usr/local/include")
SET(LINK_DIR "/usr/local/lib")

INCLUDE_DIRECTORIES(${INC_DIR})
link_directories(${LINK_DIR})

SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable (UnitTest dummy.cc DummyUnitTest.cc)

target_link_libraries (UnitTest Dummy)
target_link_libraries (UnitTest gtest)
target_link_libraries (UnitTest gtest_main)

add_test (NAME UnitTest COMMAND UnitTest)
