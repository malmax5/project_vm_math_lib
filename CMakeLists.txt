cmake_minimum_required(VERSION 3.14)
project(pvm_math_lib VERSION 1.0.0 LANGUAGES CXX)

add_library(pvm_math_lib INTERFACE)

target_include_directories(pvm_math_lib INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(pvm_math_lib INTERFACE cxx_std_17)

option(PVM_MATH_BUILD_TESTS "Build unit tests for pvm_math_lib" OFF)

if(PVM_MATH_BUILD_TESTS)
    include(FetchContent)
    
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/heads/main.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    FetchContent_MakeAvailable(googletest)

    add_executable(unit_tests_math 
        tests/test_main.cpp 
        tests/test_math.cpp
    )
    target_link_libraries(unit_tests_math PRIVATE pvm_math_lib gtest_main)
endif()
