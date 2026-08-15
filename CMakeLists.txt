cmake_minimum_required(VERSION 3.15)
 
project(eulersTotient
    VERSION 1.0.0
    DESCRIPTION "Euler's Totient Function"
    LANGUAGES CXX
)
 
option(EULERS_BUILD_TESTS "Build GoogleTest unit tests" ON)
 
add_library(eulers_totient STATIC
    src/eulersGcd.cpp
    src/eulersGcdV2.cpp
    src/sieve.cpp
    src/primeFact.cpp
    src/main.cpp
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
 
add_executable(comp src/main.cpp)
 
target_link_libraries(comp PRIVATE eulers_totient)
 
set_target_properties(comp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(EULERS_BUILD_TESTS)
    include(FetchContent)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
 
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.15.2
    )
    FetchContent_MakeAvailable(googletest)
 
    enable_testing()
 
    add_executable(eulers_totient_tests
        test/eulers_gcd_test.cpp
        test/eulers_gcd_v2_test.cpp
        test/sieve_test.cpp
        test/prime_fact_test.cpp
        test/cross_validation_test.cpp
    )
 
    target_link_libraries(eulers_totient_tests PRIVATE
        eulers_totient
        GTest::gtest_main
    )
 
    set_target_properties(eulers_totient_tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
 
    include(GoogleTest)
    gtest_discover_tests(eulers_totient_tests)
endif()