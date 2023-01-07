cmake_minimum_required(VERSION 3.16.3)  # lowest version that is tested on
project(simplevectors 
    VERSION 0.3.6
    DESCRIPTION "Simple vector implementations in C++"
    LANGUAGES CXX)

include(GNUInstallDirs)

# install options
option(SVECTOR_INSTALL "Install simplevectors during the install step")

# test options
option(SVECTOR_BUILD_TEST "Build simplevector tests" OFF)
option(SVECTOR_BUILD_EXAMPLE "Build simplevector examples" OFF)

# compile
add_library(simplevectors INTERFACE)

# C++ standard
target_compile_features(simplevectors INTERFACE cxx_std_11)

target_include_directories(simplevectors INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/>)

if (SVECTOR_INSTALL)
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
    install(TARGETS simplevectors
        EXPORT simplevectorsTargets
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )
    install(EXPORT simplevectorsTargets
        NAMESPACE simplevectors::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/simplevectors
        )

    # configure pc.in file
    configure_file(simplevectors.pc.in simplevectors.pc @ONLY)
    install(FILES ${CMAKE_BINARY_DIR}/simplevectors.pc
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
endif()

# add tests if set
if (SVECTOR_BUILD_TEST)
    # don't install gtest when running `make install`
    set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest." FORCE)
    enable_testing()
    add_subdirectory(test)
endif()

# add examples
if (SVECTOR_BUILD_EXAMPLE)
    add_subdirectory(example)
endif()
