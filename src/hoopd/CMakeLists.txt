
# hoopd
aux_source_directory(. SRCS)

# dummy 
aux_source_directory(./dummy D_SRC)

# lib
add_library(hoopd STATIC ${SRCS} ${D_SRC})
