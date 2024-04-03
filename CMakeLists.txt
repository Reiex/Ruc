#######################################################################################################################
##! \file
##! \author Pélégrin Marius
##! \copyright The MIT License (MIT)
##! \date 2023-2024
#######################################################################################################################

# Global project definitions

cmake_minimum_required(VERSION 3.21)

project(Ruc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Ruc

add_custom_target(
    ruc SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Ruc.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/RucDecl.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/RucTypes.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Core/Core.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Core/CoreDecl.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Core/CoreTypes.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Core/Macro.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Core/Status.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Ruc/Core/templates/Status.hpp
)

# Ruc examples

option(RUC_BUILD_EXAMPLES "Add target ruc-examples" ON)

if(RUC_BUILD_EXAMPLES)

    add_executable(
        ruc-examples
        ${CMAKE_CURRENT_LIST_DIR}/examples/main.cpp
    )

    add_dependencies(
        ruc-examples
        ruc
    )

    target_include_directories(
        ruc-examples
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
    )

endif()
