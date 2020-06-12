# hoopd
aux_source_directory(./impl IMPL)

# lib
add_library(hoopd STATIC ${IMPL})
