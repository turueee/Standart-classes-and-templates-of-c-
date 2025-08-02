file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${strlibrary} STATIC ${srcs} ${hdrs})


