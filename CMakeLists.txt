cmake_minimum_required(VERSION 4.3)
project(disclaba3 C)

set(CMAKE_C_STANDARD 23)


add_executable(dzeta dzeta.c)


add_executable(sieve sieve.c)


add_custom_target(disclaba3 DEPENDS dzeta sieve)


find_library(MATH_LIBRARY m)

if(MATH_LIBRARY)
    target_link_libraries(dzeta PRIVATE ${MATH_LIBRARY})
    target_link_libraries(sieve PRIVATE ${MATH_LIBRARY})
endif()