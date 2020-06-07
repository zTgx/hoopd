add_subdirectory(../depend/cpp-httplib httplib)
add_subdirectory(../depend/spdlog spdlog)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library (Dummy dummy.h dummy.cc)
add_executable (hoopserver main.cc)

target_link_libraries (hoopserver Dummy)
target_link_libraries (hoopserver httplib)
target_link_libraries (hoopserver spdlog)
