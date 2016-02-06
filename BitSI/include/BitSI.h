#ifndef BITSI_H
#define BITSI_H

#include <opendht/dhtrunner.h>

using namespace std;

enum ConnectionStatus
{
    Disconnected,
    Connected
};

class BitSI
{
public:
    BitSI();

    void bootstrap(string ip, string port);

    void store(string hash, string data);

    void find(string hash);

private:
    dht::DhtRunner node;
    ConnectionStatus status;
};

#endif // BITSI_H
