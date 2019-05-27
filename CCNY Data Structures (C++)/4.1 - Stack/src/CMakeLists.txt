project(hw4a_library)


set(HEADER_FILES hw4q1.h hw4q4.h)

set(SOURCE_FILES hw4q1.cpp hw4q4.cpp)

add_library(hw4a_library ${SOURCE_FILES} ${HEADER_FILES})
