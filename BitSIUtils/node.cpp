#include <iostream>

#include "BitSI.h"
#include "MetaInfo.h"
using namespace std;

int main(int argc, char * argv[])
{
    BitSI bitsi;

    if (argc != 4)
    {
        cout << "usage: node bootstrap_ip bootstrap_port torrent_filename" << endl;
        return 1;
    }

    MetaInfo info(argv[3]);

    cout << "Bootstrapping" << endl;

    bitsi.bootstrap(argv[1], argv[2]);

    cin.ignore();

    bitsi.store(info.getInfoHash(), info.getName());

    cin.ignore();

    bitsi.find(info.getInfoHash());

    cin.ignore();

    return 0;
}
