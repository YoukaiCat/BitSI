#include "BitSI.h"
#include "IndexData.h"
#include "Utils.h"

BitSI::BitSI() { }

void BitSI::bootstrap(string ip, string port)
{
    node.setOnStatusChanged([this](dht::Dht::Status dhtStatus, dht::Dht::Status unknown) {
        unused(unknown);
        if (dhtStatus == dht::Dht::Status::Connected) {
            status = ConnectionStatus::Connected;
            cout << "DHT Status: connected" << endl;
        } else {
            status = ConnectionStatus::Disconnected;
            cout << "DHT Status: disconnected" << endl;
        }
    });
    node.run(55333, dht::crypto::generateIdentity(), true);
    node.bootstrap(ip.data(), port.data());
}

void BitSI::store(string hash, string title)
{
    IndexData data(hash, title);
    node.put(hash, data, [](bool success) {
        cout << "Data store status: " << (int)success << endl;
    });
}

void BitSI::find(string s)
{
    node.get(s, [](const std::vector<std::shared_ptr<dht::Value>> & vals) {
        for (auto val : vals) {
            auto data = val.get()->unpack<IndexData>();
            cout << "Data found: " << data << endl;
        }
        return true;
    });
}
