# Build Configuration
## Folder Structure
We will start from a basic example where we only have an empty `Matrix` class and a test which use it.

Basic folder structure:
├── CMakeLists.txt
├── include
│   ├── newton
│   │   └── matrix.h
│   ├── CMakeLists.txt
│   └── newton.h
│   
└── test
    ├── CMakeLists.txt
    └── test1.cpp

We have a main `CMakeLists.txt` file in the root of the project, which links to each subsirectory.

```cmake
# /CMakeLists.txt
cmake_minimum_required (VERSION 3.21)
project ("Newton"
    VERSION 1.0.0
    DESCRIPTION "A header only c++ math library"
    LANGUAGES C CXX)

add_subdirectory(include)
add_subdirectory(tests)
```

In the include folder we have a cmake configuration to build the header-only library:

```cmake
# /include/CMakeLists.txt
include(GNUInstallDirs)
add_library(${PROJECT_NAME} INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

# Adding the install interface generator expression makes sure that the include
# files are installed to the proper location (provided by GNUInstallDirs)
target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

```

In the `tests` directory we have a cmake configuration which will use the library that we have
just created.

```cmake
# /tests/CMakeLists.txt
add_executable (test1 test1.cpp)
set_property(TARGET test1 PROPERTY CXX_STANDARD 17)
target_include_directories(test1 PRIVATE ${PROJECT_SOURCE_DIR}/include)
```


# Build Configuration
https://ryandeangraham.medium.com/building-a-header-only-library-hello-world-f9dd05ac1066
- I've used CMake


# References
- https://github.com/CppCon/CppCon2019/blob/master/Presentations/back_to_basics_move_semantics_part_1/back_to_basics_move_semantics_part_1__klaus_iglberger__cppcon_2019.pdf
- https://github.com/CppCon/CppCon2019/blob/master/Presentations/back_to_basics_move_semantics_part_2/back_to_basics_move_semantics_part_2__klaus_iglberger__cppcon_2019.pdf