#include "IndexData.h"

IndexData::IndexData() { }

IndexData::IndexData(const string & hash, const string & title)
{
    this->hash = hash;
    this->title = title;
}

IndexData * IndexData::setHash(const std::string & hash)
{
    this->hash = hash;
    return this;
}

const std::string & IndexData::getHash() const
{
    return hash;
}

IndexData * IndexData::setTitle(const std::string & title)
{
    this->title = title;
    return this;
}

const std::string & IndexData::getTitle() const
{
    return title;
}

ostream & operator<<(ostream & os, const IndexData & indexData)
{
    os << "Hash: " << indexData.getHash()
    << "\nTitle: " << indexData.getTitle();
    return os;
}
