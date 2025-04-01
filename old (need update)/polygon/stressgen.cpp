#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int t = 100;

    cout << t << endl;

    for (int i = 0; i < t; i++) {
        cout << rnd.next(1, 1'000'000'000) << ' ' << 1000 << endl;
    }

    return 0;
}
