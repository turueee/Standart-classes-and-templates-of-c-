file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${alloclibrary} STATIC ${srcs} ${hdrs})

target_link_libraries(${alloclibrary} ${strlibrary})
target_link_libraries(${alloclibrary} ${arrlibrary})
target_link_libraries(${alloclibrary} ${ritlibrary})
target_link_libraries(${alloclibrary} ${vectorlibrary})

