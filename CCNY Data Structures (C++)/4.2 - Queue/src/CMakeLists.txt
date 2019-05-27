project(hw4b_library)


set(HEADER_FILES hw4q2.h hw4q5.h)

set(SOURCE_FILES hw4q2.cpp hw4q5.cpp)

add_library(hw4b_library ${SOURCE_FILES} ${HEADER_FILES})
