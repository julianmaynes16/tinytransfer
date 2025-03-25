

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(PYBIND11_FINDPYTHON ON)

# Find Python and its development components
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Add pybind11 subdirectory


# Add heatshrink library
add_library(heatshrink 
    ${CMAKE_CURRENT_SOURCE_DIR}/heatshrink/heatshrink_encoder.c ${CMAKE_CURRENT_SOURCE_DIR}/heatshrink/heatshrink_decoder.c)
target_include_directories(heatshrink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/heatshrink)

# Add tinytransfer library
add_library(tinytransfer ${CMAKE_CURRENT_SOURCE_DIR}/tinytransfer.cpp)
target_include_directories(tinytransfer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link heatshrink and pybind11 to tinytransfer
target_link_libraries(tinytransfer PUBLIC heatshrink pybind11::module)

# Create the Python module
pybind11_add_module(_C tinytransfer.cpp)
target_link_libraries(_C PRIVATE tinytransfer)