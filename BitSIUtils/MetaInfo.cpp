#include "MetaInfo.h"

#include <libtorrent/session.hpp>

MetaInfo::MetaInfo(const std::string & filename) : info(torrent_info(filename)) {}

const std::string MetaInfo::getInfoHash() const
{
    return to_hex(info.info_hash().to_string());
}

const std::string MetaInfo::getName() const
{
    return info.name();
}

const std::string MetaInfo::getFileName(int fileNum) const
{
    return info.file_at(fileNum).path;
}
