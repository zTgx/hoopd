# 3rd
# aux_source_directory(./thirdparty/httpparser HTTPPARSER)
add_subdirectory (thirdparty)

# hoopd 
aux_source_directory(./ HOOPD)

# lib
# add_library(hoopd STATIC ${HOOPD} ${HTTPPARSER})

add_library(hoopd STATIC ${HOOPD} $<TARGET_OBJECTS:thirdparty>)
