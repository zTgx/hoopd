
SET(INC_DIR "/usr/local/include")
SET(LINK_DIR "/usr/local/lib")

INCLUDE_DIRECTORIES(${INC_DIR})
link_directories(${LINK_DIR})

SET(CMAKE_CXX_STANDARD 17)

add_executable (UnitTest dummy.cc DummyUnitTest.cc)

target_link_libraries (UnitTest Dummy)
target_link_libraries (UnitTest gtest)
target_link_libraries (UnitTest gtest_main)

add_test (NAME UnitTest COMMAND Test)
