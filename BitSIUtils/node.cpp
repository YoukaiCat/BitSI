#include <iostream>

#include "BitSI.h"
#include "Utils.h"

using namespace std;

int main(int argc, char * argv[])
{
    unused(argc);
    unused(argv);

    BitSI bitsi;

    cout << "Bootstrapping" << endl;

    bitsi.bootstrap("172.17.0.2", "55333");

    cin.ignore();

    bitsi.store("123", "TEST1");
    bitsi.store("123", "TEST2");

    cin.ignore();

    bitsi.find("123");

    cin.ignore();

    return 0;
}
