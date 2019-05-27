project(hw6_library)


set(HEADER_FILES hw6q1.h hw6q2.h node.h)

set(SOURCE_FILES hw6q1.cpp hw6q2.cpp node.cpp)

add_library(hw6_library ${SOURCE_FILES} ${HEADER_FILES})
