include_directories(../BitSI/include)

add_executable(node node.cpp)

target_link_libraries(node LINK_PUBLIC bitsi gnutls)
