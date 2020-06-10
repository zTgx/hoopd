
# subdirectory
# add_subdirectory(dummy)

# hoopd
aux_source_directory(. SRCS)
add_library(hoopd ${SRCS})

# link sub lib
# target_link_libraries (hoopd dummy)
