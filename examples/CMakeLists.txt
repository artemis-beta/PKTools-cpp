file( GLOB PKTOOLS_EXAMPLE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx )

foreach( EXAMPLE ${PKTOOLS_EXAMPLE_SRCS} )
    get_filename_component( BINARY_NAME ${EXAMPLE} NAME_WLE )
    add_executable( ${BINARY_NAME} ${EXAMPLE} )
    target_link_libraries( ${BINARY_NAME} PUBLIC ${PKTOOLS_LIBRARY} )
    target_include_directories( ${BINARY_NAME} PUBLIC ${PKTOOLS_INCLUDE_DIR} )
endforeach()