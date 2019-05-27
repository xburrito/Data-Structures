project(hw3_library)


set(HEADER_FILES hw5q1.h hw5q2.h hw5q3.h hw5q4.h hw5q5.h)

set(SOURCE_FILES hw5q1.cpp hw5q2.cpp hw5q3.cpp hw5q4.cpp hw5q5.cpp)

add_library(hw5_library ${SOURCE_FILES} ${HEADER_FILES})
