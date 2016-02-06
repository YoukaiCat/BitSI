#ifndef BITSI_METAINFO_H
#define BITSI_METAINFO_H

#include <string>
#include <libtorrent/torrent_info.hpp>

using namespace libtorrent;

class MetaInfo
{
public:
    MetaInfo(const std::string & filename);
    const std::string getInfoHash() const;
    const std::string getName() const;
    const std::string getFileName(int fineNum) const;
private:
    torrent_info info;
};

#endif //BITSI_METAINFO_H
