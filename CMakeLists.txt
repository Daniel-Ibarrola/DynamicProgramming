cmake_minimum_required(VERSION 3.24)
project(dynamicprogramming)

set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})


# defines targets and sources
add_subdirectory(src)

# enable testing and define tests
enable_testing()
add_subdirectory(tests)
