cmake_minimum_required (VERSION 3.21)
project ("Newton"
    VERSION 1.0.0
    DESCRIPTION "A header only c++ math library"
    LANGUAGES C CXX)

add_subdirectory(include)
add_subdirectory(tests)