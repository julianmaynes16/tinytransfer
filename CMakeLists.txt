cmake_minimum_required(VERSION 3.22)
cmake_policy(VERSION 3.22)

message(STATUS "Building tinytransfer")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(tinytransfer)

set(PYBIND11_FINDPYTHON ON)
# Add pybind11 subdirectory
add_subdirectory(pybind11)

# Find Python and its development components
find_package(Python COMPONENTS Interpreter Development REQUIRED)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

add_library(heatshrink ${CMAKE_CURRENT_SOURCE_DIR}/cpp/heatshrink/heatshrink_encoder.c ${CMAKE_CURRENT_SOURCE_DIR}/cpp/heatshrink/heatshrink_decoder.c)
add_library(tinytransfer ${CMAKE_CURRENT_SOURCE_DIR}/cpp/tinytransfer.cpp)

target_include_directories(heatshrink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cpp/heatshrink)
target_include_directories(tinytransfer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cpp)

target_compile_options(heatshrink PRIVATE -Wno-unknown-pragmas)

target_link_libraries(tinytransfer heatshrink)

pybind11_add_module(pytinytransfer python/wrapper.cpp)