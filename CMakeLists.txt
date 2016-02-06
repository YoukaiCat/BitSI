cmake_minimum_required (VERSION 2.8.11)
project(bitsi)

set(BITSI_MAJOR_VERSION 0)
set(BITSI_MINOR_VERSION 1)
set(BITSI_PATCH_VERSION 0)
set(BITSI_VERSION ${FOOBAR_MAJOR_VERSION}.${FOOBAR_MINOR_VERSION}.${FOOBAR_PATCH_VERSION})

set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix "\${prefix}")
set(libdir "\${exec_prefix}/lib")
set(includedir "\${prefix}/include")

option(BUILD_UTILS "Build console client" ON)
option(ENABLE_DEBUG "Build with debug flags" ON)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic ${CMAKE_CXX_FLAGS}")

add_subdirectory(BitSI)

if (BUILD_UTILS)
    add_subdirectory(BitSIUtils)
endif ()
