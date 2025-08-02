file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${arrlibrary} STATIC ${srcs} ${hdrs})


