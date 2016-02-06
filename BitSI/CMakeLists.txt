cmake_minimum_required(VERSION 2.8.11)
project(bitsi)

find_package(PkgConfig)
pkg_check_modules(OPENDHT opendht)

include_directories(include/)

if (ENABLE_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else ()
    set(CMAKE_BUILD_TYPE Release)
endif ()

list(APPEND SOURCES src/BitSI.cpp src/IndexData.cpp)

list(APPEND HEADERS include/BitSI.h include/IndexData.h include/Utils.h)

add_library(bitsi SHARED ${SOURCES} ${HEADERS})

set_target_properties(bitsi PROPERTIES IMPORT_SUFFIX "_import.lib")

add_library(bitsi-static STATIC ${SOURCES} ${HEADERS})

set_target_properties(bitsi-static PROPERTIES OUTPUT_NAME "bitsi")

if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
    set(CMAKE_INSTALL_LIBDIR lib)
endif ()

target_link_libraries(bitsi LINK_PUBLIC opendht)
target_link_libraries(bitsi-static LINK_PUBLIC opendht)

install(TARGETS bitsi bitsi-static DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_PREFIX})
