file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${alloclibrary} STATIC ${srcs} ${hdrs})


