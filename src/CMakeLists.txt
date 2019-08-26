add_library (Dummy dummy.h dummy.cc)
add_executable (wtm main.cc)
target_link_libraries (wtm Dummy)
