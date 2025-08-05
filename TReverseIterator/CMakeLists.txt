file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${ritlibrary} STATIC ${srcs} ${hdrs})

target_link_libraries(${ritlibrary} ${strlibrary})
target_link_libraries(${ritlibrary} ${alloclibrary})
target_link_libraries(${ritlibrary} ${arrlibrary})
target_link_libraries(${ritlibrary} ${vectorlibrary})


