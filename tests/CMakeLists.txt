cmake_minimum_required(VERSION 3.12)
add_executable (test1 test1.cpp)
set_property(TARGET test1 PROPERTY CXX_STANDARD 17)
target_include_directories(test1 PRIVATE ${PROJECT_SOURCE_DIR}/include)
