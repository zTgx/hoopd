add_subdirectory(../depend/cpp-httplib httplib)

add_library (Dummy dummy.h dummy.cc)
add_executable (wtm main.cc)
target_link_libraries (wtm Dummy)
target_link_libraries (wtm httplib)
