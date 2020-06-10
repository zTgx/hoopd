# depend
add_subdirectory(../depend/cpp-httplib httplib)
add_subdirectory(../depend/spdlog spdlog)

# subdirectory
add_subdirectory(dummy)

# executable
aux_source_directory(. SRCS)
add_executable (hoopd ${SRCS})

# link sub lib
target_link_libraries (hoopd dummy)

# link depend lib
target_link_libraries (hoopd httplib)
target_link_libraries (hoopd spdlog)
