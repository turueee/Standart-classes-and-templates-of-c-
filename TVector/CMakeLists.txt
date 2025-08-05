file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${vectorlibrary} STATIC ${srcs} ${hdrs})

target_link_libraries(${vectorlibrary} ${ritlibrary})
target_link_libraries(${vectorlibrary} ${alloclibrary})
target_link_libraries(${vectorlibrary} ${arrlibrary})
target_link_libraries(${vectorlibrary} ${strlibrary})


