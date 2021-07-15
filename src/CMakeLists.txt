# 3rd
# aux_source_directory(./thirdparty/httpparser HTTPPARSER)
add_subdirectory (thirdparty)

# hoopd 
aux_source_directory(./ HOOPD)

# lib
add_library(hoopd STATIC ${HOOPD})

# 链接 thirdparty 方式一
# add_library(hoopd STATIC ${HOOPD} $<TARGET_OBJECTS:thirdparty>)

# 链接 thirdparty 方式二
target_link_libraries(hoopd thirdparty)
