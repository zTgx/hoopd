aux_source_directory(./httpparser HTTPPARSER)
aux_source_directory(./json JSON)

add_library(thirdparty STATIC 
    ${HTTPPARSER}
    ${JSON}
)
