cmake_minimum_required( VERSION 3.21 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED TRUE )

set( PKTOOLS_LIBRARY pktools )

project( ${PKTOOLS_LIBRARY} VERSION 0.1.0 LANGUAGES CXX )

option( PKTOOLS_BUILD_EXAMPLES "Build Examples" OFF )

file( GLOB PKTOOLS_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx )

set( CONAN_DISABLE_CHECK_COMPILER ON )
set( PKTOOLS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include )
include( ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake )
conan_basic_setup()

add_library( ${PKTOOLS_LIBRARY} ${PKTOOLS_SRC_FILES} )
add_compile_options( -fconcepts-ts )
target_include_directories( ${PKTOOLS_LIBRARY} PUBLIC ${PKTOOLS_INCLUDE_DIR} )

if( PKTOOLS_BUILD_EXAMPLES )
    add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/examples )
endif()