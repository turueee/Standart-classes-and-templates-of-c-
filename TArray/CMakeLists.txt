file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${arrlibrary} STATIC ${srcs} ${hdrs})

target_link_libraries(${arrlibrary} ${strlibrary})
target_link_libraries(${arrlibrary} ${alloclibrary})
target_link_libraries(${arrlibrary} ${ritlibrary})
target_link_libraries(${arrlibrary} ${vectorlibrary})


