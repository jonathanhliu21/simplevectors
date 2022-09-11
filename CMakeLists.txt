cmake_minimum_required(VERSION 3.9)
project(simplevectors 
    VERSION 0.2.0
    DESCRIPTION "Simple vector implementations in C++"
    LANGUAGES CXX)

include(GNUInstallDirs)

# test options
option(BUILD_TEST "Build tests" OFF)
option(BUILD_EXAMPLE "Build examples" OFF)

# C++ standard
set(CMAKE_CXX_STANDARD 14)

# add headers and sources
set(svector_HEADERS
  include/simplevectors/core/units.hpp 
  include/simplevectors/core/vector.hpp
  include/simplevectors/core/vector2d.hpp
  include/simplevectors/core/vector3d.hpp
  include/simplevectors/vectors.hpp)

# compile
add_library(simplevectors INTERFACE)
set_target_properties(simplevectors PROPERTIES
  VERSION ${PROJECT_VERSION})

target_include_directories(simplevectors INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>)

# install public headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# configure & install CMake package
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/simplevectorsConfig.cmake
    INSTALL_DESTINATION lib/cmake/simplevectors
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/simplevectorsConfigVersion.cmake
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    COMPATIBILITY AnyNewerVersion
    )  
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/simplevectorsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/simplevectorsConfigVersion.cmake
    DESTINATION lib/cmake/simplevectors
    )

# configure pc.in file
configure_file(simplevectors.pc.in simplevectors.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/simplevectors.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# add tests if set
if (BUILD_TEST)
    # don't install gtest when running `make install`
    set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest." FORCE)
    enable_testing()
    add_subdirectory(test)
endif()

# add examples
if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif()
