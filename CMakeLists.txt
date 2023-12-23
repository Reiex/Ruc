#######################################################################################################################
##! \file
##! \author Pélégrin Marius
##! \copyright The MIT License (MIT)
##! \date 2023
#######################################################################################################################

# Global project definitions

cmake_minimum_required(VERSION 3.21)

project(Ruc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

option(RUC_LIBRARY_ONLY "Build only the library")

# Ruc examples

if(NOT RUC_LIBRARY_ONLY)

    add_executable(
        ruc-examples
        ${CMAKE_CURRENT_LIST_DIR}/examples/main.cpp
    )

    target_include_directories(
        ruc-examples
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
    )

endif()
