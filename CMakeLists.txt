cmake_minimum_required(VERSION 3.14)
project(pvm_math_lib VERSION 1.0.0 LANGUAGES CXX)

add_library(pvm_math_lib INTERFACE)

target_include_directories(pvm_math_lib INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(pvm_math_lib INTERFACE cxx_std_17)
