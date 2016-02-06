#ifndef BITSI_INDEXDATA_H
#define BITSI_INDEXDATA_H

#include <msgpack.hpp>
#include <iostream>

using namespace std;

class IndexData
{
public:
    IndexData();

    IndexData(const string & hash, const string & title);

    IndexData * setHash(const string & hash);

    const string & getHash() const;

    IndexData * setTitle(const string & title);

    const string & getTitle() const;

    friend ostream & operator<<(ostream & os, const IndexData & indexData);

private:
    string hash;
    string title;

public:
    MSGPACK_DEFINE (hash, title)
};

#endif //BITSI_INDEXDATA_H
