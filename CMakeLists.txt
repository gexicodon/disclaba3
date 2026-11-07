cmake_minimum_required(VERSION 4.3)
project(disclaba3 C)

set(CMAKE_C_STANDARD 23)

add_executable(disclaba3 dzeta.c)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(zeta_calc PRIVATE ${MATH_LIBRARY})
endif()