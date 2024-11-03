cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_TEST_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/tests/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_TEST_BINARY_DIR})

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" TEST_SOURCES)
aux_source_directory("${CMAKE_SOURCE_DIR}/src/core" CORE_SOURCES)
aux_source_directory("${CMAKE_SOURCE_DIR}/src/common" COMMON_SOURCES)
include_directories("${CMAKE_SOURCE_DIR}/include/core"
                    "${CMAKE_SOURCE_DIR}/include/common")

message(STATUS "TEST_SOURCES: ${TEST_SOURCES}")

add_executable(better-ds-tests ${TEST_SOURCES} 
                                ${CORE_SOURCES}
                                ${COMMON_SOURCES})

add_test(NAME better-ds-tests COMMAND $<TARGET_FILE:better-ds-tests>)
