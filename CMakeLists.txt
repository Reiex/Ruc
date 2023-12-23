#######################################################################################################################
##! \file
##! \author Pélégrin Marius
##! \copyright The MIT License (MIT)
##! \date 2023
#######################################################################################################################

cmake_minimum_required(VERSION 3.21)

project(Ruc)

set(CMAKE_CXX_STANDARD 23)

add_executable(
    ruc-examples
    ${CMAKE_CURRENT_LIST_DIR}/examples/main.cpp
)

target_include_directories(ruc-examples PUBLIC include)
