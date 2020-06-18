#3rd
aux_source_directory(./3rd/httpparser HTTPPARSER)

# hoopd
aux_source_directory(./impl IMPL)

# lib
add_library(hoopd STATIC ${IMPL} ${HTTPPARSER})
