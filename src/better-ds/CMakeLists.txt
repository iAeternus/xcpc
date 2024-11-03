cmake_minimum_required(VERSION 3.10)
project(better-ds VERSION 1.0 LANGUAGES CXX DESCRIPTION "Better Data Structure for XCPC")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

aux_source_directory("${CMAKE_SOURCE_DIR}/src" SOURCES)
aux_source_directory("${CMAKE_SOURCE_DIR}/src/core" CORE_SOURCES)
aux_source_directory("${CMAKE_SOURCE_DIR}/src/common" COMMON_SOURCES)
include_directories("${CMAKE_SOURCE_DIR}/include/core"
                    "${CMAKE_SOURCE_DIR}/include/common")

message(STATUS "SOURCES: ${SOURCES}")

add_executable(better-ds ${SOURCES}
                            ${CORE_SOURCES}
                            ${COMMON_SOURCES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -pedantic)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif()

add_subdirectory(tests)
enable_testing()