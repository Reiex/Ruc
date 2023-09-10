#######################################################################################################################
##! \file
##! \author Marius Pélégrin
##! \copyright The MIT License (MIT)
##! \date 2023
#######################################################################################################################

cmake_minimum_required(VERSION 3.21)

project(Ruc)

set(CMAKE_CXX_STANDARD 23)

set(
    RUC_EXAMPLES_SOURCES
    examples/main.cpp
)

add_executable(RucExamples ${RUC_EXAMPLES_SOURCES})

target_include_directories(RucExamples PUBLIC include)
