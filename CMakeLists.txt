cmake_minimum_required(VERSION 3.15)

project(eulersTotient
    VERSION 1.0.0
    DESCRIPTION "Euler's Totient Function"
    LANGUAGES CXX
)

add_library(eulers_totient STATIC
    src/eulersGcd.cpp
    src/eulersGcdV2.cpp
    src/sieve.cpp
)

target_include_directories(eulers_totient PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_compile_features(eulers_totient PUBLIC cxx_std_11)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(eulers_totient PRIVATE
        -fno-exceptions
        $<$<CONFIG:Release>:-O2>
    )
endif()

set_target_properties(eulers_totient PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

add_executable(comp app/comp.cpp)

target_link_libraries(comp PRIVATE eulers_totient)

set_target_properties(comp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
