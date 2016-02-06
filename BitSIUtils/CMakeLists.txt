include_directories(../BitSI/include)

add_executable(node node.cpp MetaInfo.cpp MetaInfo.h)

target_link_libraries(node LINK_PUBLIC bitsi gnutls torrent-rasterbar boost_system)
