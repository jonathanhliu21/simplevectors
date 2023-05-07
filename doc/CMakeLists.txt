find_package(Doxygen REQUIRED)
set(DOXYGEN_EXCLUDE_PATTERNS
    "${CMAKE_SOURCE_DIR}/build/*"
    "${CMAKE_SOURCE_DIR}/example/*"
)

set(DOXYGEN_SHORT_NAMES YES)

doxygen_add_docs(doxygen
    ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "-- Building doxygen documentation"
)
